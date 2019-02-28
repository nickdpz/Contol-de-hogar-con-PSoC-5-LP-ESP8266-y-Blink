/*******************************************************************************
* File Name: PHabitacion.h  
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

#if !defined(CY_PINS_PHabitacion_H) /* Pins PHabitacion_H */
#define CY_PINS_PHabitacion_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PHabitacion_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PHabitacion__PORT == 15 && ((PHabitacion__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    PHabitacion_Write(uint8 value);
void    PHabitacion_SetDriveMode(uint8 mode);
uint8   PHabitacion_ReadDataReg(void);
uint8   PHabitacion_Read(void);
void    PHabitacion_SetInterruptMode(uint16 position, uint16 mode);
uint8   PHabitacion_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the PHabitacion_SetDriveMode() function.
     *  @{
     */
        #define PHabitacion_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define PHabitacion_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define PHabitacion_DM_RES_UP          PIN_DM_RES_UP
        #define PHabitacion_DM_RES_DWN         PIN_DM_RES_DWN
        #define PHabitacion_DM_OD_LO           PIN_DM_OD_LO
        #define PHabitacion_DM_OD_HI           PIN_DM_OD_HI
        #define PHabitacion_DM_STRONG          PIN_DM_STRONG
        #define PHabitacion_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define PHabitacion_MASK               PHabitacion__MASK
#define PHabitacion_SHIFT              PHabitacion__SHIFT
#define PHabitacion_WIDTH              1u

/* Interrupt constants */
#if defined(PHabitacion__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PHabitacion_SetInterruptMode() function.
     *  @{
     */
        #define PHabitacion_INTR_NONE      (uint16)(0x0000u)
        #define PHabitacion_INTR_RISING    (uint16)(0x0001u)
        #define PHabitacion_INTR_FALLING   (uint16)(0x0002u)
        #define PHabitacion_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define PHabitacion_INTR_MASK      (0x01u) 
#endif /* (PHabitacion__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PHabitacion_PS                     (* (reg8 *) PHabitacion__PS)
/* Data Register */
#define PHabitacion_DR                     (* (reg8 *) PHabitacion__DR)
/* Port Number */
#define PHabitacion_PRT_NUM                (* (reg8 *) PHabitacion__PRT) 
/* Connect to Analog Globals */                                                  
#define PHabitacion_AG                     (* (reg8 *) PHabitacion__AG)                       
/* Analog MUX bux enable */
#define PHabitacion_AMUX                   (* (reg8 *) PHabitacion__AMUX) 
/* Bidirectional Enable */                                                        
#define PHabitacion_BIE                    (* (reg8 *) PHabitacion__BIE)
/* Bit-mask for Aliased Register Access */
#define PHabitacion_BIT_MASK               (* (reg8 *) PHabitacion__BIT_MASK)
/* Bypass Enable */
#define PHabitacion_BYP                    (* (reg8 *) PHabitacion__BYP)
/* Port wide control signals */                                                   
#define PHabitacion_CTL                    (* (reg8 *) PHabitacion__CTL)
/* Drive Modes */
#define PHabitacion_DM0                    (* (reg8 *) PHabitacion__DM0) 
#define PHabitacion_DM1                    (* (reg8 *) PHabitacion__DM1)
#define PHabitacion_DM2                    (* (reg8 *) PHabitacion__DM2) 
/* Input Buffer Disable Override */
#define PHabitacion_INP_DIS                (* (reg8 *) PHabitacion__INP_DIS)
/* LCD Common or Segment Drive */
#define PHabitacion_LCD_COM_SEG            (* (reg8 *) PHabitacion__LCD_COM_SEG)
/* Enable Segment LCD */
#define PHabitacion_LCD_EN                 (* (reg8 *) PHabitacion__LCD_EN)
/* Slew Rate Control */
#define PHabitacion_SLW                    (* (reg8 *) PHabitacion__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PHabitacion_PRTDSI__CAPS_SEL       (* (reg8 *) PHabitacion__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PHabitacion_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PHabitacion__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PHabitacion_PRTDSI__OE_SEL0        (* (reg8 *) PHabitacion__PRTDSI__OE_SEL0) 
#define PHabitacion_PRTDSI__OE_SEL1        (* (reg8 *) PHabitacion__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PHabitacion_PRTDSI__OUT_SEL0       (* (reg8 *) PHabitacion__PRTDSI__OUT_SEL0) 
#define PHabitacion_PRTDSI__OUT_SEL1       (* (reg8 *) PHabitacion__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PHabitacion_PRTDSI__SYNC_OUT       (* (reg8 *) PHabitacion__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(PHabitacion__SIO_CFG)
    #define PHabitacion_SIO_HYST_EN        (* (reg8 *) PHabitacion__SIO_HYST_EN)
    #define PHabitacion_SIO_REG_HIFREQ     (* (reg8 *) PHabitacion__SIO_REG_HIFREQ)
    #define PHabitacion_SIO_CFG            (* (reg8 *) PHabitacion__SIO_CFG)
    #define PHabitacion_SIO_DIFF           (* (reg8 *) PHabitacion__SIO_DIFF)
#endif /* (PHabitacion__SIO_CFG) */

/* Interrupt Registers */
#if defined(PHabitacion__INTSTAT)
    #define PHabitacion_INTSTAT            (* (reg8 *) PHabitacion__INTSTAT)
    #define PHabitacion_SNAP               (* (reg8 *) PHabitacion__SNAP)
    
	#define PHabitacion_0_INTTYPE_REG 		(* (reg8 *) PHabitacion__0__INTTYPE)
#endif /* (PHabitacion__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PHabitacion_H */


/* [] END OF FILE */
