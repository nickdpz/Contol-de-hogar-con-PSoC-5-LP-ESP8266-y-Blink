/*******************************************************************************
* File Name: PSala.h  
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

#if !defined(CY_PINS_PSala_H) /* Pins PSala_H */
#define CY_PINS_PSala_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PSala_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PSala__PORT == 15 && ((PSala__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    PSala_Write(uint8 value);
void    PSala_SetDriveMode(uint8 mode);
uint8   PSala_ReadDataReg(void);
uint8   PSala_Read(void);
void    PSala_SetInterruptMode(uint16 position, uint16 mode);
uint8   PSala_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the PSala_SetDriveMode() function.
     *  @{
     */
        #define PSala_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define PSala_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define PSala_DM_RES_UP          PIN_DM_RES_UP
        #define PSala_DM_RES_DWN         PIN_DM_RES_DWN
        #define PSala_DM_OD_LO           PIN_DM_OD_LO
        #define PSala_DM_OD_HI           PIN_DM_OD_HI
        #define PSala_DM_STRONG          PIN_DM_STRONG
        #define PSala_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define PSala_MASK               PSala__MASK
#define PSala_SHIFT              PSala__SHIFT
#define PSala_WIDTH              1u

/* Interrupt constants */
#if defined(PSala__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PSala_SetInterruptMode() function.
     *  @{
     */
        #define PSala_INTR_NONE      (uint16)(0x0000u)
        #define PSala_INTR_RISING    (uint16)(0x0001u)
        #define PSala_INTR_FALLING   (uint16)(0x0002u)
        #define PSala_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define PSala_INTR_MASK      (0x01u) 
#endif /* (PSala__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PSala_PS                     (* (reg8 *) PSala__PS)
/* Data Register */
#define PSala_DR                     (* (reg8 *) PSala__DR)
/* Port Number */
#define PSala_PRT_NUM                (* (reg8 *) PSala__PRT) 
/* Connect to Analog Globals */                                                  
#define PSala_AG                     (* (reg8 *) PSala__AG)                       
/* Analog MUX bux enable */
#define PSala_AMUX                   (* (reg8 *) PSala__AMUX) 
/* Bidirectional Enable */                                                        
#define PSala_BIE                    (* (reg8 *) PSala__BIE)
/* Bit-mask for Aliased Register Access */
#define PSala_BIT_MASK               (* (reg8 *) PSala__BIT_MASK)
/* Bypass Enable */
#define PSala_BYP                    (* (reg8 *) PSala__BYP)
/* Port wide control signals */                                                   
#define PSala_CTL                    (* (reg8 *) PSala__CTL)
/* Drive Modes */
#define PSala_DM0                    (* (reg8 *) PSala__DM0) 
#define PSala_DM1                    (* (reg8 *) PSala__DM1)
#define PSala_DM2                    (* (reg8 *) PSala__DM2) 
/* Input Buffer Disable Override */
#define PSala_INP_DIS                (* (reg8 *) PSala__INP_DIS)
/* LCD Common or Segment Drive */
#define PSala_LCD_COM_SEG            (* (reg8 *) PSala__LCD_COM_SEG)
/* Enable Segment LCD */
#define PSala_LCD_EN                 (* (reg8 *) PSala__LCD_EN)
/* Slew Rate Control */
#define PSala_SLW                    (* (reg8 *) PSala__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PSala_PRTDSI__CAPS_SEL       (* (reg8 *) PSala__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PSala_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PSala__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PSala_PRTDSI__OE_SEL0        (* (reg8 *) PSala__PRTDSI__OE_SEL0) 
#define PSala_PRTDSI__OE_SEL1        (* (reg8 *) PSala__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PSala_PRTDSI__OUT_SEL0       (* (reg8 *) PSala__PRTDSI__OUT_SEL0) 
#define PSala_PRTDSI__OUT_SEL1       (* (reg8 *) PSala__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PSala_PRTDSI__SYNC_OUT       (* (reg8 *) PSala__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(PSala__SIO_CFG)
    #define PSala_SIO_HYST_EN        (* (reg8 *) PSala__SIO_HYST_EN)
    #define PSala_SIO_REG_HIFREQ     (* (reg8 *) PSala__SIO_REG_HIFREQ)
    #define PSala_SIO_CFG            (* (reg8 *) PSala__SIO_CFG)
    #define PSala_SIO_DIFF           (* (reg8 *) PSala__SIO_DIFF)
#endif /* (PSala__SIO_CFG) */

/* Interrupt Registers */
#if defined(PSala__INTSTAT)
    #define PSala_INTSTAT            (* (reg8 *) PSala__INTSTAT)
    #define PSala_SNAP               (* (reg8 *) PSala__SNAP)
    
	#define PSala_0_INTTYPE_REG 		(* (reg8 *) PSala__0__INTTYPE)
#endif /* (PSala__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PSala_H */


/* [] END OF FILE */
