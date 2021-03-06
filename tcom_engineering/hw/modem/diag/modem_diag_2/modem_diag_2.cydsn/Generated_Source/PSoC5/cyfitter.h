/*******************************************************************************
* File Name: cyfitter.h
* 
* PSoC Creator  4.2
*
* Description:
* 
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2018 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include "cydevice.h"
#include "cydevice_trm.h"

/* CTS */
#define CTS__0__INTTYPE CYREG_PICU0_INTTYPE3
#define CTS__0__MASK 0x08u
#define CTS__0__PC CYREG_PRT0_PC3
#define CTS__0__PORT 0u
#define CTS__0__SHIFT 3u
#define CTS__AG CYREG_PRT0_AG
#define CTS__AMUX CYREG_PRT0_AMUX
#define CTS__BIE CYREG_PRT0_BIE
#define CTS__BIT_MASK CYREG_PRT0_BIT_MASK
#define CTS__BYP CYREG_PRT0_BYP
#define CTS__CTL CYREG_PRT0_CTL
#define CTS__DM0 CYREG_PRT0_DM0
#define CTS__DM1 CYREG_PRT0_DM1
#define CTS__DM2 CYREG_PRT0_DM2
#define CTS__DR CYREG_PRT0_DR
#define CTS__INP_DIS CYREG_PRT0_INP_DIS
#define CTS__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU0_BASE
#define CTS__LCD_COM_SEG CYREG_PRT0_LCD_COM_SEG
#define CTS__LCD_EN CYREG_PRT0_LCD_EN
#define CTS__MASK 0x08u
#define CTS__PORT 0u
#define CTS__PRT CYREG_PRT0_PRT
#define CTS__PRTDSI__CAPS_SEL CYREG_PRT0_CAPS_SEL
#define CTS__PRTDSI__DBL_SYNC_IN CYREG_PRT0_DBL_SYNC_IN
#define CTS__PRTDSI__OE_SEL0 CYREG_PRT0_OE_SEL0
#define CTS__PRTDSI__OE_SEL1 CYREG_PRT0_OE_SEL1
#define CTS__PRTDSI__OUT_SEL0 CYREG_PRT0_OUT_SEL0
#define CTS__PRTDSI__OUT_SEL1 CYREG_PRT0_OUT_SEL1
#define CTS__PRTDSI__SYNC_OUT CYREG_PRT0_SYNC_OUT
#define CTS__PS CYREG_PRT0_PS
#define CTS__SHIFT 3u
#define CTS__SLW CYREG_PRT0_SLW

/* DSR */
#define DSR__0__INTTYPE CYREG_PICU0_INTTYPE5
#define DSR__0__MASK 0x20u
#define DSR__0__PC CYREG_PRT0_PC5
#define DSR__0__PORT 0u
#define DSR__0__SHIFT 5u
#define DSR__AG CYREG_PRT0_AG
#define DSR__AMUX CYREG_PRT0_AMUX
#define DSR__BIE CYREG_PRT0_BIE
#define DSR__BIT_MASK CYREG_PRT0_BIT_MASK
#define DSR__BYP CYREG_PRT0_BYP
#define DSR__CTL CYREG_PRT0_CTL
#define DSR__DM0 CYREG_PRT0_DM0
#define DSR__DM1 CYREG_PRT0_DM1
#define DSR__DM2 CYREG_PRT0_DM2
#define DSR__DR CYREG_PRT0_DR
#define DSR__INP_DIS CYREG_PRT0_INP_DIS
#define DSR__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU0_BASE
#define DSR__LCD_COM_SEG CYREG_PRT0_LCD_COM_SEG
#define DSR__LCD_EN CYREG_PRT0_LCD_EN
#define DSR__MASK 0x20u
#define DSR__PORT 0u
#define DSR__PRT CYREG_PRT0_PRT
#define DSR__PRTDSI__CAPS_SEL CYREG_PRT0_CAPS_SEL
#define DSR__PRTDSI__DBL_SYNC_IN CYREG_PRT0_DBL_SYNC_IN
#define DSR__PRTDSI__OE_SEL0 CYREG_PRT0_OE_SEL0
#define DSR__PRTDSI__OE_SEL1 CYREG_PRT0_OE_SEL1
#define DSR__PRTDSI__OUT_SEL0 CYREG_PRT0_OUT_SEL0
#define DSR__PRTDSI__OUT_SEL1 CYREG_PRT0_OUT_SEL1
#define DSR__PRTDSI__SYNC_OUT CYREG_PRT0_SYNC_OUT
#define DSR__PS CYREG_PRT0_PS
#define DSR__SHIFT 5u
#define DSR__SLW CYREG_PRT0_SLW

/* DTR */
#define DTR__0__INTTYPE CYREG_PICU0_INTTYPE4
#define DTR__0__MASK 0x10u
#define DTR__0__PC CYREG_PRT0_PC4
#define DTR__0__PORT 0u
#define DTR__0__SHIFT 4u
#define DTR__AG CYREG_PRT0_AG
#define DTR__AMUX CYREG_PRT0_AMUX
#define DTR__BIE CYREG_PRT0_BIE
#define DTR__BIT_MASK CYREG_PRT0_BIT_MASK
#define DTR__BYP CYREG_PRT0_BYP
#define DTR__CTL CYREG_PRT0_CTL
#define DTR__DM0 CYREG_PRT0_DM0
#define DTR__DM1 CYREG_PRT0_DM1
#define DTR__DM2 CYREG_PRT0_DM2
#define DTR__DR CYREG_PRT0_DR
#define DTR__INP_DIS CYREG_PRT0_INP_DIS
#define DTR__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU0_BASE
#define DTR__LCD_COM_SEG CYREG_PRT0_LCD_COM_SEG
#define DTR__LCD_EN CYREG_PRT0_LCD_EN
#define DTR__MASK 0x10u
#define DTR__PORT 0u
#define DTR__PRT CYREG_PRT0_PRT
#define DTR__PRTDSI__CAPS_SEL CYREG_PRT0_CAPS_SEL
#define DTR__PRTDSI__DBL_SYNC_IN CYREG_PRT0_DBL_SYNC_IN
#define DTR__PRTDSI__OE_SEL0 CYREG_PRT0_OE_SEL0
#define DTR__PRTDSI__OE_SEL1 CYREG_PRT0_OE_SEL1
#define DTR__PRTDSI__OUT_SEL0 CYREG_PRT0_OUT_SEL0
#define DTR__PRTDSI__OUT_SEL1 CYREG_PRT0_OUT_SEL1
#define DTR__PRTDSI__SYNC_OUT CYREG_PRT0_SYNC_OUT
#define DTR__PS CYREG_PRT0_PS
#define DTR__SHIFT 4u
#define DTR__SLW CYREG_PRT0_SLW

