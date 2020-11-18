/*******************************************************************************
* File Name: Pin_10.h  
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

#if !defined(CY_PINS_Pin_10_H) /* Pins Pin_10_H */
#define CY_PINS_Pin_10_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Pin_10_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Pin_10__PORT == 15 && ((Pin_10__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Pin_10_Write(uint8 value);
void    Pin_10_SetDriveMode(uint8 mode);
uint8   Pin_10_ReadDataReg(void);
uint8   Pin_10_Read(void);
void    Pin_10_SetInterruptMode(uint16 position, uint16 mode);
uint8   Pin_10_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Pin_10_SetDriveMode() function.
     *  @{
     */
        #define Pin_10_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Pin_10_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Pin_10_DM_RES_UP          PIN_DM_RES_UP
        #define Pin_10_DM_RES_DWN         PIN_DM_RES_DWN
        #define Pin_10_DM_OD_LO           PIN_DM_OD_LO
        #define Pin_10_DM_OD_HI           PIN_DM_OD_HI
        #define Pin_10_DM_STRONG          PIN_DM_STRONG
        #define Pin_10_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Pin_10_MASK               Pin_10__MASK
#define Pin_10_SHIFT              Pin_10__SHIFT
#define Pin_10_WIDTH              8u

/* Interrupt constants */
#if defined(Pin_10__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Pin_10_SetInterruptMode() function.
     *  @{
     */
        #define Pin_10_INTR_NONE      (uint16)(0x0000u)
        #define Pin_10_INTR_RISING    (uint16)(0x0001u)
        #define Pin_10_INTR_FALLING   (uint16)(0x0002u)
        #define Pin_10_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Pin_10_INTR_MASK      (0x01u) 
#endif /* (Pin_10__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Pin_10_PS                     (* (reg8 *) Pin_10__PS)
/* Data Register */
#define Pin_10_DR                     (* (reg8 *) Pin_10__DR)
/* Port Number */
#define Pin_10_PRT_NUM                (* (reg8 *) Pin_10__PRT) 
/* Connect to Analog Globals */                                                  
#define Pin_10_AG                     (* (reg8 *) Pin_10__AG)                       
/* Analog MUX bux enable */
#define Pin_10_AMUX                   (* (reg8 *) Pin_10__AMUX) 
/* Bidirectional Enable */                                                        
#define Pin_10_BIE                    (* (reg8 *) Pin_10__BIE)
/* Bit-mask for Aliased Register Access */
#define Pin_10_BIT_MASK               (* (reg8 *) Pin_10__BIT_MASK)
/* Bypass Enable */
#define Pin_10_BYP                    (* (reg8 *) Pin_10__BYP)
/* Port wide control signals */                                                   
#define Pin_10_CTL                    (* (reg8 *) Pin_10__CTL)
/* Drive Modes */
#define Pin_10_DM0                    (* (reg8 *) Pin_10__DM0) 
#define Pin_10_DM1                    (* (reg8 *) Pin_10__DM1)
#define Pin_10_DM2                    (* (reg8 *) Pin_10__DM2) 
/* Input Buffer Disable Override */
#define Pin_10_INP_DIS                (* (reg8 *) Pin_10__INP_DIS)
/* LCD Common or Segment Drive */
#define Pin_10_LCD_COM_SEG            (* (reg8 *) Pin_10__LCD_COM_SEG)
/* Enable Segment LCD */
#define Pin_10_LCD_EN                 (* (reg8 *) Pin_10__LCD_EN)
/* Slew Rate Control */
#define Pin_10_SLW                    (* (reg8 *) Pin_10__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Pin_10_PRTDSI__CAPS_SEL       (* (reg8 *) Pin_10__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Pin_10_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Pin_10__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Pin_10_PRTDSI__OE_SEL0        (* (reg8 *) Pin_10__PRTDSI__OE_SEL0) 
#define Pin_10_PRTDSI__OE_SEL1        (* (reg8 *) Pin_10__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Pin_10_PRTDSI__OUT_SEL0       (* (reg8 *) Pin_10__PRTDSI__OUT_SEL0) 
#define Pin_10_PRTDSI__OUT_SEL1       (* (reg8 *) Pin_10__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Pin_10_PRTDSI__SYNC_OUT       (* (reg8 *) Pin_10__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Pin_10__SIO_CFG)
    #define Pin_10_SIO_HYST_EN        (* (reg8 *) Pin_10__SIO_HYST_EN)
    #define Pin_10_SIO_REG_HIFREQ     (* (reg8 *) Pin_10__SIO_REG_HIFREQ)
    #define Pin_10_SIO_CFG            (* (reg8 *) Pin_10__SIO_CFG)
    #define Pin_10_SIO_DIFF           (* (reg8 *) Pin_10__SIO_DIFF)
#endif /* (Pin_10__SIO_CFG) */

/* Interrupt Registers */
#if defined(Pin_10__INTSTAT)
    #define Pin_10_INTSTAT            (* (reg8 *) Pin_10__INTSTAT)
    #define Pin_10_SNAP               (* (reg8 *) Pin_10__SNAP)
    
	#define Pin_10_0_INTTYPE_REG 		(* (reg8 *) Pin_10__0__INTTYPE)
	#define Pin_10_1_INTTYPE_REG 		(* (reg8 *) Pin_10__1__INTTYPE)
	#define Pin_10_2_INTTYPE_REG 		(* (reg8 *) Pin_10__2__INTTYPE)
	#define Pin_10_3_INTTYPE_REG 		(* (reg8 *) Pin_10__3__INTTYPE)
	#define Pin_10_4_INTTYPE_REG 		(* (reg8 *) Pin_10__4__INTTYPE)
	#define Pin_10_5_INTTYPE_REG 		(* (reg8 *) Pin_10__5__INTTYPE)
	#define Pin_10_6_INTTYPE_REG 		(* (reg8 *) Pin_10__6__INTTYPE)
	#define Pin_10_7_INTTYPE_REG 		(* (reg8 *) Pin_10__7__INTTYPE)
#endif /* (Pin_10__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Pin_10_H */


/* [] END OF FILE */
