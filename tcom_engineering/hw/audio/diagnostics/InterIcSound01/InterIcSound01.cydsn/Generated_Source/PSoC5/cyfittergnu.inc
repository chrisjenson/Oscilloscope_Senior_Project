/*******************************************************************************
* File Name: cyfittergnu.inc
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

.ifndef INCLUDED_CYFITTERGNU_INC
.set INCLUDED_CYFITTERGNU_INC, 1
.include "cydevicegnu.inc"
.include "cydevicegnu_trm.inc"

/* WS */
.set WS__0__INTTYPE, CYREG_PICU3_INTTYPE2
.set WS__0__MASK, 0x04
.set WS__0__PC, CYREG_PRT3_PC2
.set WS__0__PORT, 3
.set WS__0__SHIFT, 2
.set WS__AG, CYREG_PRT3_AG
.set WS__AMUX, CYREG_PRT3_AMUX
.set WS__BIE, CYREG_PRT3_BIE
.set WS__BIT_MASK, CYREG_PRT3_BIT_MASK
.set WS__BYP, CYREG_PRT3_BYP
.set WS__CTL, CYREG_PRT3_CTL
.set WS__DM0, CYREG_PRT3_DM0
.set WS__DM1, CYREG_PRT3_DM1
.set WS__DM2, CYREG_PRT3_DM2
.set WS__DR, CYREG_PRT3_DR
.set WS__INP_DIS, CYREG_PRT3_INP_DIS
.set WS__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU3_BASE
.set WS__LCD_COM_SEG, CYREG_PRT3_LCD_COM_SEG
.set WS__LCD_EN, CYREG_PRT3_LCD_EN
.set WS__MASK, 0x04
.set WS__PORT, 3
.set WS__PRT, CYREG_PRT3_PRT
.set WS__PRTDSI__CAPS_SEL, CYREG_PRT3_CAPS_SEL
.set WS__PRTDSI__DBL_SYNC_IN, CYREG_PRT3_DBL_SYNC_IN
.set WS__PRTDSI__OE_SEL0, CYREG_PRT3_OE_SEL0
.set WS__PRTDSI__OE_SEL1, CYREG_PRT3_OE_SEL1
.set WS__PRTDSI__OUT_SEL0, CYREG_PRT3_OUT_SEL0
.set WS__PRTDSI__OUT_SEL1, CYREG_PRT3_OUT_SEL1
.set WS__PRTDSI__SYNC_OUT, CYREG_PRT3_SYNC_OUT
.set WS__PS, CYREG_PRT3_PS
.set WS__SHIFT, 2
.set WS__SLW, CYREG_PRT3_SLW

