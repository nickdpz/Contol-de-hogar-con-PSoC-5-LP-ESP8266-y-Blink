/*******************************************************************************
* File Name: PIND.h  
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

#if !defined(CY_PINS_PIND_H) /* Pins PIND_H */
#define CY_PINS_PIND_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PIND_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PIND__PORT == 15 && ((PIND__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    PIND_Write(uint8 value);
void    PIND_SetDriveMode(uint8 mode);
uint8   PIND_ReadDataReg(void);
uint8   PIND_Read(void);
void    PIND_SetInterruptMode(uint16 position, uint16 mode);
uint8   PIND_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the PIND_SetDriveMode() function.
     *  @{
     */
        #define PIND_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define PIND_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define PIND_DM_RES_UP          PIN_DM_RES_UP
        #define PIND_DM_RES_DWN         PIN_DM_RES_DWN
        #define PIND_DM_OD_LO           PIN_DM_OD_LO
        #define PIND_DM_OD_HI           PIN_DM_OD_HI
        #define PIND_DM_STRONG          PIN_DM_STRONG
        #define PIND_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define PIND_MASK               PIND__MASK
#define PIND_SHIFT              PIND__SHIFT
#define PIND_WIDTH              1u

/* Interrupt constants */
#if defined(PIND__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PIND_SetInterruptMode() function.
     *  @{
     */
        #define PIND_INTR_NONE      (uint16)(0x0000u)
        #define PIND_INTR_RISING    (uint16)(0x0001u)
        #define PIND_INTR_FALLING   (uint16)(0x0002u)
        #define PIND_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define PIND_INTR_MASK      (0x01u) 
#endif /* (PIND__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PIND_PS                     (* (reg8 *) PIND__PS)
/* Data Register */
#define PIND_DR                     (* (reg8 *) PIND__DR)
/* Port Number */
#define PIND_PRT_NUM                (* (reg8 *) PIND__PRT) 
/* Connect to Analog Globals */                                                  
#define PIND_AG                     (* (reg8 *) PIND__AG)                       
/* Analog MUX bux enable */
#define PIND_AMUX                   (* (reg8 *) PIND__AMUX) 
/* Bidirectional Enable */                                                        
#define PIND_BIE                    (* (reg8 *) PIND__BIE)
/* Bit-mask for Aliased Register Access */
#define PIND_BIT_MASK               (* (reg8 *) PIND__BIT_MASK)
/* Bypass Enable */
#define PIND_BYP                    (* (reg8 *) PIND__BYP)
/* Port wide control signals */                                                   
#define PIND_CTL                    (* (reg8 *) PIND__CTL)
/* Drive Modes */
#define PIND_DM0                    (* (reg8 *) PIND__DM0) 
#define PIND_DM1                    (* (reg8 *) PIND__DM1)
#define PIND_DM2                    (* (reg8 *) PIND__DM2) 
/* Input Buffer Disable Override */
#define PIND_INP_DIS                (* (reg8 *) PIND__INP_DIS)
/* LCD Common or Segment Drive */
#define PIND_LCD_COM_SEG            (* (reg8 *) PIND__LCD_COM_SEG)
/* Enable Segment LCD */
#define PIND_LCD_EN                 (* (reg8 *) PIND__LCD_EN)
/* Slew Rate Control */
#define PIND_SLW                    (* (reg8 *) PIND__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PIND_PRTDSI__CAPS_SEL       (* (reg8 *) PIND__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PIND_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PIND__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PIND_PRTDSI__OE_SEL0        (* (reg8 *) PIND__PRTDSI__OE_SEL0) 
#define PIND_PRTDSI__OE_SEL1        (* (reg8 *) PIND__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PIND_PRTDSI__OUT_SEL0       (* (reg8 *) PIND__PRTDSI__OUT_SEL0) 
#define PIND_PRTDSI__OUT_SEL1       (* (reg8 *) PIND__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PIND_PRTDSI__SYNC_OUT       (* (reg8 *) PIND__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(PIND__SIO_CFG)
    #define PIND_SIO_HYST_EN        (* (reg8 *) PIND__SIO_HYST_EN)
    #define PIND_SIO_REG_HIFREQ     (* (reg8 *) PIND__SIO_REG_HIFREQ)
    #define PIND_SIO_CFG            (* (reg8 *) PIND__SIO_CFG)
    #define PIND_SIO_DIFF           (* (reg8 *) PIND__SIO_DIFF)
#endif /* (PIND__SIO_CFG) */

/* Interrupt Registers */
#if defined(PIND__INTSTAT)
    #define PIND_INTSTAT            (* (reg8 *) PIND__INTSTAT)
    #define PIND_SNAP               (* (reg8 *) PIND__SNAP)
    
	#define PIND_0_INTTYPE_REG 		(* (reg8 *) PIND__0__INTTYPE)
#endif /* (PIND__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PIND_H */


/* [] END OF FILE */
