/*******************************************************************************
* File Name: HCSR501.h  
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

#if !defined(CY_PINS_HCSR501_H) /* Pins HCSR501_H */
#define CY_PINS_HCSR501_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "HCSR501_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 HCSR501__PORT == 15 && ((HCSR501__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    HCSR501_Write(uint8 value);
void    HCSR501_SetDriveMode(uint8 mode);
uint8   HCSR501_ReadDataReg(void);
uint8   HCSR501_Read(void);
void    HCSR501_SetInterruptMode(uint16 position, uint16 mode);
uint8   HCSR501_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the HCSR501_SetDriveMode() function.
     *  @{
     */
        #define HCSR501_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define HCSR501_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define HCSR501_DM_RES_UP          PIN_DM_RES_UP
        #define HCSR501_DM_RES_DWN         PIN_DM_RES_DWN
        #define HCSR501_DM_OD_LO           PIN_DM_OD_LO
        #define HCSR501_DM_OD_HI           PIN_DM_OD_HI
        #define HCSR501_DM_STRONG          PIN_DM_STRONG
        #define HCSR501_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define HCSR501_MASK               HCSR501__MASK
#define HCSR501_SHIFT              HCSR501__SHIFT
#define HCSR501_WIDTH              1u

/* Interrupt constants */
#if defined(HCSR501__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in HCSR501_SetInterruptMode() function.
     *  @{
     */
        #define HCSR501_INTR_NONE      (uint16)(0x0000u)
        #define HCSR501_INTR_RISING    (uint16)(0x0001u)
        #define HCSR501_INTR_FALLING   (uint16)(0x0002u)
        #define HCSR501_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define HCSR501_INTR_MASK      (0x01u) 
#endif /* (HCSR501__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define HCSR501_PS                     (* (reg8 *) HCSR501__PS)
/* Data Register */
#define HCSR501_DR                     (* (reg8 *) HCSR501__DR)
/* Port Number */
#define HCSR501_PRT_NUM                (* (reg8 *) HCSR501__PRT) 
/* Connect to Analog Globals */                                                  
#define HCSR501_AG                     (* (reg8 *) HCSR501__AG)                       
/* Analog MUX bux enable */
#define HCSR501_AMUX                   (* (reg8 *) HCSR501__AMUX) 
/* Bidirectional Enable */                                                        
#define HCSR501_BIE                    (* (reg8 *) HCSR501__BIE)
/* Bit-mask for Aliased Register Access */
#define HCSR501_BIT_MASK               (* (reg8 *) HCSR501__BIT_MASK)
/* Bypass Enable */
#define HCSR501_BYP                    (* (reg8 *) HCSR501__BYP)
/* Port wide control signals */                                                   
#define HCSR501_CTL                    (* (reg8 *) HCSR501__CTL)
/* Drive Modes */
#define HCSR501_DM0                    (* (reg8 *) HCSR501__DM0) 
#define HCSR501_DM1                    (* (reg8 *) HCSR501__DM1)
#define HCSR501_DM2                    (* (reg8 *) HCSR501__DM2) 
/* Input Buffer Disable Override */
#define HCSR501_INP_DIS                (* (reg8 *) HCSR501__INP_DIS)
/* LCD Common or Segment Drive */
#define HCSR501_LCD_COM_SEG            (* (reg8 *) HCSR501__LCD_COM_SEG)
/* Enable Segment LCD */
#define HCSR501_LCD_EN                 (* (reg8 *) HCSR501__LCD_EN)
/* Slew Rate Control */
#define HCSR501_SLW                    (* (reg8 *) HCSR501__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define HCSR501_PRTDSI__CAPS_SEL       (* (reg8 *) HCSR501__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define HCSR501_PRTDSI__DBL_SYNC_IN    (* (reg8 *) HCSR501__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define HCSR501_PRTDSI__OE_SEL0        (* (reg8 *) HCSR501__PRTDSI__OE_SEL0) 
#define HCSR501_PRTDSI__OE_SEL1        (* (reg8 *) HCSR501__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define HCSR501_PRTDSI__OUT_SEL0       (* (reg8 *) HCSR501__PRTDSI__OUT_SEL0) 
#define HCSR501_PRTDSI__OUT_SEL1       (* (reg8 *) HCSR501__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define HCSR501_PRTDSI__SYNC_OUT       (* (reg8 *) HCSR501__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(HCSR501__SIO_CFG)
    #define HCSR501_SIO_HYST_EN        (* (reg8 *) HCSR501__SIO_HYST_EN)
    #define HCSR501_SIO_REG_HIFREQ     (* (reg8 *) HCSR501__SIO_REG_HIFREQ)
    #define HCSR501_SIO_CFG            (* (reg8 *) HCSR501__SIO_CFG)
    #define HCSR501_SIO_DIFF           (* (reg8 *) HCSR501__SIO_DIFF)
#endif /* (HCSR501__SIO_CFG) */

/* Interrupt Registers */
#if defined(HCSR501__INTSTAT)
    #define HCSR501_INTSTAT            (* (reg8 *) HCSR501__INTSTAT)
    #define HCSR501_SNAP               (* (reg8 *) HCSR501__SNAP)
    
	#define HCSR501_0_INTTYPE_REG 		(* (reg8 *) HCSR501__0__INTTYPE)
#endif /* (HCSR501__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_HCSR501_H */


/* [] END OF FILE */