/* LCD */
.set LCD_LCDPort__0__INTTYPE, CYREG_PICU2_INTTYPE0
.set LCD_LCDPort__0__MASK, 0x01
.set LCD_LCDPort__0__PC, CYREG_PRT2_PC0
.set LCD_LCDPort__0__PORT, 2
.set LCD_LCDPort__0__SHIFT, 0
.set LCD_LCDPort__1__INTTYPE, CYREG_PICU2_INTTYPE1
.set LCD_LCDPort__1__MASK, 0x02
.set LCD_LCDPort__1__PC, CYREG_PRT2_PC1
.set LCD_LCDPort__1__PORT, 2
.set LCD_LCDPort__1__SHIFT, 1
.set LCD_LCDPort__2__INTTYPE, CYREG_PICU2_INTTYPE2
.set LCD_LCDPort__2__MASK, 0x04
.set LCD_LCDPort__2__PC, CYREG_PRT2_PC2
.set LCD_LCDPort__2__PORT, 2
.set LCD_LCDPort__2__SHIFT, 2
.set LCD_LCDPort__3__INTTYPE, CYREG_PICU2_INTTYPE3
.set LCD_LCDPort__3__MASK, 0x08
.set LCD_LCDPort__3__PC, CYREG_PRT2_PC3
.set LCD_LCDPort__3__PORT, 2
.set LCD_LCDPort__3__SHIFT, 3
.set LCD_LCDPort__4__INTTYPE, CYREG_PICU2_INTTYPE4
.set LCD_LCDPort__4__MASK, 0x10
.set LCD_LCDPort__4__PC, CYREG_PRT2_PC4
.set LCD_LCDPort__4__PORT, 2
.set LCD_LCDPort__4__SHIFT, 4
.set LCD_LCDPort__5__INTTYPE, CYREG_PICU2_INTTYPE5
.set LCD_LCDPort__5__MASK, 0x20
.set LCD_LCDPort__5__PC, CYREG_PRT2_PC5
.set LCD_LCDPort__5__PORT, 2
.set LCD_LCDPort__5__SHIFT, 5
.set LCD_LCDPort__6__INTTYPE, CYREG_PICU2_INTTYPE6
.set LCD_LCDPort__6__MASK, 0x40
.set LCD_LCDPort__6__PC, CYREG_PRT2_PC6
.set LCD_LCDPort__6__PORT, 2
.set LCD_LCDPort__6__SHIFT, 6
.set LCD_LCDPort__AG, CYREG_PRT2_AG
.set LCD_LCDPort__AMUX, CYREG_PRT2_AMUX
.set LCD_LCDPort__BIE, CYREG_PRT2_BIE
.set LCD_LCDPort__BIT_MASK, CYREG_PRT2_BIT_MASK
.set LCD_LCDPort__BYP, CYREG_PRT2_BYP
.set LCD_LCDPort__CTL, CYREG_PRT2_CTL
.set LCD_LCDPort__DM0, CYREG_PRT2_DM0
.set LCD_LCDPort__DM1, CYREG_PRT2_DM1
.set LCD_LCDPort__DM2, CYREG_PRT2_DM2
.set LCD_LCDPort__DR, CYREG_PRT2_DR
.set LCD_LCDPort__INP_DIS, CYREG_PRT2_INP_DIS
.set LCD_LCDPort__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU2_BASE
.set LCD_LCDPort__LCD_COM_SEG, CYREG_PRT2_LCD_COM_SEG
.set LCD_LCDPort__LCD_EN, CYREG_PRT2_LCD_EN
.set LCD_LCDPort__MASK, 0x7F
.set LCD_LCDPort__PORT, 2
.set LCD_LCDPort__PRT, CYREG_PRT2_PRT
.set LCD_LCDPort__PRTDSI__CAPS_SEL, CYREG_PRT2_CAPS_SEL
.set LCD_LCDPort__PRTDSI__DBL_SYNC_IN, CYREG_PRT2_DBL_SYNC_IN
.set LCD_LCDPort__PRTDSI__OE_SEL0, CYREG_PRT2_OE_SEL0
.set LCD_LCDPort__PRTDSI__OE_SEL1, CYREG_PRT2_OE_SEL1
.set LCD_LCDPort__PRTDSI__OUT_SEL0, CYREG_PRT2_OUT_SEL0
.set LCD_LCDPort__PRTDSI__OUT_SEL1, CYREG_PRT2_OUT_SEL1
.set LCD_LCDPort__PRTDSI__SYNC_OUT, CYREG_PRT2_SYNC_OUT
.set LCD_LCDPort__PS, CYREG_PRT2_PS
.set LCD_LCDPort__SHIFT, 0
.set LCD_LCDPort__SLW, CYREG_PRT2_SLW

/* SCK */
.set SCK__0__INTTYPE, CYREG_PICU3_INTTYPE0
.set SCK__0__MASK, 0x01
.set SCK__0__PC, CYREG_PRT3_PC0
.set SCK__0__PORT, 3
.set SCK__0__SHIFT, 0
.set SCK__AG, CYREG_PRT3_AG
.set SCK__AMUX, CYREG_PRT3_AMUX
.set SCK__BIE, CYREG_PRT3_BIE
.set SCK__BIT_MASK, CYREG_PRT3_BIT_MASK
.set SCK__BYP, CYREG_PRT3_BYP
.set SCK__CTL, CYREG_PRT3_CTL
.set SCK__DM0, CYREG_PRT3_DM0
.set SCK__DM1, CYREG_PRT3_DM1
.set SCK__DM2, CYREG_PRT3_DM2
.set SCK__DR, CYREG_PRT3_DR
.set SCK__INP_DIS, CYREG_PRT3_INP_DIS
.set SCK__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU3_BASE
.set SCK__LCD_COM_SEG, CYREG_PRT3_LCD_COM_SEG
.set SCK__LCD_EN, CYREG_PRT3_LCD_EN
.set SCK__MASK, 0x01
.set SCK__PORT, 3
.set SCK__PRT, CYREG_PRT3_PRT
.set SCK__PRTDSI__CAPS_SEL, CYREG_PRT3_CAPS_SEL
.set SCK__PRTDSI__DBL_SYNC_IN, CYREG_PRT3_DBL_SYNC_IN
.set SCK__PRTDSI__OE_SEL0, CYREG_PRT3_OE_SEL0
.set SCK__PRTDSI__OE_SEL1, CYREG_PRT3_OE_SEL1
.set SCK__PRTDSI__OUT_SEL0, CYREG_PRT3_OUT_SEL0
.set SCK__PRTDSI__OUT_SEL1, CYREG_PRT3_OUT_SEL1
.set SCK__PRTDSI__SYNC_OUT, CYREG_PRT3_SYNC_OUT
.set SCK__PS, CYREG_PRT3_PS
.set SCK__SHIFT, 0
.set SCK__SLW, CYREG_PRT3_SLW