/* LCD */
#define LCD_LCDPort__0__INTTYPE CYREG_PICU2_INTTYPE0
#define LCD_LCDPort__0__MASK 0x01u
#define LCD_LCDPort__0__PC CYREG_PRT2_PC0
#define LCD_LCDPort__0__PORT 2u
#define LCD_LCDPort__0__SHIFT 0u
#define LCD_LCDPort__1__INTTYPE CYREG_PICU2_INTTYPE1
#define LCD_LCDPort__1__MASK 0x02u
#define LCD_LCDPort__1__PC CYREG_PRT2_PC1
#define LCD_LCDPort__1__PORT 2u
#define LCD_LCDPort__1__SHIFT 1u
#define LCD_LCDPort__2__INTTYPE CYREG_PICU2_INTTYPE2
#define LCD_LCDPort__2__MASK 0x04u
#define LCD_LCDPort__2__PC CYREG_PRT2_PC2
#define LCD_LCDPort__2__PORT 2u
#define LCD_LCDPort__2__SHIFT 2u
#define LCD_LCDPort__3__INTTYPE CYREG_PICU2_INTTYPE3
#define LCD_LCDPort__3__MASK 0x08u
#define LCD_LCDPort__3__PC CYREG_PRT2_PC3
#define LCD_LCDPort__3__PORT 2u
#define LCD_LCDPort__3__SHIFT 3u
#define LCD_LCDPort__4__INTTYPE CYREG_PICU2_INTTYPE4
#define LCD_LCDPort__4__MASK 0x10u
#define LCD_LCDPort__4__PC CYREG_PRT2_PC4
#define LCD_LCDPort__4__PORT 2u
#define LCD_LCDPort__4__SHIFT 4u
#define LCD_LCDPort__5__INTTYPE CYREG_PICU2_INTTYPE5
#define LCD_LCDPort__5__MASK 0x20u
#define LCD_LCDPort__5__PC CYREG_PRT2_PC5
#define LCD_LCDPort__5__PORT 2u
#define LCD_LCDPort__5__SHIFT 5u
#define LCD_LCDPort__6__INTTYPE CYREG_PICU2_INTTYPE6
#define LCD_LCDPort__6__MASK 0x40u
#define LCD_LCDPort__6__PC CYREG_PRT2_PC6
#define LCD_LCDPort__6__PORT 2u
#define LCD_LCDPort__6__SHIFT 6u
#define LCD_LCDPort__AG CYREG_PRT2_AG
#define LCD_LCDPort__AMUX CYREG_PRT2_AMUX
#define LCD_LCDPort__BIE CYREG_PRT2_BIE
#define LCD_LCDPort__BIT_MASK CYREG_PRT2_BIT_MASK
#define LCD_LCDPort__BYP CYREG_PRT2_BYP
#define LCD_LCDPort__CTL CYREG_PRT2_CTL
#define LCD_LCDPort__DM0 CYREG_PRT2_DM0
#define LCD_LCDPort__DM1 CYREG_PRT2_DM1
#define LCD_LCDPort__DM2 CYREG_PRT2_DM2
#define LCD_LCDPort__DR CYREG_PRT2_DR
#define LCD_LCDPort__INP_DIS CYREG_PRT2_INP_DIS
#define LCD_LCDPort__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define LCD_LCDPort__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define LCD_LCDPort__LCD_EN CYREG_PRT2_LCD_EN
#define LCD_LCDPort__MASK 0x7Fu
#define LCD_LCDPort__PORT 2u
#define LCD_LCDPort__PRT CYREG_PRT2_PRT
#define LCD_LCDPort__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define LCD_LCDPort__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define LCD_LCDPort__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define LCD_LCDPort__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define LCD_LCDPort__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define LCD_LCDPort__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define LCD_LCDPort__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define LCD_LCDPort__PS CYREG_PRT2_PS
#define LCD_LCDPort__SHIFT 0u
#define LCD_LCDPort__SLW CYREG_PRT2_SLW

/* RTS */
#define RTS__0__INTTYPE CYREG_PICU0_INTTYPE2
#define RTS__0__MASK 0x04u
#define RTS__0__PC CYREG_PRT0_PC2
#define RTS__0__PORT 0u
#define RTS__0__SHIFT 2u
#define RTS__AG CYREG_PRT0_AG
#define RTS__AMUX CYREG_PRT0_AMUX
#define RTS__BIE CYREG_PRT0_BIE
#define RTS__BIT_MASK CYREG_PRT0_BIT_MASK
#define RTS__BYP CYREG_PRT0_BYP
#define RTS__CTL CYREG_PRT0_CTL
#define RTS__DM0 CYREG_PRT0_DM0
#define RTS__DM1 CYREG_PRT0_DM1
#define RTS__DM2 CYREG_PRT0_DM2
#define RTS__DR CYREG_PRT0_DR
#define RTS__INP_DIS CYREG_PRT0_INP_DIS
#define RTS__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU0_BASE
#define RTS__LCD_COM_SEG CYREG_PRT0_LCD_COM_SEG
#define RTS__LCD_EN CYREG_PRT0_LCD_EN
#define RTS__MASK 0x04u
#define RTS__PORT 0u
#define RTS__PRT CYREG_PRT0_PRT
#define RTS__PRTDSI__CAPS_SEL CYREG_PRT0_CAPS_SEL
#define RTS__PRTDSI__DBL_SYNC_IN CYREG_PRT0_DBL_SYNC_IN
#define RTS__PRTDSI__OE_SEL0 CYREG_PRT0_OE_SEL0
#define RTS__PRTDSI__OE_SEL1 CYREG_PRT0_OE_SEL1
#define RTS__PRTDSI__OUT_SEL0 CYREG_PRT0_OUT_SEL0
#define RTS__PRTDSI__OUT_SEL1 CYREG_PRT0_OUT_SEL1
#define RTS__PRTDSI__SYNC_OUT CYREG_PRT0_SYNC_OUT
#define RTS__PS CYREG_PRT0_PS
#define RTS__SHIFT 2u
#define RTS__SLW CYREG_PRT0_SLW

