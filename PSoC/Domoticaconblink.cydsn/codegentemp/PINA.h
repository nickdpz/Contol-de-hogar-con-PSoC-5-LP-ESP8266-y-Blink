/*******************************************************************************
* File Name: PINA.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_PINA_H) /* Pins PINA_H */
#define CY_PINS_PINA_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PINA_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PINA__PORT == 15 && ((PINA__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    PINA_Write(uint8 value);
void    PINA_SetDriveMode(uint8 mode);
uint8   PINA_ReadDataReg(void);
uint8   PINA_Read(void);
void    PINA_SetInterruptMode(uint16 position, uint16 mode);
uint8   PINA_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the PINA_SetDriveMode() function.
     *  @{
     */
        #define PINA_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define PINA_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define PINA_DM_RES_UP          PIN_DM_RES_UP
        #define PINA_DM_RES_DWN         PIN_DM_RES_DWN
        #define PINA_DM_OD_LO           PIN_DM_OD_LO
        #define PINA_DM_OD_HI           PIN_DM_OD_HI
        #define PINA_DM_STRONG          PIN_DM_STRONG
        #define PINA_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define PINA_MASK               PINA__MASK
#define PINA_SHIFT              PINA__SHIFT
#define PINA_WIDTH              1u

/* Interrupt constants */
#if defined(PINA__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PINA_SetInterruptMode() function.
     *  @{
     */
        #define PINA_INTR_NONE      (uint16)(0x0000u)
        #define PINA_INTR_RISING    (uint16)(0x0001u)
        #define PINA_INTR_FALLING   (uint16)(0x0002u)
        #define PINA_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define PINA_INTR_MASK      (0x01u) 
#endif /* (PINA__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PINA_PS                     (* (reg8 *) PINA__PS)
/* Data Register */
#define PINA_DR                     (* (reg8 *) PINA__DR)
/* Port Number */
#define PINA_PRT_NUM                (* (reg8 *) PINA__PRT) 
/* Connect to Analog Globals */                                                  
#define PINA_AG                     (* (reg8 *) PINA__AG)                       
/* Analog MUX bux enable */
#define PINA_AMUX                   (* (reg8 *) PINA__AMUX) 
/* Bidirectional Enable */                                                        
#define PINA_BIE                    (* (reg8 *) PINA__BIE)
/* Bit-mask for Aliased Register Access */
#define PINA_BIT_MASK               (* (reg8 *) PINA__BIT_MASK)
/* Bypass Enable */
#define PINA_BYP                    (* (reg8 *) PINA__BYP)
/* Port wide control signals */                                                   
#define PINA_CTL                    (* (reg8 *) PINA__CTL)
/* Drive Modes */
#define PINA_DM0                    (* (reg8 *) PINA__DM0) 
#define PINA_DM1                    (* (reg8 *) PINA__DM1)
#define PINA_DM2                    (* (reg8 *) PINA__DM2) 
/* Input Buffer Disable Override */
#define PINA_INP_DIS                (* (reg8 *) PINA__INP_DIS)
/* LCD Common or Segment Drive */
#define PINA_LCD_COM_SEG            (* (reg8 *) PINA__LCD_COM_SEG)
/* Enable Segment LCD */
#define PINA_LCD_EN                 (* (reg8 *) PINA__LCD_EN)
/* Slew Rate Control */
#define PINA_SLW                    (* (reg8 *) PINA__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PINA_PRTDSI__CAPS_SEL       (* (reg8 *) PINA__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PINA_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PINA__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PINA_PRTDSI__OE_SEL0        (* (reg8 *) PINA__PRTDSI__OE_SEL0) 
#define PINA_PRTDSI__OE_SEL1        (* (reg8 *) PINA__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PINA_PRTDSI__OUT_SEL0       (* (reg8 *) PINA__PRTDSI__OUT_SEL0) 
#define PINA_PRTDSI__OUT_SEL1       (* (reg8 *) PINA__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PINA_PRTDSI__SYNC_OUT       (* (reg8 *) PINA__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(PINA__SIO_CFG)
    #define PINA_SIO_HYST_EN        (* (reg8 *) PINA__SIO_HYST_EN)
    #define PINA_SIO_REG_HIFREQ     (* (reg8 *) PINA__SIO_REG_HIFREQ)
    #define PINA_SIO_CFG            (* (reg8 *) PINA__SIO_CFG)
    #define PINA_SIO_DIFF           (* (reg8 *) PINA__SIO_DIFF)
#endif /* (PINA__SIO_CFG) */

/* Interrupt Registers */
#if defined(PINA__INTSTAT)
    #define PINA_INTSTAT            (* (reg8 *) PINA__INTSTAT)
    #define PINA_SNAP               (* (reg8 *) PINA__SNAP)
    
	#define PINA_0_INTTYPE_REG 		(* (reg8 *) PINA__0__INTTYPE)
#endif /* (PINA__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PINA_H */


/* [] END OF FILE */
