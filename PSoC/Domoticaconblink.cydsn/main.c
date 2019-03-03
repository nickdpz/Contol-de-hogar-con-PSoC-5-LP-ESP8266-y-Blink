/* ========================================
 * 
 *
 * ========================================
*/
#include "project.h"
#include <stdio.h>
#include <stdbool.h>

#define DS1307_dir 0x68         
#define ds1307_dir_memory 0x00
#define direccion_de_registro_control 0x07
#define registro_control 0b10010001


volatile bool bandera = false;
volatile bool banderaM = false;
volatile bool banderaI = false;
volatile bool banderaF = false;
volatile bool banderaS = false;
volatile bool banderaH = false;
volatile bool cont=false;
volatile uint16 temp2=0;
typedef union
{struct{
  uint8_t sec;
  uint8_t min;
  uint8_t hour;
  uint8_t weekDay;
  uint8_t date;
  uint8_t month;
  uint8_t year;  
};
uint8_t datos[8];
}rtc_t;

rtc_t ds;

rtc_t wHoraInicio;

rtc_t wHoraFin;

uint16 aux[2]={0,0};

void DS_begintx (void){
        do{
                //Espera mienstras el esclavo le responde
        }while(I2C_MasterSendStart(DS1307_dir, I2C_WRITE_XFER_MODE)!=I2C_MSTR_NO_ERROR);
}

void DS_init(void){
    DS_begintx();
    I2C_MasterWriteByte(direccion_de_registro_control);  
    I2C_MasterWriteByte(registro_control);
    I2C_MasterSendStop();
}

void DS_set_data(){
    uint8 i; 
    
    for(i=0;i<=7;i++){
        DS_begintx();
        I2C_MasterWriteByte(i);     // Escribe la posicion 
        I2C_MasterWriteByte(ds.datos[i]);            // Escribe el dato correspondiente
        I2C_MasterSendStop();
    }
}

void DS_get_data(){        
        uint8 i;
    
    for(i=0;i<=7;i++){
        DS_begintx();
        I2C_MasterWriteByte(i);//Pone direccion de memoria que quiere leer 
        I2C_MasterSendRestart(DS1307_dir, I2C_READ_XFER_MODE); // Re transmite para obtener datos
        ds.datos[i]=I2C_MasterReadByte(I2C_NAK_DATA);
        I2C_MasterSendStop();
    }
    
}

CY_ISR(InterrupRx){
    char dato;
    dato=UART_GetChar();//recibe el dato del bluetooth
    if(bandera==true){
        switch (dato){
            case 'w':{
                PINA_Write(~PINA_Read());            
                break;
            }
            case 'x':{ 
                PINB_Write(~PINB_Read());
                break;
            }
            case 'y':{
                PINC_Write(~PINC_Read());            
                break;
            }
            case 'z':{
                PIND_Write(~PIND_Read());
                break;
            }
            case 's':{
                LCD_Position(0,0);
                LCD_PrintString("Hall    %");
                banderaS=true; 
                break;
            }
            case 'h':{   
                LCD_Position(0,0);
                LCD_PrintString("Room    %");
                banderaH=true; 
                break;
            }
            case 'i':{
                LCD_Position(0,0);
                LCD_PrintString("ON        ");
                banderaI=true;
                break;
            }
            case 'f':{
                LCD_Position(0,0);
                LCD_PrintString("OFF       ");
                banderaF=true;
                break;
            }
            case 'm':{
                LCD_Position(0,0);
                LCD_PrintString("Select:     ");
                banderaM=true;
                break;
            }
            default:
            {
                if (banderaS==true){
                    char dimmer=((255*dato)/100);
                    LCD_Position(0,6);
                    LCD_PrintNumber(dato);
                    PWM_WriteCompare2(dimmer);
                    banderaS=false;
                }
                if (banderaH==true){
                    char dimmer=((255*dato)/100);
                    LCD_Position(0,6);
                    LCD_PrintNumber(dato);
                    PWM_WriteCompare1(dimmer);
                    banderaH=false;
                }
                if (banderaI==true){
                    if(cont==true){
                        if(dato>9){
                            LCD_PrintNumber(dato);
                        }else{
                            LCD_PrintNumber(0);
                            LCD_PrintNumber(dato);
                        }
                        banderaI=false;
                        cont=false;
                    }else{
                        LCD_Position(0,5);
                        LCD_PrintNumber(dato);
                        LCD_PutChar(':');
                        cont=true;
                    }
                    
                }
                if (banderaF==true){
                    if(cont==true){
                        if(dato>9){
                            LCD_PrintNumber(dato);
                        }else{
                            LCD_PrintNumber(0);
                            LCD_PrintNumber(dato);
                        }
                        banderaI=false;
                        cont=false;
                    }else{
                        LCD_Position(0,5);
                        LCD_PrintNumber(dato);
                        LCD_PutChar(':');
                        cont=true;
                    }
                }
                if (banderaM==true){
                    LCD_Position(0,8);
                    LCD_PrintNumber(dato);// muestra item
                    banderaM=false;
                }
                break;
            }
    }
    }else{
        if(dato=='*'){
            LCD_Position(0,0);
            LCD_PrintString("Conect");//Se detecta la ultima linea del inicio
            bandera=true;
        }    
    }
}