/* RXD */
#define RXD__0__INTTYPE CYREG_PICU0_INTTYPE1
#define RXD__0__MASK 0x02u
#define RXD__0__PC CYREG_PRT0_PC1
#define RXD__0__PORT 0u
#define RXD__0__SHIFT 1u
#define RXD__AG CYREG_PRT0_AG
#define RXD__AMUX CYREG_PRT0_AMUX
#define RXD__BIE CYREG_PRT0_BIE
#define RXD__BIT_MASK CYREG_PRT0_BIT_MASK
#define RXD__BYP CYREG_PRT0_BYP
#define RXD__CTL CYREG_PRT0_CTL
#define RXD__DM0 CYREG_PRT0_DM0
#define RXD__DM1 CYREG_PRT0_DM1
#define RXD__DM2 CYREG_PRT0_DM2
#define RXD__DR CYREG_PRT0_DR
#define RXD__INP_DIS CYREG_PRT0_INP_DIS
#define RXD__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU0_BASE
#define RXD__LCD_COM_SEG CYREG_PRT0_LCD_COM_SEG
#define RXD__LCD_EN CYREG_PRT0_LCD_EN
#define RXD__MASK 0x02u
#define RXD__PORT 0u
#define RXD__PRT CYREG_PRT0_PRT
#define RXD__PRTDSI__CAPS_SEL CYREG_PRT0_CAPS_SEL
#define RXD__PRTDSI__DBL_SYNC_IN CYREG_PRT0_DBL_SYNC_IN
#define RXD__PRTDSI__OE_SEL0 CYREG_PRT0_OE_SEL0
#define RXD__PRTDSI__OE_SEL1 CYREG_PRT0_OE_SEL1
#define RXD__PRTDSI__OUT_SEL0 CYREG_PRT0_OUT_SEL0
#define RXD__PRTDSI__OUT_SEL1 CYREG_PRT0_OUT_SEL1
#define RXD__PRTDSI__SYNC_OUT CYREG_PRT0_SYNC_OUT
#define RXD__PS CYREG_PRT0_PS
#define RXD__SHIFT 1u
#define RXD__SLW CYREG_PRT0_SLW

/* TXD */
#define TXD__0__INTTYPE CYREG_PICU0_INTTYPE0
#define TXD__0__MASK 0x01u
#define TXD__0__PC CYREG_PRT0_PC0
#define TXD__0__PORT 0u
#define TXD__0__SHIFT 0u
#define TXD__AG CYREG_PRT0_AG
#define TXD__AMUX CYREG_PRT0_AMUX
#define TXD__BIE CYREG_PRT0_BIE
#define TXD__BIT_MASK CYREG_PRT0_BIT_MASK
#define TXD__BYP CYREG_PRT0_BYP
#define TXD__CTL CYREG_PRT0_CTL
#define TXD__DM0 CYREG_PRT0_DM0
#define TXD__DM1 CYREG_PRT0_DM1
#define TXD__DM2 CYREG_PRT0_DM2
#define TXD__DR CYREG_PRT0_DR
#define TXD__INP_DIS CYREG_PRT0_INP_DIS
#define TXD__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU0_BASE
#define TXD__LCD_COM_SEG CYREG_PRT0_LCD_COM_SEG
#define TXD__LCD_EN CYREG_PRT0_LCD_EN
#define TXD__MASK 0x01u
#define TXD__PORT 0u
#define TXD__PRT CYREG_PRT0_PRT
#define TXD__PRTDSI__CAPS_SEL CYREG_PRT0_CAPS_SEL
#define TXD__PRTDSI__DBL_SYNC_IN CYREG_PRT0_DBL_SYNC_IN
#define TXD__PRTDSI__OE_SEL0 CYREG_PRT0_OE_SEL0
#define TXD__PRTDSI__OE_SEL1 CYREG_PRT0_OE_SEL1
#define TXD__PRTDSI__OUT_SEL0 CYREG_PRT0_OUT_SEL0
#define TXD__PRTDSI__OUT_SEL1 CYREG_PRT0_OUT_SEL1
#define TXD__PRTDSI__SYNC_OUT CYREG_PRT0_SYNC_OUT
#define TXD__PS CYREG_PRT0_PS
#define TXD__SHIFT 0u
#define TXD__SLW CYREG_PRT0_SLW