/* SDI */
.set SDI__0__INTTYPE, CYREG_PICU3_INTTYPE1
.set SDI__0__MASK, 0x02
.set SDI__0__PC, CYREG_PRT3_PC1
.set SDI__0__PORT, 3
.set SDI__0__SHIFT, 1
.set SDI__AG, CYREG_PRT3_AG
.set SDI__AMUX, CYREG_PRT3_AMUX
.set SDI__BIE, CYREG_PRT3_BIE
.set SDI__BIT_MASK, CYREG_PRT3_BIT_MASK
.set SDI__BYP, CYREG_PRT3_BYP
.set SDI__CTL, CYREG_PRT3_CTL
.set SDI__DM0, CYREG_PRT3_DM0
.set SDI__DM1, CYREG_PRT3_DM1
.set SDI__DM2, CYREG_PRT3_DM2
.set SDI__DR, CYREG_PRT3_DR
.set SDI__INP_DIS, CYREG_PRT3_INP_DIS
.set SDI__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU3_BASE
.set SDI__LCD_COM_SEG, CYREG_PRT3_LCD_COM_SEG
.set SDI__LCD_EN, CYREG_PRT3_LCD_EN
.set SDI__MASK, 0x02
.set SDI__PORT, 3
.set SDI__PRT, CYREG_PRT3_PRT
.set SDI__PRTDSI__CAPS_SEL, CYREG_PRT3_CAPS_SEL
.set SDI__PRTDSI__DBL_SYNC_IN, CYREG_PRT3_DBL_SYNC_IN
.set SDI__PRTDSI__OE_SEL0, CYREG_PRT3_OE_SEL0
.set SDI__PRTDSI__OE_SEL1, CYREG_PRT3_OE_SEL1
.set SDI__PRTDSI__OUT_SEL0, CYREG_PRT3_OUT_SEL0
.set SDI__PRTDSI__OUT_SEL1, CYREG_PRT3_OUT_SEL1
.set SDI__PRTDSI__SYNC_OUT, CYREG_PRT3_SYNC_OUT
.set SDI__PS, CYREG_PRT3_PS
.set SDI__SHIFT, 1
.set SDI__SLW, CYREG_PRT3_SLW

