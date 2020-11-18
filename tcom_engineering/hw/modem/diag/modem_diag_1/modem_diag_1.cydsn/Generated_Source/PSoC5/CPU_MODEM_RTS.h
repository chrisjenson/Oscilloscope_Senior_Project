/*******************************************************************************
* File Name: CPU_MODEM_RTS.h  
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

#if !defined(CY_PINS_CPU_MODEM_RTS_H) /* Pins CPU_MODEM_RTS_H */
#define CY_PINS_CPU_MODEM_RTS_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "CPU_MODEM_RTS_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 CPU_MODEM_RTS__PORT == 15 && ((CPU_MODEM_RTS__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    CPU_MODEM_RTS_Write(uint8 value);
void    CPU_MODEM_RTS_SetDriveMode(uint8 mode);
uint8   CPU_MODEM_RTS_ReadDataReg(void);
uint8   CPU_MODEM_RTS_Read(void);
void    CPU_MODEM_RTS_SetInterruptMode(uint16 position, uint16 mode);
uint8   CPU_MODEM_RTS_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the CPU_MODEM_RTS_SetDriveMode() function.
     *  @{
     */
        #define CPU_MODEM_RTS_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define CPU_MODEM_RTS_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define CPU_MODEM_RTS_DM_RES_UP          PIN_DM_RES_UP
        #define CPU_MODEM_RTS_DM_RES_DWN         PIN_DM_RES_DWN
        #define CPU_MODEM_RTS_DM_OD_LO           PIN_DM_OD_LO
        #define CPU_MODEM_RTS_DM_OD_HI           PIN_DM_OD_HI
        #define CPU_MODEM_RTS_DM_STRONG          PIN_DM_STRONG
        #define CPU_MODEM_RTS_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define CPU_MODEM_RTS_MASK               CPU_MODEM_RTS__MASK
#define CPU_MODEM_RTS_SHIFT              CPU_MODEM_RTS__SHIFT
#define CPU_MODEM_RTS_WIDTH              1u

/* Interrupt constants */
#if defined(CPU_MODEM_RTS__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in CPU_MODEM_RTS_SetInterruptMode() function.
     *  @{
     */
        #define CPU_MODEM_RTS_INTR_NONE      (uint16)(0x0000u)
        #define CPU_MODEM_RTS_INTR_RISING    (uint16)(0x0001u)
        #define CPU_MODEM_RTS_INTR_FALLING   (uint16)(0x0002u)
        #define CPU_MODEM_RTS_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define CPU_MODEM_RTS_INTR_MASK      (0x01u) 
#endif /* (CPU_MODEM_RTS__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CPU_MODEM_RTS_PS                     (* (reg8 *) CPU_MODEM_RTS__PS)
/* Data Register */
#define CPU_MODEM_RTS_DR                     (* (reg8 *) CPU_MODEM_RTS__DR)
/* Port Number */
#define CPU_MODEM_RTS_PRT_NUM                (* (reg8 *) CPU_MODEM_RTS__PRT) 
/* Connect to Analog Globals */                                                  
#define CPU_MODEM_RTS_AG                     (* (reg8 *) CPU_MODEM_RTS__AG)                       
/* Analog MUX bux enable */
#define CPU_MODEM_RTS_AMUX                   (* (reg8 *) CPU_MODEM_RTS__AMUX) 
/* Bidirectional Enable */                                                        
#define CPU_MODEM_RTS_BIE                    (* (reg8 *) CPU_MODEM_RTS__BIE)
/* Bit-mask for Aliased Register Access */
#define CPU_MODEM_RTS_BIT_MASK               (* (reg8 *) CPU_MODEM_RTS__BIT_MASK)
/* Bypass Enable */
#define CPU_MODEM_RTS_BYP                    (* (reg8 *) CPU_MODEM_RTS__BYP)
/* Port wide control signals */                                                   
#define CPU_MODEM_RTS_CTL                    (* (reg8 *) CPU_MODEM_RTS__CTL)
/* Drive Modes */
#define CPU_MODEM_RTS_DM0                    (* (reg8 *) CPU_MODEM_RTS__DM0) 
#define CPU_MODEM_RTS_DM1                    (* (reg8 *) CPU_MODEM_RTS__DM1)
#define CPU_MODEM_RTS_DM2                    (* (reg8 *) CPU_MODEM_RTS__DM2) 
/* Input Buffer Disable Override */
#define CPU_MODEM_RTS_INP_DIS                (* (reg8 *) CPU_MODEM_RTS__INP_DIS)
/* LCD Common or Segment Drive */
#define CPU_MODEM_RTS_LCD_COM_SEG            (* (reg8 *) CPU_MODEM_RTS__LCD_COM_SEG)
/* Enable Segment LCD */
#define CPU_MODEM_RTS_LCD_EN                 (* (reg8 *) CPU_MODEM_RTS__LCD_EN)
/* Slew Rate Control */
#define CPU_MODEM_RTS_SLW                    (* (reg8 *) CPU_MODEM_RTS__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define CPU_MODEM_RTS_PRTDSI__CAPS_SEL       (* (reg8 *) CPU_MODEM_RTS__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define CPU_MODEM_RTS_PRTDSI__DBL_SYNC_IN    (* (reg8 *) CPU_MODEM_RTS__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define CPU_MODEM_RTS_PRTDSI__OE_SEL0        (* (reg8 *) CPU_MODEM_RTS__PRTDSI__OE_SEL0) 
#define CPU_MODEM_RTS_PRTDSI__OE_SEL1        (* (reg8 *) CPU_MODEM_RTS__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define CPU_MODEM_RTS_PRTDSI__OUT_SEL0       (* (reg8 *) CPU_MODEM_RTS__PRTDSI__OUT_SEL0) 
#define CPU_MODEM_RTS_PRTDSI__OUT_SEL1       (* (reg8 *) CPU_MODEM_RTS__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define CPU_MODEM_RTS_PRTDSI__SYNC_OUT       (* (reg8 *) CPU_MODEM_RTS__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(CPU_MODEM_RTS__SIO_CFG)
    #define CPU_MODEM_RTS_SIO_HYST_EN        (* (reg8 *) CPU_MODEM_RTS__SIO_HYST_EN)
    #define CPU_MODEM_RTS_SIO_REG_HIFREQ     (* (reg8 *) CPU_MODEM_RTS__SIO_REG_HIFREQ)
    #define CPU_MODEM_RTS_SIO_CFG            (* (reg8 *) CPU_MODEM_RTS__SIO_CFG)
    #define CPU_MODEM_RTS_SIO_DIFF           (* (reg8 *) CPU_MODEM_RTS__SIO_DIFF)
#endif /* (CPU_MODEM_RTS__SIO_CFG) */

/* Interrupt Registers */
#if defined(CPU_MODEM_RTS__INTSTAT)
    #define CPU_MODEM_RTS_INTSTAT            (* (reg8 *) CPU_MODEM_RTS__INTSTAT)
    #define CPU_MODEM_RTS_SNAP               (* (reg8 *) CPU_MODEM_RTS__SNAP)
    
	#define CPU_MODEM_RTS_0_INTTYPE_REG 		(* (reg8 *) CPU_MODEM_RTS__0__INTTYPE)
#endif /* (CPU_MODEM_RTS__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_CPU_MODEM_RTS_H */


/* [] END OF FILE */