void reloj(){
        DS_get_data();     
        LCD_Position(1,4);
        LCD_PrintNumber(0x01&(ds.hour>>4));
        LCD_PrintNumber((0b00001111)&ds.hour);
        LCD_PutChar(':');
        LCD_PrintNumber(ds.min>>4);
        LCD_PrintNumber((0b00001111)&ds.min);
        LCD_PutChar(':');       
        LCD_PrintNumber(ds.sec>>4);
        LCD_PrintNumber((0b00001111)&ds.sec);
}

void muestreo(){
    //Temperatura
    uint16 temp=0;
    char warning[3]={};
    aux[0]=aux[1];//Actualiza dato pasado
    ADC_StartConvert();
    ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
    temp=ADC_GetResult16();
    aux[1]=ADC_CountsTo_mVolts(temp);
    if((2500>aux[0])&&(aux[1]>=2500)){//Nueva medida es mayor a 2500 y la anterior era menor 2500 ->50°
        temp2++;//Aumenta el numero de alertas
        LCD_Position(0,0);
        LCD_PrintString("Warning T #");
        LCD_PrintNumber(temp2);
        sprintf(warning,"t%d",temp2);
        UART_PutString(warning);        
    }
    temp=EEPROM_ReadByte(0);//Actualiza aca ya que en la interupcion no se puede
    if(temp2!=temp){
        if(temp2>temp){
            EEPROM_WriteByte(temp2,0);
        }else{
            temp2=temp;
        }    
    }
    
}


CY_ISR(InterrupISR){
        char warning[3]={};
        temp2++;//Aumenta el numero de alertas
        LCD_Position(0,0);
        LCD_PrintString("Warning M #");
        LCD_PrintNumber(temp2);
        sprintf(warning,"m%d",temp2);
        PINMOV_ClearInterrupt();
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    IRQRX_StartEx(InterrupRx);
    ISR_MOV_StartEx(InterrupISR);
    UART_Start();
    LCD_Start();
    I2C_Start();
    PWM_Start();
    ADC_Start();
    /*
    ds.sec =  0x00; //  
    ds.min =  0x37;//
    ds.hour = 0b000010110;//Formato 24 horas bit 6 en 1 - 16 horas
    ds.date = 0x02; // dia 2
    ds.month = 0x03;//marzo
    ds.year = 0x19; // 2019
    ds.weekDay = 6; // Saturday: 5th day of week considering monday as first day.;
    DS_init();//Configura 
    DS_set_data();  */
    PINA_Write(0);
    PINB_Write(0);
    PINC_Write(0);
    PIND_Write(0);
    PWM_WriteCompare1(0);
    PWM_WriteCompare2(0); 
    EEPROM_Start();
    EEPROM_WriteByte(0,0);
    
    for(;;)
    {       
        reloj();
        muestreo();
        CyDelay(500);
                
    }
}