/* I2S_1 */
.set I2S_1_bI2S_BitCounter__16BIT_CONTROL_AUX_CTL_REG, CYREG_B1_UDB04_05_ACTL
.set I2S_1_bI2S_BitCounter__16BIT_CONTROL_CONTROL_REG, CYREG_B1_UDB04_05_CTL
.set I2S_1_bI2S_BitCounter__16BIT_CONTROL_COUNT_REG, CYREG_B1_UDB04_05_CTL
.set I2S_1_bI2S_BitCounter__16BIT_COUNT_CONTROL_REG, CYREG_B1_UDB04_05_CTL
.set I2S_1_bI2S_BitCounter__16BIT_COUNT_COUNT_REG, CYREG_B1_UDB04_05_CTL
.set I2S_1_bI2S_BitCounter__16BIT_MASK_MASK_REG, CYREG_B1_UDB04_05_MSK
.set I2S_1_bI2S_BitCounter__16BIT_MASK_PERIOD_REG, CYREG_B1_UDB04_05_MSK
.set I2S_1_bI2S_BitCounter__16BIT_PERIOD_MASK_REG, CYREG_B1_UDB04_05_MSK
.set I2S_1_bI2S_BitCounter__16BIT_PERIOD_PERIOD_REG, CYREG_B1_UDB04_05_MSK
.set I2S_1_bI2S_BitCounter__CONTROL_AUX_CTL_REG, CYREG_B1_UDB04_ACTL
.set I2S_1_bI2S_BitCounter__CONTROL_REG, CYREG_B1_UDB04_CTL
.set I2S_1_bI2S_BitCounter__CONTROL_ST_REG, CYREG_B1_UDB04_ST_CTL
.set I2S_1_bI2S_BitCounter__COUNT_REG, CYREG_B1_UDB04_CTL
.set I2S_1_bI2S_BitCounter__COUNT_ST_REG, CYREG_B1_UDB04_ST_CTL
.set I2S_1_bI2S_BitCounter__MASK_CTL_AUX_CTL_REG, CYREG_B1_UDB04_MSK_ACTL
.set I2S_1_bI2S_BitCounter__PER_CTL_AUX_CTL_REG, CYREG_B1_UDB04_MSK_ACTL
.set I2S_1_bI2S_BitCounter__PERIOD_REG, CYREG_B1_UDB04_MSK
.set I2S_1_bI2S_BitCounter_ST__16BIT_STATUS_AUX_CTL_REG, CYREG_B1_UDB04_05_ACTL
.set I2S_1_bI2S_BitCounter_ST__16BIT_STATUS_REG, CYREG_B1_UDB04_05_ST
.set I2S_1_bI2S_BitCounter_ST__MASK_REG, CYREG_B1_UDB04_MSK
.set I2S_1_bI2S_BitCounter_ST__MASK_ST_AUX_CTL_REG, CYREG_B1_UDB04_MSK_ACTL
.set I2S_1_bI2S_BitCounter_ST__PER_ST_AUX_CTL_REG, CYREG_B1_UDB04_MSK_ACTL
.set I2S_1_bI2S_BitCounter_ST__STATUS_AUX_CTL_REG, CYREG_B1_UDB04_ACTL
.set I2S_1_bI2S_BitCounter_ST__STATUS_CNT_REG, CYREG_B1_UDB04_ST_CTL
.set I2S_1_bI2S_BitCounter_ST__STATUS_CONTROL_REG, CYREG_B1_UDB04_ST_CTL
.set I2S_1_bI2S_BitCounter_ST__STATUS_REG, CYREG_B1_UDB04_ST
.set I2S_1_bI2S_CtlReg__1__MASK, 0x02
.set I2S_1_bI2S_CtlReg__1__POS, 1
.set I2S_1_bI2S_CtlReg__16BIT_CONTROL_AUX_CTL_REG, CYREG_B1_UDB05_06_ACTL
.set I2S_1_bI2S_CtlReg__16BIT_CONTROL_CONTROL_REG, CYREG_B1_UDB05_06_CTL
.set I2S_1_bI2S_CtlReg__16BIT_CONTROL_COUNT_REG, CYREG_B1_UDB05_06_CTL
.set I2S_1_bI2S_CtlReg__16BIT_COUNT_CONTROL_REG, CYREG_B1_UDB05_06_CTL
.set I2S_1_bI2S_CtlReg__16BIT_COUNT_COUNT_REG, CYREG_B1_UDB05_06_CTL
.set I2S_1_bI2S_CtlReg__16BIT_MASK_MASK_REG, CYREG_B1_UDB05_06_MSK
.set I2S_1_bI2S_CtlReg__16BIT_MASK_PERIOD_REG, CYREG_B1_UDB05_06_MSK
.set I2S_1_bI2S_CtlReg__16BIT_PERIOD_MASK_REG, CYREG_B1_UDB05_06_MSK
.set I2S_1_bI2S_CtlReg__16BIT_PERIOD_PERIOD_REG, CYREG_B1_UDB05_06_MSK
.set I2S_1_bI2S_CtlReg__2__MASK, 0x04
.set I2S_1_bI2S_CtlReg__2__POS, 2
.set I2S_1_bI2S_CtlReg__CONTROL_AUX_CTL_REG, CYREG_B1_UDB05_ACTL
.set I2S_1_bI2S_CtlReg__CONTROL_REG, CYREG_B1_UDB05_CTL
.set I2S_1_bI2S_CtlReg__CONTROL_ST_REG, CYREG_B1_UDB05_ST_CTL
.set I2S_1_bI2S_CtlReg__COUNT_REG, CYREG_B1_UDB05_CTL
.set I2S_1_bI2S_CtlReg__COUNT_ST_REG, CYREG_B1_UDB05_ST_CTL
.set I2S_1_bI2S_CtlReg__MASK, 0x06
.set I2S_1_bI2S_CtlReg__MASK_CTL_AUX_CTL_REG, CYREG_B1_UDB05_MSK_ACTL
.set I2S_1_bI2S_CtlReg__PER_CTL_AUX_CTL_REG, CYREG_B1_UDB05_MSK_ACTL
.set I2S_1_bI2S_CtlReg__PERIOD_REG, CYREG_B1_UDB05_MSK
.set I2S_1_bI2S_Rx_CH_0__dpRx_u0__16BIT_A0_REG, CYREG_B1_UDB05_06_A0
.set I2S_1_bI2S_Rx_CH_0__dpRx_u0__16BIT_A1_REG, CYREG_B1_UDB05_06_A1
.set I2S_1_bI2S_Rx_CH_0__dpRx_u0__16BIT_D0_REG, CYREG_B1_UDB05_06_D0
.set I2S_1_bI2S_Rx_CH_0__dpRx_u0__16BIT_D1_REG, CYREG_B1_UDB05_06_D1
.set I2S_1_bI2S_Rx_CH_0__dpRx_u0__16BIT_DP_AUX_CTL_REG, CYREG_B1_UDB05_06_ACTL
.set I2S_1_bI2S_Rx_CH_0__dpRx_u0__16BIT_F0_REG, CYREG_B1_UDB05_06_F0
.set I2S_1_bI2S_Rx_CH_0__dpRx_u0__16BIT_F1_REG, CYREG_B1_UDB05_06_F1
.set I2S_1_bI2S_Rx_CH_0__dpRx_u0__A0_A1_REG, CYREG_B1_UDB05_A0_A1
.set I2S_1_bI2S_Rx_CH_0__dpRx_u0__A0_REG, CYREG_B1_UDB05_A0
.set I2S_1_bI2S_Rx_CH_0__dpRx_u0__A1_REG, CYREG_B1_UDB05_A1
.set I2S_1_bI2S_Rx_CH_0__dpRx_u0__D0_D1_REG, CYREG_B1_UDB05_D0_D1
.set I2S_1_bI2S_Rx_CH_0__dpRx_u0__D0_REG, CYREG_B1_UDB05_D0
.set I2S_1_bI2S_Rx_CH_0__dpRx_u0__D1_REG, CYREG_B1_UDB05_D1
.set I2S_1_bI2S_Rx_CH_0__dpRx_u0__DP_AUX_CTL_REG, CYREG_B1_UDB05_ACTL
.set I2S_1_bI2S_Rx_CH_0__dpRx_u0__F0_F1_REG, CYREG_B1_UDB05_F0_F1
.set I2S_1_bI2S_Rx_CH_0__dpRx_u0__F0_REG, CYREG_B1_UDB05_F0
.set I2S_1_bI2S_Rx_CH_0__dpRx_u0__F1_REG, CYREG_B1_UDB05_F1
.set I2S_1_bI2S_Rx_CH_0__dpRx_u0__MSK_DP_AUX_CTL_REG, CYREG_B1_UDB05_MSK_ACTL
.set I2S_1_bI2S_Rx_CH_0__dpRx_u0__PER_DP_AUX_CTL_REG, CYREG_B1_UDB05_MSK_ACTL
.set I2S_1_bI2S_Rx_STS_0__Sts__0__MASK, 0x01
.set I2S_1_bI2S_Rx_STS_0__Sts__0__POS, 0
.set I2S_1_bI2S_Rx_STS_0__Sts__1__MASK, 0x02
.set I2S_1_bI2S_Rx_STS_0__Sts__1__POS, 1
.set I2S_1_bI2S_Rx_STS_0__Sts__16BIT_STATUS_AUX_CTL_REG, CYREG_B1_UDB05_06_ACTL
.set I2S_1_bI2S_Rx_STS_0__Sts__16BIT_STATUS_REG, CYREG_B1_UDB05_06_ST
.set I2S_1_bI2S_Rx_STS_0__Sts__MASK, 0x03
.set I2S_1_bI2S_Rx_STS_0__Sts__MASK_REG, CYREG_B1_UDB05_MSK
.set I2S_1_bI2S_Rx_STS_0__Sts__MASK_ST_AUX_CTL_REG, CYREG_B1_UDB05_MSK_ACTL
.set I2S_1_bI2S_Rx_STS_0__Sts__PER_ST_AUX_CTL_REG, CYREG_B1_UDB05_MSK_ACTL
.set I2S_1_bI2S_Rx_STS_0__Sts__STATUS_AUX_CTL_REG, CYREG_B1_UDB05_ACTL
.set I2S_1_bI2S_Rx_STS_0__Sts__STATUS_CNT_REG, CYREG_B1_UDB05_ST_CTL
.set I2S_1_bI2S_Rx_STS_0__Sts__STATUS_CONTROL_REG, CYREG_B1_UDB05_ST_CTL
.set I2S_1_bI2S_Rx_STS_0__Sts__STATUS_REG, CYREG_B1_UDB05_ST