/* UART */
#define UART_BUART_sRX_RxBitCounter__16BIT_CONTROL_AUX_CTL_REG CYREG_B0_UDB03_04_ACTL
#define UART_BUART_sRX_RxBitCounter__16BIT_CONTROL_CONTROL_REG CYREG_B0_UDB03_04_CTL
#define UART_BUART_sRX_RxBitCounter__16BIT_CONTROL_COUNT_REG CYREG_B0_UDB03_04_CTL
#define UART_BUART_sRX_RxBitCounter__16BIT_COUNT_CONTROL_REG CYREG_B0_UDB03_04_CTL
#define UART_BUART_sRX_RxBitCounter__16BIT_COUNT_COUNT_REG CYREG_B0_UDB03_04_CTL
#define UART_BUART_sRX_RxBitCounter__16BIT_MASK_MASK_REG CYREG_B0_UDB03_04_MSK
#define UART_BUART_sRX_RxBitCounter__16BIT_MASK_PERIOD_REG CYREG_B0_UDB03_04_MSK
#define UART_BUART_sRX_RxBitCounter__16BIT_PERIOD_MASK_REG CYREG_B0_UDB03_04_MSK
#define UART_BUART_sRX_RxBitCounter__16BIT_PERIOD_PERIOD_REG CYREG_B0_UDB03_04_MSK
#define UART_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG CYREG_B0_UDB03_ACTL
#define UART_BUART_sRX_RxBitCounter__CONTROL_REG CYREG_B0_UDB03_CTL
#define UART_BUART_sRX_RxBitCounter__CONTROL_ST_REG CYREG_B0_UDB03_ST_CTL
#define UART_BUART_sRX_RxBitCounter__COUNT_REG CYREG_B0_UDB03_CTL
#define UART_BUART_sRX_RxBitCounter__COUNT_ST_REG CYREG_B0_UDB03_ST_CTL
#define UART_BUART_sRX_RxBitCounter__MASK_CTL_AUX_CTL_REG CYREG_B0_UDB03_MSK_ACTL
#define UART_BUART_sRX_RxBitCounter__PER_CTL_AUX_CTL_REG CYREG_B0_UDB03_MSK_ACTL
#define UART_BUART_sRX_RxBitCounter__PERIOD_REG CYREG_B0_UDB03_MSK
#define UART_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB03_04_ACTL
#define UART_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_REG CYREG_B0_UDB03_04_ST
#define UART_BUART_sRX_RxBitCounter_ST__MASK_REG CYREG_B0_UDB03_MSK
#define UART_BUART_sRX_RxBitCounter_ST__MASK_ST_AUX_CTL_REG CYREG_B0_UDB03_MSK_ACTL
#define UART_BUART_sRX_RxBitCounter_ST__PER_ST_AUX_CTL_REG CYREG_B0_UDB03_MSK_ACTL
#define UART_BUART_sRX_RxBitCounter_ST__STATUS_AUX_CTL_REG CYREG_B0_UDB03_ACTL
#define UART_BUART_sRX_RxBitCounter_ST__STATUS_CNT_REG CYREG_B0_UDB03_ST_CTL
#define UART_BUART_sRX_RxBitCounter_ST__STATUS_CONTROL_REG CYREG_B0_UDB03_ST_CTL
#define UART_BUART_sRX_RxBitCounter_ST__STATUS_REG CYREG_B0_UDB03_ST
#define UART_BUART_sRX_RxShifter_u0__16BIT_A0_REG CYREG_B0_UDB00_01_A0
#define UART_BUART_sRX_RxShifter_u0__16BIT_A1_REG CYREG_B0_UDB00_01_A1
#define UART_BUART_sRX_RxShifter_u0__16BIT_D0_REG CYREG_B0_UDB00_01_D0
#define UART_BUART_sRX_RxShifter_u0__16BIT_D1_REG CYREG_B0_UDB00_01_D1
#define UART_BUART_sRX_RxShifter_u0__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB00_01_ACTL
#define UART_BUART_sRX_RxShifter_u0__16BIT_F0_REG CYREG_B0_UDB00_01_F0
#define UART_BUART_sRX_RxShifter_u0__16BIT_F1_REG CYREG_B0_UDB00_01_F1
#define UART_BUART_sRX_RxShifter_u0__A0_A1_REG CYREG_B0_UDB00_A0_A1
#define UART_BUART_sRX_RxShifter_u0__A0_REG CYREG_B0_UDB00_A0
#define UART_BUART_sRX_RxShifter_u0__A1_REG CYREG_B0_UDB00_A1
#define UART_BUART_sRX_RxShifter_u0__D0_D1_REG CYREG_B0_UDB00_D0_D1
#define UART_BUART_sRX_RxShifter_u0__D0_REG CYREG_B0_UDB00_D0
#define UART_BUART_sRX_RxShifter_u0__D1_REG CYREG_B0_UDB00_D1
#define UART_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG CYREG_B0_UDB00_ACTL
#define UART_BUART_sRX_RxShifter_u0__F0_F1_REG CYREG_B0_UDB00_F0_F1
#define UART_BUART_sRX_RxShifter_u0__F0_REG CYREG_B0_UDB00_F0
#define UART_BUART_sRX_RxShifter_u0__F1_REG CYREG_B0_UDB00_F1
#define UART_BUART_sRX_RxSts__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB02_03_ACTL
#define UART_BUART_sRX_RxSts__16BIT_STATUS_REG CYREG_B0_UDB02_03_ST
#define UART_BUART_sRX_RxSts__3__MASK 0x08u
#define UART_BUART_sRX_RxSts__3__POS 3
#define UART_BUART_sRX_RxSts__4__MASK 0x10u
#define UART_BUART_sRX_RxSts__4__POS 4
#define UART_BUART_sRX_RxSts__5__MASK 0x20u
#define UART_BUART_sRX_RxSts__5__POS 5
#define UART_BUART_sRX_RxSts__MASK 0x38u
#define UART_BUART_sRX_RxSts__MASK_REG CYREG_B0_UDB02_MSK
#define UART_BUART_sRX_RxSts__STATUS_AUX_CTL_REG CYREG_B0_UDB02_ACTL
#define UART_BUART_sRX_RxSts__STATUS_REG CYREG_B0_UDB02_ST
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A0_REG CYREG_B0_UDB01_02_A0
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A1_REG CYREG_B0_UDB01_02_A1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D0_REG CYREG_B0_UDB01_02_D0
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D1_REG CYREG_B0_UDB01_02_D1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB01_02_ACTL
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F0_REG CYREG_B0_UDB01_02_F0
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F1_REG CYREG_B0_UDB01_02_F1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__A0_A1_REG CYREG_B0_UDB01_A0_A1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__A0_REG CYREG_B0_UDB01_A0
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__A1_REG CYREG_B0_UDB01_A1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__D0_D1_REG CYREG_B0_UDB01_D0_D1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG CYREG_B0_UDB01_D0
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG CYREG_B0_UDB01_D1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__DP_AUX_CTL_REG CYREG_B0_UDB01_ACTL
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__F0_F1_REG CYREG_B0_UDB01_F0_F1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__F0_REG CYREG_B0_UDB01_F0
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__F1_REG CYREG_B0_UDB01_F1
#define UART_BUART_sTX_TxShifter_u0__16BIT_A0_REG CYREG_B0_UDB04_05_A0
#define UART_BUART_sTX_TxShifter_u0__16BIT_A1_REG CYREG_B0_UDB04_05_A1
#define UART_BUART_sTX_TxShifter_u0__16BIT_D0_REG CYREG_B0_UDB04_05_D0
#define UART_BUART_sTX_TxShifter_u0__16BIT_D1_REG CYREG_B0_UDB04_05_D1
#define UART_BUART_sTX_TxShifter_u0__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB04_05_ACTL
#define UART_BUART_sTX_TxShifter_u0__16BIT_F0_REG CYREG_B0_UDB04_05_F0
#define UART_BUART_sTX_TxShifter_u0__16BIT_F1_REG CYREG_B0_UDB04_05_F1
#define UART_BUART_sTX_TxShifter_u0__A0_A1_REG CYREG_B0_UDB04_A0_A1
#define UART_BUART_sTX_TxShifter_u0__A0_REG CYREG_B0_UDB04_A0
#define UART_BUART_sTX_TxShifter_u0__A1_REG CYREG_B0_UDB04_A1
#define UART_BUART_sTX_TxShifter_u0__D0_D1_REG CYREG_B0_UDB04_D0_D1
#define UART_BUART_sTX_TxShifter_u0__D0_REG CYREG_B0_UDB04_D0
#define UART_BUART_sTX_TxShifter_u0__D1_REG CYREG_B0_UDB04_D1
#define UART_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG CYREG_B0_UDB04_ACTL
#define UART_BUART_sTX_TxShifter_u0__F0_F1_REG CYREG_B0_UDB04_F0_F1
#define UART_BUART_sTX_TxShifter_u0__F0_REG CYREG_B0_UDB04_F0
#define UART_BUART_sTX_TxShifter_u0__F1_REG CYREG_B0_UDB04_F1
#define UART_BUART_sTX_TxSts__0__MASK 0x01u
#define UART_BUART_sTX_TxSts__0__POS 0
#define UART_BUART_sTX_TxSts__1__MASK 0x02u
#define UART_BUART_sTX_TxSts__1__POS 1
#define UART_BUART_sTX_TxSts__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB01_02_ACTL
#define UART_BUART_sTX_TxSts__16BIT_STATUS_REG CYREG_B0_UDB01_02_ST
#define UART_BUART_sTX_TxSts__2__MASK 0x04u
#define UART_BUART_sTX_TxSts__2__POS 2
#define UART_BUART_sTX_TxSts__3__MASK 0x08u
#define UART_BUART_sTX_TxSts__3__POS 3
#define UART_BUART_sTX_TxSts__MASK 0x0Fu
#define UART_BUART_sTX_TxSts__MASK_REG CYREG_B0_UDB01_MSK
#define UART_BUART_sTX_TxSts__STATUS_AUX_CTL_REG CYREG_B0_UDB01_ACTL
#define UART_BUART_sTX_TxSts__STATUS_REG CYREG_B0_UDB01_ST
#define UART_DEBUG_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A0_REG CYREG_B0_UDB02_03_A0
#define UART_DEBUG_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A1_REG CYREG_B0_UDB02_03_A1
#define UART_DEBUG_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D0_REG CYREG_B0_UDB02_03_D0
#define UART_DEBUG_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D1_REG CYREG_B0_UDB02_03_D1
#define UART_DEBUG_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB02_03_ACTL
#define UART_DEBUG_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F0_REG CYREG_B0_UDB02_03_F0
#define UART_DEBUG_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F1_REG CYREG_B0_UDB02_03_F1
#define UART_DEBUG_BUART_sTX_sCLOCK_TxBitClkGen__A0_A1_REG CYREG_B0_UDB02_A0_A1
#define UART_DEBUG_BUART_sTX_sCLOCK_TxBitClkGen__A0_REG CYREG_B0_UDB02_A0
#define UART_DEBUG_BUART_sTX_sCLOCK_TxBitClkGen__A1_REG CYREG_B0_UDB02_A1
#define UART_DEBUG_BUART_sTX_sCLOCK_TxBitClkGen__D0_D1_REG CYREG_B0_UDB02_D0_D1
#define UART_DEBUG_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG CYREG_B0_UDB02_D0
#define UART_DEBUG_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG CYREG_B0_UDB02_D1
#define UART_DEBUG_BUART_sTX_sCLOCK_TxBitClkGen__DP_AUX_CTL_REG CYREG_B0_UDB02_ACTL
#define UART_DEBUG_BUART_sTX_sCLOCK_TxBitClkGen__F0_F1_REG CYREG_B0_UDB02_F0_F1
#define UART_DEBUG_BUART_sTX_sCLOCK_TxBitClkGen__F0_REG CYREG_B0_UDB02_F0
#define UART_DEBUG_BUART_sTX_sCLOCK_TxBitClkGen__F1_REG CYREG_B0_UDB02_F1
#define UART_DEBUG_BUART_sTX_TxShifter_u0__16BIT_A0_REG CYREG_B0_UDB05_06_A0
#define UART_DEBUG_BUART_sTX_TxShifter_u0__16BIT_A1_REG CYREG_B0_UDB05_06_A1
#define UART_DEBUG_BUART_sTX_TxShifter_u0__16BIT_D0_REG CYREG_B0_UDB05_06_D0
#define UART_DEBUG_BUART_sTX_TxShifter_u0__16BIT_D1_REG CYREG_B0_UDB05_06_D1
#define UART_DEBUG_BUART_sTX_TxShifter_u0__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB05_06_ACTL
#define UART_DEBUG_BUART_sTX_TxShifter_u0__16BIT_F0_REG CYREG_B0_UDB05_06_F0
#define UART_DEBUG_BUART_sTX_TxShifter_u0__16BIT_F1_REG CYREG_B0_UDB05_06_F1
#define UART_DEBUG_BUART_sTX_TxShifter_u0__A0_A1_REG CYREG_B0_UDB05_A0_A1
#define UART_DEBUG_BUART_sTX_TxShifter_u0__A0_REG CYREG_B0_UDB05_A0
#define UART_DEBUG_BUART_sTX_TxShifter_u0__A1_REG CYREG_B0_UDB05_A1
#define UART_DEBUG_BUART_sTX_TxShifter_u0__D0_D1_REG CYREG_B0_UDB05_D0_D1
#define UART_DEBUG_BUART_sTX_TxShifter_u0__D0_REG CYREG_B0_UDB05_D0
#define UART_DEBUG_BUART_sTX_TxShifter_u0__D1_REG CYREG_B0_UDB05_D1
#define UART_DEBUG_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG CYREG_B0_UDB05_ACTL
#define UART_DEBUG_BUART_sTX_TxShifter_u0__F0_F1_REG CYREG_B0_UDB05_F0_F1
#define UART_DEBUG_BUART_sTX_TxShifter_u0__F0_REG CYREG_B0_UDB05_F0
#define UART_DEBUG_BUART_sTX_TxShifter_u0__F1_REG CYREG_B0_UDB05_F1
#define UART_DEBUG_BUART_sTX_TxSts__0__MASK 0x01u
#define UART_DEBUG_BUART_sTX_TxSts__0__POS 0
#define UART_DEBUG_BUART_sTX_TxSts__1__MASK 0x02u
#define UART_DEBUG_BUART_sTX_TxSts__1__POS 1
#define UART_DEBUG_BUART_sTX_TxSts__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB05_06_ACTL
#define UART_DEBUG_BUART_sTX_TxSts__16BIT_STATUS_REG CYREG_B0_UDB05_06_ST
#define UART_DEBUG_BUART_sTX_TxSts__2__MASK 0x04u
#define UART_DEBUG_BUART_sTX_TxSts__2__POS 2
#define UART_DEBUG_BUART_sTX_TxSts__3__MASK 0x08u
#define UART_DEBUG_BUART_sTX_TxSts__3__POS 3
#define UART_DEBUG_BUART_sTX_TxSts__MASK 0x0Fu
#define UART_DEBUG_BUART_sTX_TxSts__MASK_REG CYREG_B0_UDB05_MSK
#define UART_DEBUG_BUART_sTX_TxSts__STATUS_AUX_CTL_REG CYREG_B0_UDB05_ACTL
#define UART_DEBUG_BUART_sTX_TxSts__STATUS_REG CYREG_B0_UDB05_ST
#define UART_DEBUG_IntClock__CFG0 CYREG_CLKDIST_DCFG1_CFG0
#define UART_DEBUG_IntClock__CFG1 CYREG_CLKDIST_DCFG1_CFG1
#define UART_DEBUG_IntClock__CFG2 CYREG_CLKDIST_DCFG1_CFG2
#define UART_DEBUG_IntClock__CFG2_SRC_SEL_MASK 0x07u
#define UART_DEBUG_IntClock__INDEX 0x01u
#define UART_DEBUG_IntClock__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define UART_DEBUG_IntClock__PM_ACT_MSK 0x02u
#define UART_DEBUG_IntClock__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define UART_DEBUG_IntClock__PM_STBY_MSK 0x02u
#define UART_IntClock__CFG0 CYREG_CLKDIST_DCFG0_CFG0
#define UART_IntClock__CFG1 CYREG_CLKDIST_DCFG0_CFG1
#define UART_IntClock__CFG2 CYREG_CLKDIST_DCFG0_CFG2
#define UART_IntClock__CFG2_SRC_SEL_MASK 0x07u
#define UART_IntClock__INDEX 0x00u
#define UART_IntClock__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define UART_IntClock__PM_ACT_MSK 0x01u
#define UART_IntClock__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define UART_IntClock__PM_STBY_MSK 0x01u
#define UART_RXInternalInterrupt__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define UART_RXInternalInterrupt__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define UART_RXInternalInterrupt__INTC_MASK 0x01u
#define UART_RXInternalInterrupt__INTC_NUMBER 0u
#define UART_RXInternalInterrupt__INTC_PRIOR_NUM 7u
#define UART_RXInternalInterrupt__INTC_PRIOR_REG CYREG_NVIC_PRI_0
#define UART_RXInternalInterrupt__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define UART_RXInternalInterrupt__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* SIM_DET */
#define SIM_DET__0__INTTYPE CYREG_PICU0_INTTYPE6
#define SIM_DET__0__MASK 0x40u
#define SIM_DET__0__PC CYREG_PRT0_PC6
#define SIM_DET__0__PORT 0u
#define SIM_DET__0__SHIFT 6u
#define SIM_DET__AG CYREG_PRT0_AG
#define SIM_DET__AMUX CYREG_PRT0_AMUX
#define SIM_DET__BIE CYREG_PRT0_BIE
#define SIM_DET__BIT_MASK CYREG_PRT0_BIT_MASK
#define SIM_DET__BYP CYREG_PRT0_BYP
#define SIM_DET__CTL CYREG_PRT0_CTL
#define SIM_DET__DM0 CYREG_PRT0_DM0
#define SIM_DET__DM1 CYREG_PRT0_DM1
#define SIM_DET__DM2 CYREG_PRT0_DM2
#define SIM_DET__DR CYREG_PRT0_DR
#define SIM_DET__INP_DIS CYREG_PRT0_INP_DIS
#define SIM_DET__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU0_BASE
#define SIM_DET__LCD_COM_SEG CYREG_PRT0_LCD_COM_SEG
#define SIM_DET__LCD_EN CYREG_PRT0_LCD_EN
#define SIM_DET__MASK 0x40u
#define SIM_DET__PORT 0u
#define SIM_DET__PRT CYREG_PRT0_PRT
#define SIM_DET__PRTDSI__CAPS_SEL CYREG_PRT0_CAPS_SEL
#define SIM_DET__PRTDSI__DBL_SYNC_IN CYREG_PRT0_DBL_SYNC_IN
#define SIM_DET__PRTDSI__OE_SEL0 CYREG_PRT0_OE_SEL0
#define SIM_DET__PRTDSI__OE_SEL1 CYREG_PRT0_OE_SEL1
#define SIM_DET__PRTDSI__OUT_SEL0 CYREG_PRT0_OUT_SEL0
#define SIM_DET__PRTDSI__OUT_SEL1 CYREG_PRT0_OUT_SEL1
#define SIM_DET__PRTDSI__SYNC_OUT CYREG_PRT0_SYNC_OUT
#define SIM_DET__PS CYREG_PRT0_PS
#define SIM_DET__SHIFT 6u
#define SIM_DET__SLW CYREG_PRT0_SLW

