/*******************************************************************************
* File Name: PTEMP.h  
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

#if !defined(CY_PINS_PTEMP_H) /* Pins PTEMP_H */
#define CY_PINS_PTEMP_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PTEMP_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PTEMP__PORT == 15 && ((PTEMP__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    PTEMP_Write(uint8 value);
void    PTEMP_SetDriveMode(uint8 mode);
uint8   PTEMP_ReadDataReg(void);
uint8   PTEMP_Read(void);
void    PTEMP_SetInterruptMode(uint16 position, uint16 mode);
uint8   PTEMP_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the PTEMP_SetDriveMode() function.
     *  @{
     */
        #define PTEMP_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define PTEMP_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define PTEMP_DM_RES_UP          PIN_DM_RES_UP
        #define PTEMP_DM_RES_DWN         PIN_DM_RES_DWN
        #define PTEMP_DM_OD_LO           PIN_DM_OD_LO
        #define PTEMP_DM_OD_HI           PIN_DM_OD_HI
        #define PTEMP_DM_STRONG          PIN_DM_STRONG
        #define PTEMP_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define PTEMP_MASK               PTEMP__MASK
#define PTEMP_SHIFT              PTEMP__SHIFT
#define PTEMP_WIDTH              1u

/* Interrupt constants */
#if defined(PTEMP__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PTEMP_SetInterruptMode() function.
     *  @{
     */
        #define PTEMP_INTR_NONE      (uint16)(0x0000u)
        #define PTEMP_INTR_RISING    (uint16)(0x0001u)
        #define PTEMP_INTR_FALLING   (uint16)(0x0002u)
        #define PTEMP_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define PTEMP_INTR_MASK      (0x01u) 
#endif /* (PTEMP__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PTEMP_PS                     (* (reg8 *) PTEMP__PS)
/* Data Register */
#define PTEMP_DR                     (* (reg8 *) PTEMP__DR)
/* Port Number */
#define PTEMP_PRT_NUM                (* (reg8 *) PTEMP__PRT) 
/* Connect to Analog Globals */                                                  
#define PTEMP_AG                     (* (reg8 *) PTEMP__AG)                       
/* Analog MUX bux enable */
#define PTEMP_AMUX                   (* (reg8 *) PTEMP__AMUX) 
/* Bidirectional Enable */                                                        
#define PTEMP_BIE                    (* (reg8 *) PTEMP__BIE)
/* Bit-mask for Aliased Register Access */
#define PTEMP_BIT_MASK               (* (reg8 *) PTEMP__BIT_MASK)
/* Bypass Enable */
#define PTEMP_BYP                    (* (reg8 *) PTEMP__BYP)
/* Port wide control signals */                                                   
#define PTEMP_CTL                    (* (reg8 *) PTEMP__CTL)
/* Drive Modes */
#define PTEMP_DM0                    (* (reg8 *) PTEMP__DM0) 
#define PTEMP_DM1                    (* (reg8 *) PTEMP__DM1)
#define PTEMP_DM2                    (* (reg8 *) PTEMP__DM2) 
/* Input Buffer Disable Override */
#define PTEMP_INP_DIS                (* (reg8 *) PTEMP__INP_DIS)
/* LCD Common or Segment Drive */
#define PTEMP_LCD_COM_SEG            (* (reg8 *) PTEMP__LCD_COM_SEG)
/* Enable Segment LCD */
#define PTEMP_LCD_EN                 (* (reg8 *) PTEMP__LCD_EN)
/* Slew Rate Control */
#define PTEMP_SLW                    (* (reg8 *) PTEMP__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PTEMP_PRTDSI__CAPS_SEL       (* (reg8 *) PTEMP__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PTEMP_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PTEMP__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PTEMP_PRTDSI__OE_SEL0        (* (reg8 *) PTEMP__PRTDSI__OE_SEL0) 
#define PTEMP_PRTDSI__OE_SEL1        (* (reg8 *) PTEMP__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PTEMP_PRTDSI__OUT_SEL0       (* (reg8 *) PTEMP__PRTDSI__OUT_SEL0) 
#define PTEMP_PRTDSI__OUT_SEL1       (* (reg8 *) PTEMP__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PTEMP_PRTDSI__SYNC_OUT       (* (reg8 *) PTEMP__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(PTEMP__SIO_CFG)
    #define PTEMP_SIO_HYST_EN        (* (reg8 *) PTEMP__SIO_HYST_EN)
    #define PTEMP_SIO_REG_HIFREQ     (* (reg8 *) PTEMP__SIO_REG_HIFREQ)
    #define PTEMP_SIO_CFG            (* (reg8 *) PTEMP__SIO_CFG)
    #define PTEMP_SIO_DIFF           (* (reg8 *) PTEMP__SIO_DIFF)
#endif /* (PTEMP__SIO_CFG) */

/* Interrupt Registers */
#if defined(PTEMP__INTSTAT)
    #define PTEMP_INTSTAT            (* (reg8 *) PTEMP__INTSTAT)
    #define PTEMP_SNAP               (* (reg8 *) PTEMP__SNAP)
    
	#define PTEMP_0_INTTYPE_REG 		(* (reg8 *) PTEMP__0__INTTYPE)
#endif /* (PTEMP__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PTEMP_H */


/* [] END OF FILE */