/* Pin_1 */
.set Pin_1__0__INTTYPE, CYREG_PICU3_INTTYPE3
.set Pin_1__0__MASK, 0x08
.set Pin_1__0__PC, CYREG_PRT3_PC3
.set Pin_1__0__PORT, 3
.set Pin_1__0__SHIFT, 3
.set Pin_1__AG, CYREG_PRT3_AG
.set Pin_1__AMUX, CYREG_PRT3_AMUX
.set Pin_1__BIE, CYREG_PRT3_BIE
.set Pin_1__BIT_MASK, CYREG_PRT3_BIT_MASK
.set Pin_1__BYP, CYREG_PRT3_BYP
.set Pin_1__CTL, CYREG_PRT3_CTL
.set Pin_1__DM0, CYREG_PRT3_DM0
.set Pin_1__DM1, CYREG_PRT3_DM1
.set Pin_1__DM2, CYREG_PRT3_DM2
.set Pin_1__DR, CYREG_PRT3_DR
.set Pin_1__INP_DIS, CYREG_PRT3_INP_DIS
.set Pin_1__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU3_BASE
.set Pin_1__LCD_COM_SEG, CYREG_PRT3_LCD_COM_SEG
.set Pin_1__LCD_EN, CYREG_PRT3_LCD_EN
.set Pin_1__MASK, 0x08
.set Pin_1__PORT, 3
.set Pin_1__PRT, CYREG_PRT3_PRT
.set Pin_1__PRTDSI__CAPS_SEL, CYREG_PRT3_CAPS_SEL
.set Pin_1__PRTDSI__DBL_SYNC_IN, CYREG_PRT3_DBL_SYNC_IN
.set Pin_1__PRTDSI__OE_SEL0, CYREG_PRT3_OE_SEL0
.set Pin_1__PRTDSI__OE_SEL1, CYREG_PRT3_OE_SEL1
.set Pin_1__PRTDSI__OUT_SEL0, CYREG_PRT3_OUT_SEL0
.set Pin_1__PRTDSI__OUT_SEL1, CYREG_PRT3_OUT_SEL1
.set Pin_1__PRTDSI__SYNC_OUT, CYREG_PRT3_SYNC_OUT
.set Pin_1__PS, CYREG_PRT3_PS
.set Pin_1__SHIFT, 3
.set Pin_1__SLW, CYREG_PRT3_SLW

