/*******************************************************************************
* File Name: PINB.h  
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

#if !defined(CY_PINS_PINB_H) /* Pins PINB_H */
#define CY_PINS_PINB_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PINB_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PINB__PORT == 15 && ((PINB__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    PINB_Write(uint8 value);
void    PINB_SetDriveMode(uint8 mode);
uint8   PINB_ReadDataReg(void);
uint8   PINB_Read(void);
void    PINB_SetInterruptMode(uint16 position, uint16 mode);
uint8   PINB_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the PINB_SetDriveMode() function.
     *  @{
     */
        #define PINB_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define PINB_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define PINB_DM_RES_UP          PIN_DM_RES_UP
        #define PINB_DM_RES_DWN         PIN_DM_RES_DWN
        #define PINB_DM_OD_LO           PIN_DM_OD_LO
        #define PINB_DM_OD_HI           PIN_DM_OD_HI
        #define PINB_DM_STRONG          PIN_DM_STRONG
        #define PINB_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define PINB_MASK               PINB__MASK
#define PINB_SHIFT              PINB__SHIFT
#define PINB_WIDTH              1u

/* Interrupt constants */
#if defined(PINB__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PINB_SetInterruptMode() function.
     *  @{
     */
        #define PINB_INTR_NONE      (uint16)(0x0000u)
        #define PINB_INTR_RISING    (uint16)(0x0001u)
        #define PINB_INTR_FALLING   (uint16)(0x0002u)
        #define PINB_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define PINB_INTR_MASK      (0x01u) 
#endif /* (PINB__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PINB_PS                     (* (reg8 *) PINB__PS)
/* Data Register */
#define PINB_DR                     (* (reg8 *) PINB__DR)
/* Port Number */
#define PINB_PRT_NUM                (* (reg8 *) PINB__PRT) 
/* Connect to Analog Globals */                                                  
#define PINB_AG                     (* (reg8 *) PINB__AG)                       
/* Analog MUX bux enable */
#define PINB_AMUX                   (* (reg8 *) PINB__AMUX) 
/* Bidirectional Enable */                                                        
#define PINB_BIE                    (* (reg8 *) PINB__BIE)
/* Bit-mask for Aliased Register Access */
#define PINB_BIT_MASK               (* (reg8 *) PINB__BIT_MASK)
/* Bypass Enable */
#define PINB_BYP                    (* (reg8 *) PINB__BYP)
/* Port wide control signals */                                                   
#define PINB_CTL                    (* (reg8 *) PINB__CTL)
/* Drive Modes */
#define PINB_DM0                    (* (reg8 *) PINB__DM0) 
#define PINB_DM1                    (* (reg8 *) PINB__DM1)
#define PINB_DM2                    (* (reg8 *) PINB__DM2) 
/* Input Buffer Disable Override */
#define PINB_INP_DIS                (* (reg8 *) PINB__INP_DIS)
/* LCD Common or Segment Drive */
#define PINB_LCD_COM_SEG            (* (reg8 *) PINB__LCD_COM_SEG)
/* Enable Segment LCD */
#define PINB_LCD_EN                 (* (reg8 *) PINB__LCD_EN)
/* Slew Rate Control */
#define PINB_SLW                    (* (reg8 *) PINB__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PINB_PRTDSI__CAPS_SEL       (* (reg8 *) PINB__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PINB_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PINB__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PINB_PRTDSI__OE_SEL0        (* (reg8 *) PINB__PRTDSI__OE_SEL0) 
#define PINB_PRTDSI__OE_SEL1        (* (reg8 *) PINB__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PINB_PRTDSI__OUT_SEL0       (* (reg8 *) PINB__PRTDSI__OUT_SEL0) 
#define PINB_PRTDSI__OUT_SEL1       (* (reg8 *) PINB__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PINB_PRTDSI__SYNC_OUT       (* (reg8 *) PINB__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(PINB__SIO_CFG)
    #define PINB_SIO_HYST_EN        (* (reg8 *) PINB__SIO_HYST_EN)
    #define PINB_SIO_REG_HIFREQ     (* (reg8 *) PINB__SIO_REG_HIFREQ)
    #define PINB_SIO_CFG            (* (reg8 *) PINB__SIO_CFG)
    #define PINB_SIO_DIFF           (* (reg8 *) PINB__SIO_DIFF)
#endif /* (PINB__SIO_CFG) */

/* Interrupt Registers */
#if defined(PINB__INTSTAT)
    #define PINB_INTSTAT            (* (reg8 *) PINB__INTSTAT)
    #define PINB_SNAP               (* (reg8 *) PINB__SNAP)
    
	#define PINB_0_INTTYPE_REG 		(* (reg8 *) PINB__0__INTTYPE)
#endif /* (PINB__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PINB_H */


/* [] END OF FILE */