/* TX_DEBUG */
#define TX_DEBUG__0__INTTYPE CYREG_PICU0_INTTYPE7
#define TX_DEBUG__0__MASK 0x80u
#define TX_DEBUG__0__PC CYREG_PRT0_PC7
#define TX_DEBUG__0__PORT 0u
#define TX_DEBUG__0__SHIFT 7u
#define TX_DEBUG__AG CYREG_PRT0_AG
#define TX_DEBUG__AMUX CYREG_PRT0_AMUX
#define TX_DEBUG__BIE CYREG_PRT0_BIE
#define TX_DEBUG__BIT_MASK CYREG_PRT0_BIT_MASK
#define TX_DEBUG__BYP CYREG_PRT0_BYP
#define TX_DEBUG__CTL CYREG_PRT0_CTL
#define TX_DEBUG__DM0 CYREG_PRT0_DM0
#define TX_DEBUG__DM1 CYREG_PRT0_DM1
#define TX_DEBUG__DM2 CYREG_PRT0_DM2
#define TX_DEBUG__DR CYREG_PRT0_DR
#define TX_DEBUG__INP_DIS CYREG_PRT0_INP_DIS
#define TX_DEBUG__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU0_BASE
#define TX_DEBUG__LCD_COM_SEG CYREG_PRT0_LCD_COM_SEG
#define TX_DEBUG__LCD_EN CYREG_PRT0_LCD_EN
#define TX_DEBUG__MASK 0x80u
#define TX_DEBUG__PORT 0u
#define TX_DEBUG__PRT CYREG_PRT0_PRT
#define TX_DEBUG__PRTDSI__CAPS_SEL CYREG_PRT0_CAPS_SEL
#define TX_DEBUG__PRTDSI__DBL_SYNC_IN CYREG_PRT0_DBL_SYNC_IN
#define TX_DEBUG__PRTDSI__OE_SEL0 CYREG_PRT0_OE_SEL0
#define TX_DEBUG__PRTDSI__OE_SEL1 CYREG_PRT0_OE_SEL1
#define TX_DEBUG__PRTDSI__OUT_SEL0 CYREG_PRT0_OUT_SEL0
#define TX_DEBUG__PRTDSI__OUT_SEL1 CYREG_PRT0_OUT_SEL1
#define TX_DEBUG__PRTDSI__SYNC_OUT CYREG_PRT0_SYNC_OUT
#define TX_DEBUG__PS CYREG_PRT0_PS
#define TX_DEBUG__SHIFT 7u
#define TX_DEBUG__SLW CYREG_PRT0_SLW

