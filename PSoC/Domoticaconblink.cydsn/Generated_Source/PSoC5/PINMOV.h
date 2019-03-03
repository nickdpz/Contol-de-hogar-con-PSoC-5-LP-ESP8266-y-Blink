/*******************************************************************************
* File Name: PINMOV.h  
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

#if !defined(CY_PINS_PINMOV_H) /* Pins PINMOV_H */
#define CY_PINS_PINMOV_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PINMOV_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PINMOV__PORT == 15 && ((PINMOV__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    PINMOV_Write(uint8 value);
void    PINMOV_SetDriveMode(uint8 mode);
uint8   PINMOV_ReadDataReg(void);
uint8   PINMOV_Read(void);
void    PINMOV_SetInterruptMode(uint16 position, uint16 mode);
uint8   PINMOV_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the PINMOV_SetDriveMode() function.
     *  @{
     */
        #define PINMOV_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define PINMOV_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define PINMOV_DM_RES_UP          PIN_DM_RES_UP
        #define PINMOV_DM_RES_DWN         PIN_DM_RES_DWN
        #define PINMOV_DM_OD_LO           PIN_DM_OD_LO
        #define PINMOV_DM_OD_HI           PIN_DM_OD_HI
        #define PINMOV_DM_STRONG          PIN_DM_STRONG
        #define PINMOV_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define PINMOV_MASK               PINMOV__MASK
#define PINMOV_SHIFT              PINMOV__SHIFT
#define PINMOV_WIDTH              1u

/* Interrupt constants */
#if defined(PINMOV__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PINMOV_SetInterruptMode() function.
     *  @{
     */
        #define PINMOV_INTR_NONE      (uint16)(0x0000u)
        #define PINMOV_INTR_RISING    (uint16)(0x0001u)
        #define PINMOV_INTR_FALLING   (uint16)(0x0002u)
        #define PINMOV_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define PINMOV_INTR_MASK      (0x01u) 
#endif /* (PINMOV__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PINMOV_PS                     (* (reg8 *) PINMOV__PS)
/* Data Register */
#define PINMOV_DR                     (* (reg8 *) PINMOV__DR)
/* Port Number */
#define PINMOV_PRT_NUM                (* (reg8 *) PINMOV__PRT) 
/* Connect to Analog Globals */                                                  
#define PINMOV_AG                     (* (reg8 *) PINMOV__AG)                       
/* Analog MUX bux enable */
#define PINMOV_AMUX                   (* (reg8 *) PINMOV__AMUX) 
/* Bidirectional Enable */                                                        
#define PINMOV_BIE                    (* (reg8 *) PINMOV__BIE)
/* Bit-mask for Aliased Register Access */
#define PINMOV_BIT_MASK               (* (reg8 *) PINMOV__BIT_MASK)
/* Bypass Enable */
#define PINMOV_BYP                    (* (reg8 *) PINMOV__BYP)
/* Port wide control signals */                                                   
#define PINMOV_CTL                    (* (reg8 *) PINMOV__CTL)
/* Drive Modes */
#define PINMOV_DM0                    (* (reg8 *) PINMOV__DM0) 
#define PINMOV_DM1                    (* (reg8 *) PINMOV__DM1)
#define PINMOV_DM2                    (* (reg8 *) PINMOV__DM2) 
/* Input Buffer Disable Override */
#define PINMOV_INP_DIS                (* (reg8 *) PINMOV__INP_DIS)
/* LCD Common or Segment Drive */
#define PINMOV_LCD_COM_SEG            (* (reg8 *) PINMOV__LCD_COM_SEG)
/* Enable Segment LCD */
#define PINMOV_LCD_EN                 (* (reg8 *) PINMOV__LCD_EN)
/* Slew Rate Control */
#define PINMOV_SLW                    (* (reg8 *) PINMOV__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PINMOV_PRTDSI__CAPS_SEL       (* (reg8 *) PINMOV__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PINMOV_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PINMOV__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PINMOV_PRTDSI__OE_SEL0        (* (reg8 *) PINMOV__PRTDSI__OE_SEL0) 
#define PINMOV_PRTDSI__OE_SEL1        (* (reg8 *) PINMOV__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PINMOV_PRTDSI__OUT_SEL0       (* (reg8 *) PINMOV__PRTDSI__OUT_SEL0) 
#define PINMOV_PRTDSI__OUT_SEL1       (* (reg8 *) PINMOV__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PINMOV_PRTDSI__SYNC_OUT       (* (reg8 *) PINMOV__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(PINMOV__SIO_CFG)
    #define PINMOV_SIO_HYST_EN        (* (reg8 *) PINMOV__SIO_HYST_EN)
    #define PINMOV_SIO_REG_HIFREQ     (* (reg8 *) PINMOV__SIO_REG_HIFREQ)
    #define PINMOV_SIO_CFG            (* (reg8 *) PINMOV__SIO_CFG)
    #define PINMOV_SIO_DIFF           (* (reg8 *) PINMOV__SIO_DIFF)
#endif /* (PINMOV__SIO_CFG) */

/* Interrupt Registers */
#if defined(PINMOV__INTSTAT)
    #define PINMOV_INTSTAT            (* (reg8 *) PINMOV__INTSTAT)
    #define PINMOV_SNAP               (* (reg8 *) PINMOV__SNAP)
    
	#define PINMOV_0_INTTYPE_REG 		(* (reg8 *) PINMOV__0__INTTYPE)
#endif /* (PINMOV__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PINMOV_H */


/* [] END OF FILE */
