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
volatile bool banderaS =false;
volatile bool banderaH = false;
volatile char cont=0;

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
                LCD_PrintString("S    ");
                banderaS=true; 
                break;
            }
            case 'h':{   
                LCD_Position(0,0);
                LCD_PrintString("H     ");
                banderaH=true; 
                break;
            }
            case 'i':{
                LCD_Position(0,0);
            
            }
            default:
            {
                if (banderaS==true){
                    char dimmer=((255*dato)/100);
                    LCD_Position(0,2);
                    LCD_PrintNumber(dato);
                    PWM_WriteCompare2(dimmer);
                    banderaS=false;
                }
                if (banderaH==true){
                    char dimmer=((255*dato)/100);
                    LCD_Position(0,2);
                    LCD_PrintNumber(dato);
                    PWM_WriteCompare1(dimmer);
                    banderaH=false;
                }
                break;
            }
    }
    }else{
        if(dato=='*'){
            LCD_Position(0,0);
            LCD_PrintString("Conect");
            bandera=true;
        }    
    }
}


void reloj(){
        LCD_PrintNumber(0x01&(ds.hour>>4));
        LCD_PrintNumber((0b00001111)&ds.hour);
        LCD_PutChar(':');
        LCD_PrintNumber(ds.min>>4);
        LCD_PrintNumber((0b00001111)&ds.min);
        LCD_PutChar(':');       
        LCD_PrintNumber(ds.sec>>4);
        LCD_PrintNumber((0b00001111)&ds.sec);
}

int main(void)
{
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    IRQRX_StartEx(InterrupRx);
    UART_Start();
    LCD_Start();
    I2C_Start();
    PWM_Start();
    ds.hour = 0b00010001;
    ds.min =  0x51;
    ds.sec =  0x00; //  11:05:30 am
    ds.date = 0x12; 
    ds.month = 0x10;
    ds.year = 0x18; //12 octubre 2018
    ds.weekDay = 5; // Friday: 5th day of week considering monday as first day.;
    //DS_init();//Configura 
    //DS_set_data();  
    PINA_Write(0);
    PINB_Write(0);
    PINC_Write(0);
    PIND_Write(0);
    PWM_WriteCompare2(0); 
    for(;;)
    {       
        DS_get_data();     
        LCD_Position(1,4);
        reloj();
        CyDelay(500);
    }
}