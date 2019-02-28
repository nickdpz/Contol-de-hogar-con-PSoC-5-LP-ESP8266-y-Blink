/*******************************************************************************
* File Name: PINC.h  
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

#if !defined(CY_PINS_PINC_H) /* Pins PINC_H */
#define CY_PINS_PINC_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PINC_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PINC__PORT == 15 && ((PINC__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    PINC_Write(uint8 value);
void    PINC_SetDriveMode(uint8 mode);
uint8   PINC_ReadDataReg(void);
uint8   PINC_Read(void);
void    PINC_SetInterruptMode(uint16 position, uint16 mode);
uint8   PINC_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the PINC_SetDriveMode() function.
     *  @{
     */
        #define PINC_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define PINC_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define PINC_DM_RES_UP          PIN_DM_RES_UP
        #define PINC_DM_RES_DWN         PIN_DM_RES_DWN
        #define PINC_DM_OD_LO           PIN_DM_OD_LO
        #define PINC_DM_OD_HI           PIN_DM_OD_HI
        #define PINC_DM_STRONG          PIN_DM_STRONG
        #define PINC_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define PINC_MASK               PINC__MASK
#define PINC_SHIFT              PINC__SHIFT
#define PINC_WIDTH              1u

/* Interrupt constants */
#if defined(PINC__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PINC_SetInterruptMode() function.
     *  @{
     */
        #define PINC_INTR_NONE      (uint16)(0x0000u)
        #define PINC_INTR_RISING    (uint16)(0x0001u)
        #define PINC_INTR_FALLING   (uint16)(0x0002u)
        #define PINC_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define PINC_INTR_MASK      (0x01u) 
#endif /* (PINC__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PINC_PS                     (* (reg8 *) PINC__PS)
/* Data Register */
#define PINC_DR                     (* (reg8 *) PINC__DR)
/* Port Number */
#define PINC_PRT_NUM                (* (reg8 *) PINC__PRT) 
/* Connect to Analog Globals */                                                  
#define PINC_AG                     (* (reg8 *) PINC__AG)                       
/* Analog MUX bux enable */
#define PINC_AMUX                   (* (reg8 *) PINC__AMUX) 
/* Bidirectional Enable */                                                        
#define PINC_BIE                    (* (reg8 *) PINC__BIE)
/* Bit-mask for Aliased Register Access */
#define PINC_BIT_MASK               (* (reg8 *) PINC__BIT_MASK)
/* Bypass Enable */
#define PINC_BYP                    (* (reg8 *) PINC__BYP)
/* Port wide control signals */                                                   
#define PINC_CTL                    (* (reg8 *) PINC__CTL)
/* Drive Modes */
#define PINC_DM0                    (* (reg8 *) PINC__DM0) 
#define PINC_DM1                    (* (reg8 *) PINC__DM1)
#define PINC_DM2                    (* (reg8 *) PINC__DM2) 
/* Input Buffer Disable Override */
#define PINC_INP_DIS                (* (reg8 *) PINC__INP_DIS)
/* LCD Common or Segment Drive */
#define PINC_LCD_COM_SEG            (* (reg8 *) PINC__LCD_COM_SEG)
/* Enable Segment LCD */
#define PINC_LCD_EN                 (* (reg8 *) PINC__LCD_EN)
/* Slew Rate Control */
#define PINC_SLW                    (* (reg8 *) PINC__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PINC_PRTDSI__CAPS_SEL       (* (reg8 *) PINC__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PINC_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PINC__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PINC_PRTDSI__OE_SEL0        (* (reg8 *) PINC__PRTDSI__OE_SEL0) 
#define PINC_PRTDSI__OE_SEL1        (* (reg8 *) PINC__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PINC_PRTDSI__OUT_SEL0       (* (reg8 *) PINC__PRTDSI__OUT_SEL0) 
#define PINC_PRTDSI__OUT_SEL1       (* (reg8 *) PINC__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PINC_PRTDSI__SYNC_OUT       (* (reg8 *) PINC__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(PINC__SIO_CFG)
    #define PINC_SIO_HYST_EN        (* (reg8 *) PINC__SIO_HYST_EN)
    #define PINC_SIO_REG_HIFREQ     (* (reg8 *) PINC__SIO_REG_HIFREQ)
    #define PINC_SIO_CFG            (* (reg8 *) PINC__SIO_CFG)
    #define PINC_SIO_DIFF           (* (reg8 *) PINC__SIO_DIFF)
#endif /* (PINC__SIO_CFG) */

/* Interrupt Registers */
#if defined(PINC__INTSTAT)
    #define PINC_INTSTAT            (* (reg8 *) PINC__INTSTAT)
    #define PINC_SNAP               (* (reg8 *) PINC__SNAP)
    
	#define PINC_0_INTTYPE_REG 		(* (reg8 *) PINC__0__INTTYPE)
#endif /* (PINC__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PINC_H */


/* [] END OF FILE */