/* clock */
.set clock__CFG0, CYREG_CLKDIST_DCFG0_CFG0
.set clock__CFG1, CYREG_CLKDIST_DCFG0_CFG1
.set clock__CFG2, CYREG_CLKDIST_DCFG0_CFG2
.set clock__CFG2_SRC_SEL_MASK, 0x07
.set clock__INDEX, 0x00
.set clock__PM_ACT_CFG, CYREG_PM_ACT_CFG2
.set clock__PM_ACT_MSK, 0x01
.set clock__PM_STBY_CFG, CYREG_PM_STBY_CFG2
.set clock__PM_STBY_MSK, 0x01

/* VDAC8_1 */
.set VDAC8_1_viDAC8__CR0, CYREG_DAC3_CR0
.set VDAC8_1_viDAC8__CR1, CYREG_DAC3_CR1
.set VDAC8_1_viDAC8__D, CYREG_DAC3_D
.set VDAC8_1_viDAC8__PM_ACT_CFG, CYREG_PM_ACT_CFG8
.set VDAC8_1_viDAC8__PM_ACT_MSK, 0x08
.set VDAC8_1_viDAC8__PM_STBY_CFG, CYREG_PM_STBY_CFG8
.set VDAC8_1_viDAC8__PM_STBY_MSK, 0x08
.set VDAC8_1_viDAC8__STROBE, CYREG_DAC3_STROBE
.set VDAC8_1_viDAC8__SW0, CYREG_DAC3_SW0
.set VDAC8_1_viDAC8__SW2, CYREG_DAC3_SW2
.set VDAC8_1_viDAC8__SW3, CYREG_DAC3_SW3
.set VDAC8_1_viDAC8__SW4, CYREG_DAC3_SW4
.set VDAC8_1_viDAC8__TR, CYREG_DAC3_TR
.set VDAC8_1_viDAC8__TRIM__M1, CYREG_FLSHID_CUST_TABLES_DAC3_M1
.set VDAC8_1_viDAC8__TRIM__M2, CYREG_FLSHID_CUST_TABLES_DAC3_M2
.set VDAC8_1_viDAC8__TRIM__M3, CYREG_FLSHID_CUST_TABLES_DAC3_M3
.set VDAC8_1_viDAC8__TRIM__M4, CYREG_FLSHID_CUST_TABLES_DAC3_M4
.set VDAC8_1_viDAC8__TRIM__M5, CYREG_FLSHID_CUST_TABLES_DAC3_M5
.set VDAC8_1_viDAC8__TRIM__M6, CYREG_FLSHID_CUST_TABLES_DAC3_M6
.set VDAC8_1_viDAC8__TRIM__M7, CYREG_FLSHID_CUST_TABLES_DAC3_M7
.set VDAC8_1_viDAC8__TRIM__M8, CYREG_FLSHID_CUST_TABLES_DAC3_M8
.set VDAC8_1_viDAC8__TST, CYREG_DAC3_TST

/* Miscellaneous */
.set BCLK__BUS_CLK__HZ, 24000000
.set BCLK__BUS_CLK__KHZ, 24000
.set BCLK__BUS_CLK__MHZ, 24
.set CYDEV_CHIP_DIE_LEOPARD, 1
.set CYDEV_CHIP_DIE_PSOC4A, 18
.set CYDEV_CHIP_DIE_PSOC5LP, 2
.set CYDEV_CHIP_DIE_PSOC5TM, 3
.set CYDEV_CHIP_DIE_TMA4, 4
.set CYDEV_CHIP_DIE_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_FM0P, 5
.set CYDEV_CHIP_FAMILY_FM3, 6
.set CYDEV_CHIP_FAMILY_FM4, 7
.set CYDEV_CHIP_FAMILY_PSOC3, 1
.set CYDEV_CHIP_FAMILY_PSOC4, 2
.set CYDEV_CHIP_FAMILY_PSOC5, 3
.set CYDEV_CHIP_FAMILY_PSOC6, 4
.set CYDEV_CHIP_FAMILY_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_USED, CYDEV_CHIP_FAMILY_PSOC5
.set CYDEV_CHIP_JTAG_ID, 0x2E123069
.set CYDEV_CHIP_MEMBER_3A, 1
.set CYDEV_CHIP_MEMBER_4A, 18
.set CYDEV_CHIP_MEMBER_4D, 13
.set CYDEV_CHIP_MEMBER_4E, 6
.set CYDEV_CHIP_MEMBER_4F, 19
.set CYDEV_CHIP_MEMBER_4G, 4
.set CYDEV_CHIP_MEMBER_4H, 17
.set CYDEV_CHIP_MEMBER_4I, 23
.set CYDEV_CHIP_MEMBER_4J, 14
.set CYDEV_CHIP_MEMBER_4K, 15
.set CYDEV_CHIP_MEMBER_4L, 22
.set CYDEV_CHIP_MEMBER_4M, 21
.set CYDEV_CHIP_MEMBER_4N, 10
.set CYDEV_CHIP_MEMBER_4O, 7
.set CYDEV_CHIP_MEMBER_4P, 20
.set CYDEV_CHIP_MEMBER_4Q, 12
.set CYDEV_CHIP_MEMBER_4R, 8
.set CYDEV_CHIP_MEMBER_4S, 11
.set CYDEV_CHIP_MEMBER_4T, 9
.set CYDEV_CHIP_MEMBER_4U, 5
.set CYDEV_CHIP_MEMBER_4V, 16
.set CYDEV_CHIP_MEMBER_5A, 3
.set CYDEV_CHIP_MEMBER_5B, 2
.set CYDEV_CHIP_MEMBER_6A, 24
.set CYDEV_CHIP_MEMBER_FM3, 28
.set CYDEV_CHIP_MEMBER_FM4, 29
.set CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1, 25
.set CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2, 26
.set CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3, 27
.set CYDEV_CHIP_MEMBER_UNKNOWN, 0
.set CYDEV_CHIP_MEMBER_USED, CYDEV_CHIP_MEMBER_5B
.set CYDEV_CHIP_DIE_EXPECT, CYDEV_CHIP_MEMBER_USED
.set CYDEV_CHIP_DIE_ACTUAL, CYDEV_CHIP_DIE_EXPECT
.set CYDEV_CHIP_REV_LEOPARD_ES1, 0
.set CYDEV_CHIP_REV_LEOPARD_ES2, 1
.set CYDEV_CHIP_REV_LEOPARD_ES3, 3
.set CYDEV_CHIP_REV_LEOPARD_PRODUCTION, 3
.set CYDEV_CHIP_REV_PSOC4A_ES0, 17
.set CYDEV_CHIP_REV_PSOC4A_PRODUCTION, 17
.set CYDEV_CHIP_REV_PSOC5LP_ES0, 0
.set CYDEV_CHIP_REV_PSOC5LP_PRODUCTION, 0
.set CYDEV_CHIP_REV_PSOC5TM_ES0, 0
.set CYDEV_CHIP_REV_PSOC5TM_ES1, 1
.set CYDEV_CHIP_REV_PSOC5TM_PRODUCTION, 1
.set CYDEV_CHIP_REV_TMA4_ES, 17
.set CYDEV_CHIP_REV_TMA4_ES2, 33
.set CYDEV_CHIP_REV_TMA4_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_3A_ES1, 0
.set CYDEV_CHIP_REVISION_3A_ES2, 1
.set CYDEV_CHIP_REVISION_3A_ES3, 3
.set CYDEV_CHIP_REVISION_3A_PRODUCTION, 3
.set CYDEV_CHIP_REVISION_4A_ES0, 17
.set CYDEV_CHIP_REVISION_4A_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_4D_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD, 0
.set CYDEV_CHIP_REVISION_4E_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION_256K, 0
.set CYDEV_CHIP_REVISION_4G_ES, 17
.set CYDEV_CHIP_REVISION_4G_ES2, 33
.set CYDEV_CHIP_REVISION_4G_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_4H_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4I_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4J_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4K_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4L_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4M_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4N_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4O_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4P_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4Q_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4R_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4S_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4T_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4U_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4V_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_5A_ES0, 0
.set CYDEV_CHIP_REVISION_5A_ES1, 1
.set CYDEV_CHIP_REVISION_5A_PRODUCTION, 1
.set CYDEV_CHIP_REVISION_5B_ES0, 0
.set CYDEV_CHIP_REVISION_5B_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_6A_ES, 17
.set CYDEV_CHIP_REVISION_6A_NO_UDB, 33
.set CYDEV_CHIP_REVISION_6A_PRODUCTION, 33
.set CYDEV_CHIP_REVISION_FM3_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_FM4_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_USED, CYDEV_CHIP_REVISION_5B_PRODUCTION
.set CYDEV_CHIP_REV_EXPECT, CYDEV_CHIP_REVISION_USED
.set CYDEV_CONFIG_FASTBOOT_ENABLED, 1
.set CYDEV_CONFIG_UNUSED_IO_AllowButWarn, 0
.set CYDEV_CONFIG_UNUSED_IO, CYDEV_CONFIG_UNUSED_IO_AllowButWarn
.set CYDEV_CONFIG_UNUSED_IO_AllowWithInfo, 1
.set CYDEV_CONFIG_UNUSED_IO_Disallowed, 2
.set CYDEV_CONFIGURATION_COMPRESSED, 0
.set CYDEV_CONFIGURATION_DMA, 1
.set CYDEV_CONFIGURATION_ECC, 1
.set CYDEV_CONFIGURATION_IMOENABLED, CYDEV_CONFIG_FASTBOOT_ENABLED
.set CYDEV_CONFIGURATION_MODE_COMPRESSED, 0
.set CYDEV_CONFIGURATION_MODE_DMA, 2
.set CYDEV_CONFIGURATION_MODE, CYDEV_CONFIGURATION_MODE_DMA
.set CYDEV_CONFIGURATION_MODE_UNCOMPRESSED, 1
.set CYDEV_DEBUG_ENABLE_MASK, 0x20
.set CYDEV_DEBUG_ENABLE_REGISTER, CYREG_MLOGIC_DEBUG
.set CYDEV_DEBUGGING_DPS_Disable, 3
.set CYDEV_DEBUGGING_DPS_JTAG_4, 1
.set CYDEV_DEBUGGING_DPS_JTAG_5, 0
.set CYDEV_DEBUGGING_DPS_SWD, 2
.set CYDEV_DEBUGGING_DPS_SWD_SWV, 6
.set CYDEV_DEBUGGING_DPS, CYDEV_DEBUGGING_DPS_SWD_SWV
.set CYDEV_DEBUGGING_ENABLE, 1
.set CYDEV_DEBUGGING_XRES, 0
.set CYDEV_DMA_CHANNELS_AVAILABLE, 24
.set CYDEV_ECC_ENABLE, 0
.set CYDEV_HEAP_SIZE, 0x80
.set CYDEV_INSTRUCT_CACHE_ENABLED, 0
.set CYDEV_INTR_RISING, 0x00000000
.set CYDEV_IS_EXPORTING_CODE, 0
.set CYDEV_IS_IMPORTING_CODE, 0
.set CYDEV_PROJ_TYPE, 0
.set CYDEV_PROJ_TYPE_BOOTLOADER, 1
.set CYDEV_PROJ_TYPE_LAUNCHER, 5
.set CYDEV_PROJ_TYPE_LOADABLE, 2
.set CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER, 4
.set CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER, 3
.set CYDEV_PROJ_TYPE_STANDARD, 0
.set CYDEV_PROTECTION_ENABLE, 0
.set CYDEV_STACK_SIZE, 0x0800
.set CYDEV_USE_BUNDLED_CMSIS, 1
.set CYDEV_VARIABLE_VDDA, 0
.set CYDEV_VDDA_MV, 5000
.set CYDEV_VDDD_MV, 5000
.set CYDEV_VDDIO0_MV, 5000
.set CYDEV_VDDIO1_MV, 5000
.set CYDEV_VDDIO2_MV, 5000
.set CYDEV_VDDIO3_MV, 5000
.set CYDEV_VIO0_MV, 5000
.set CYDEV_VIO1_MV, 5000
.set CYDEV_VIO2_MV, 5000
.set CYDEV_VIO3_MV, 5000
.set CYIPBLOCK_ARM_CM3_VERSION, 0
.set CYIPBLOCK_P3_ANAIF_VERSION, 0
.set CYIPBLOCK_P3_CAN_VERSION, 0
.set CYIPBLOCK_P3_CAPSENSE_VERSION, 0
.set CYIPBLOCK_P3_COMP_VERSION, 0
.set CYIPBLOCK_P3_DECIMATOR_VERSION, 0
.set CYIPBLOCK_P3_DFB_VERSION, 0
.set CYIPBLOCK_P3_DMA_VERSION, 0
.set CYIPBLOCK_P3_DRQ_VERSION, 0
.set CYIPBLOCK_P3_DSM_VERSION, 0
.set CYIPBLOCK_P3_EMIF_VERSION, 0
.set CYIPBLOCK_P3_I2C_VERSION, 0
.set CYIPBLOCK_P3_LCD_VERSION, 0
.set CYIPBLOCK_P3_LPF_VERSION, 0
.set CYIPBLOCK_P3_OPAMP_VERSION, 0
.set CYIPBLOCK_P3_PM_VERSION, 0
.set CYIPBLOCK_P3_SCCT_VERSION, 0
.set CYIPBLOCK_P3_TIMER_VERSION, 0
.set CYIPBLOCK_P3_USB_VERSION, 0
.set CYIPBLOCK_P3_VIDAC_VERSION, 0
.set CYIPBLOCK_P3_VREF_VERSION, 0
.set CYIPBLOCK_S8_GPIO_VERSION, 0
.set CYIPBLOCK_S8_IRQ_VERSION, 0
.set CYIPBLOCK_S8_SAR_VERSION, 0
.set CYIPBLOCK_S8_SIO_VERSION, 0
.set CYIPBLOCK_S8_UDB_VERSION, 0
.set DMA_CHANNELS_USED__MASK0, 0x00000000
.set CYDEV_BOOTLOADER_ENABLE, 0
.endif