/* Miscellaneous */
#define BCLK__BUS_CLK__HZ 24000000U
#define BCLK__BUS_CLK__KHZ 24000U
#define BCLK__BUS_CLK__MHZ 24U
#define CY_PROJECT_NAME "modem_diag_2"
#define CY_VERSION "PSoC Creator  4.2"
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_PSOC4A 18u
#define CYDEV_CHIP_DIE_PSOC5LP 2u
#define CYDEV_CHIP_DIE_PSOC5TM 3u
#define CYDEV_CHIP_DIE_TMA4 4u
#define CYDEV_CHIP_DIE_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_FM0P 5u
#define CYDEV_CHIP_FAMILY_FM3 6u
#define CYDEV_CHIP_FAMILY_FM4 7u
#define CYDEV_CHIP_FAMILY_PSOC3 1u
#define CYDEV_CHIP_FAMILY_PSOC4 2u
#define CYDEV_CHIP_FAMILY_PSOC5 3u
#define CYDEV_CHIP_FAMILY_PSOC6 4u
#define CYDEV_CHIP_FAMILY_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC5
#define CYDEV_CHIP_JTAG_ID 0x2E123069u
#define CYDEV_CHIP_MEMBER_3A 1u
#define CYDEV_CHIP_MEMBER_4A 18u
#define CYDEV_CHIP_MEMBER_4D 13u
#define CYDEV_CHIP_MEMBER_4E 6u
#define CYDEV_CHIP_MEMBER_4F 19u
#define CYDEV_CHIP_MEMBER_4G 4u
#define CYDEV_CHIP_MEMBER_4H 17u
#define CYDEV_CHIP_MEMBER_4I 23u
#define CYDEV_CHIP_MEMBER_4J 14u
#define CYDEV_CHIP_MEMBER_4K 15u
#define CYDEV_CHIP_MEMBER_4L 22u
#define CYDEV_CHIP_MEMBER_4M 21u
#define CYDEV_CHIP_MEMBER_4N 10u
#define CYDEV_CHIP_MEMBER_4O 7u
#define CYDEV_CHIP_MEMBER_4P 20u
#define CYDEV_CHIP_MEMBER_4Q 12u
#define CYDEV_CHIP_MEMBER_4R 8u
#define CYDEV_CHIP_MEMBER_4S 11u
#define CYDEV_CHIP_MEMBER_4T 9u
#define CYDEV_CHIP_MEMBER_4U 5u
#define CYDEV_CHIP_MEMBER_4V 16u
#define CYDEV_CHIP_MEMBER_5A 3u
#define CYDEV_CHIP_MEMBER_5B 2u
#define CYDEV_CHIP_MEMBER_6A 24u
#define CYDEV_CHIP_MEMBER_FM3 28u
#define CYDEV_CHIP_MEMBER_FM4 29u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 25u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 26u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 27u
#define CYDEV_CHIP_MEMBER_UNKNOWN 0u
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_5B
#define CYDEV_CHIP_DIE_EXPECT CYDEV_CHIP_MEMBER_USED
#define CYDEV_CHIP_DIE_ACTUAL CYDEV_CHIP_DIE_EXPECT
#define CYDEV_CHIP_REV_LEOPARD_ES1 0u
#define CYDEV_CHIP_REV_LEOPARD_ES2 1u
#define CYDEV_CHIP_REV_LEOPARD_ES3 3u
#define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3u
#define CYDEV_CHIP_REV_PSOC4A_ES0 17u
#define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17u
#define CYDEV_CHIP_REV_PSOC5LP_ES0 0u
#define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES0 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES1 1u
#define CYDEV_CHIP_REV_PSOC5TM_PRODUCTION 1u
#define CYDEV_CHIP_REV_TMA4_ES 17u
#define CYDEV_CHIP_REV_TMA4_ES2 33u
#define CYDEV_CHIP_REV_TMA4_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_3A_ES1 0u
#define CYDEV_CHIP_REVISION_3A_ES2 1u
#define CYDEV_CHIP_REVISION_3A_ES3 3u
#define CYDEV_CHIP_REVISION_3A_PRODUCTION 3u
#define CYDEV_CHIP_REVISION_4A_ES0 17u
#define CYDEV_CHIP_REVISION_4A_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4D_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD 0u
#define CYDEV_CHIP_REVISION_4E_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0u
#define CYDEV_CHIP_REVISION_4G_ES 17u
#define CYDEV_CHIP_REVISION_4G_ES2 33u
#define CYDEV_CHIP_REVISION_4G_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4H_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4I_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4J_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4K_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4L_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4M_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4N_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4O_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4P_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4R_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4S_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4T_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4U_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4V_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_5A_ES0 0u
#define CYDEV_CHIP_REVISION_5A_ES1 1u
#define CYDEV_CHIP_REVISION_5A_PRODUCTION 1u
#define CYDEV_CHIP_REVISION_5B_ES0 0u
#define CYDEV_CHIP_REVISION_5B_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_6A_ES 17u
#define CYDEV_CHIP_REVISION_6A_NO_UDB 33u
#define CYDEV_CHIP_REVISION_6A_PRODUCTION 33u
#define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_5B_PRODUCTION
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REVISION_USED
#define CYDEV_CONFIG_FASTBOOT_ENABLED 1
#define CYDEV_CONFIG_UNUSED_IO_AllowButWarn 0
#define CYDEV_CONFIG_UNUSED_IO CYDEV_CONFIG_UNUSED_IO_AllowButWarn
#define CYDEV_CONFIG_UNUSED_IO_AllowWithInfo 1
#define CYDEV_CONFIG_UNUSED_IO_Disallowed 2
#define CYDEV_CONFIGURATION_COMPRESSED 1
#define CYDEV_CONFIGURATION_DMA 0
#define CYDEV_CONFIGURATION_ECC 1
#define CYDEV_CONFIGURATION_IMOENABLED CYDEV_CONFIG_FASTBOOT_ENABLED
#define CYDEV_CONFIGURATION_MODE_COMPRESSED 0
#define CYDEV_CONFIGURATION_MODE CYDEV_CONFIGURATION_MODE_COMPRESSED
#define CYDEV_CONFIGURATION_MODE_DMA 2
#define CYDEV_CONFIGURATION_MODE_UNCOMPRESSED 1
#define CYDEV_DEBUG_ENABLE_MASK 0x20u
#define CYDEV_DEBUG_ENABLE_REGISTER CYREG_MLOGIC_DEBUG
#define CYDEV_DEBUGGING_DPS_Disable 3
#define CYDEV_DEBUGGING_DPS_JTAG_4 1
#define CYDEV_DEBUGGING_DPS_JTAG_5 0
#define CYDEV_DEBUGGING_DPS_SWD 2
#define CYDEV_DEBUGGING_DPS_SWD_SWV 6
#define CYDEV_DEBUGGING_DPS CYDEV_DEBUGGING_DPS_SWD_SWV
#define CYDEV_DEBUGGING_ENABLE 1
#define CYDEV_DEBUGGING_XRES 0
#define CYDEV_DMA_CHANNELS_AVAILABLE 24u
#define CYDEV_ECC_ENABLE 0
#define CYDEV_HEAP_SIZE 0x4000
#define CYDEV_INSTRUCT_CACHE_ENABLED 1
#define CYDEV_INTR_RISING 0x00000001u
#define CYDEV_IS_EXPORTING_CODE 0
#define CYDEV_IS_IMPORTING_CODE 0
#define CYDEV_PROJ_TYPE 0
#define CYDEV_PROJ_TYPE_BOOTLOADER 1
#define CYDEV_PROJ_TYPE_LAUNCHER 5
#define CYDEV_PROJ_TYPE_LOADABLE 2
#define CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER 4
#define CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER 3
#define CYDEV_PROJ_TYPE_STANDARD 0
#define CYDEV_PROTECTION_ENABLE 0
#define CYDEV_STACK_SIZE 0x1000
#define CYDEV_USE_BUNDLED_CMSIS 1
#define CYDEV_VARIABLE_VDDA 0
#define CYDEV_VDDA 5.0
#define CYDEV_VDDA_MV 5000
#define CYDEV_VDDD 5.0
#define CYDEV_VDDD_MV 5000
#define CYDEV_VDDIO0 5.0
#define CYDEV_VDDIO0_MV 5000
#define CYDEV_VDDIO1 5.0
#define CYDEV_VDDIO1_MV 5000
#define CYDEV_VDDIO2 5.0
#define CYDEV_VDDIO2_MV 5000
#define CYDEV_VDDIO3 5.0
#define CYDEV_VDDIO3_MV 5000
#define CYDEV_VIO0 5.0
#define CYDEV_VIO0_MV 5000
#define CYDEV_VIO1 5.0
#define CYDEV_VIO1_MV 5000
#define CYDEV_VIO2 5.0
#define CYDEV_VIO2_MV 5000
#define CYDEV_VIO3 5.0
#define CYDEV_VIO3_MV 5000
#define CYIPBLOCK_ARM_CM3_VERSION 0
#define CYIPBLOCK_P3_ANAIF_VERSION 0
#define CYIPBLOCK_P3_CAN_VERSION 0
#define CYIPBLOCK_P3_CAPSENSE_VERSION 0
#define CYIPBLOCK_P3_COMP_VERSION 0
#define CYIPBLOCK_P3_DECIMATOR_VERSION 0
#define CYIPBLOCK_P3_DFB_VERSION 0
#define CYIPBLOCK_P3_DMA_VERSION 0
#define CYIPBLOCK_P3_DRQ_VERSION 0
#define CYIPBLOCK_P3_DSM_VERSION 0
#define CYIPBLOCK_P3_EMIF_VERSION 0
#define CYIPBLOCK_P3_I2C_VERSION 0
#define CYIPBLOCK_P3_LCD_VERSION 0
#define CYIPBLOCK_P3_LPF_VERSION 0
#define CYIPBLOCK_P3_OPAMP_VERSION 0
#define CYIPBLOCK_P3_PM_VERSION 0
#define CYIPBLOCK_P3_SCCT_VERSION 0
#define CYIPBLOCK_P3_TIMER_VERSION 0
#define CYIPBLOCK_P3_USB_VERSION 0
#define CYIPBLOCK_P3_VIDAC_VERSION 0
#define CYIPBLOCK_P3_VREF_VERSION 0
#define CYIPBLOCK_S8_GPIO_VERSION 0
#define CYIPBLOCK_S8_IRQ_VERSION 0
#define CYIPBLOCK_S8_SAR_VERSION 0
#define CYIPBLOCK_S8_SIO_VERSION 0
#define CYIPBLOCK_S8_UDB_VERSION 0
#define DMA_CHANNELS_USED__MASK0 0x00000000u
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */
