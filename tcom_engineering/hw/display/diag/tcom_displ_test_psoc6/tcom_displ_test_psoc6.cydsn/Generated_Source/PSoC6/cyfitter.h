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
#include "cy_device_headers.h"
#include "cyfitter_gpio.h"
#include "cyfitter_sysint.h"

/* CLOCK_2 */
#define CLOCK_2__DIV_IDX 1
#define CLOCK_2__DIV_NUM 1
#define CLOCK_2__DIV_TYPE CY_SYSCLK_DIV_8_BIT

/* I2C_MASTER */
#define I2C_MASTER_SCB__HW SCB6
#define I2C_MASTER_SCB__IDX 6
#define I2C_MASTER_SCB__SS0_POSITION 0u
#define I2C_MASTER_SCB__SS1_POSITION 1u
#define I2C_MASTER_SCB__SS2_POSITION 2u
#define I2C_MASTER_SCB__SS3_POSITION 3u
#define I2C_MASTER_SCBCLK__DIV_IDX 0
#define I2C_MASTER_SCBCLK__DIV_NUM 0
#define I2C_MASTER_SCBCLK__DIV_TYPE CY_SYSCLK_DIV_8_BIT

/* LCD_INTERFACE */
#define LCD_INTERFACE_GraphLcd8_Lsb__16BIT_A0_REG 0x40341020u
#define LCD_INTERFACE_GraphLcd8_Lsb__16BIT_A1_REG 0x40341120u
#define LCD_INTERFACE_GraphLcd8_Lsb__16BIT_D0_REG 0x40341220u
#define LCD_INTERFACE_GraphLcd8_Lsb__16BIT_D1_REG 0x40341320u
#define LCD_INTERFACE_GraphLcd8_Lsb__16BIT_DP_AUX_CTL_REG 0x40341920u
#define LCD_INTERFACE_GraphLcd8_Lsb__16BIT_F0_REG 0x40341420u
#define LCD_INTERFACE_GraphLcd8_Lsb__16BIT_F1_REG 0x40341520u
#define LCD_INTERFACE_GraphLcd8_Lsb__32BIT_A0_REG 0x40341020u
#define LCD_INTERFACE_GraphLcd8_Lsb__32BIT_A1_REG 0x40341120u
#define LCD_INTERFACE_GraphLcd8_Lsb__32BIT_D0_REG 0x40341220u
#define LCD_INTERFACE_GraphLcd8_Lsb__32BIT_D1_REG 0x40341320u
#define LCD_INTERFACE_GraphLcd8_Lsb__32BIT_DP_AUX_CTL_REG 0x40341920u
#define LCD_INTERFACE_GraphLcd8_Lsb__32BIT_F0_REG 0x40341420u
#define LCD_INTERFACE_GraphLcd8_Lsb__32BIT_F1_REG 0x40341520u
#define LCD_INTERFACE_GraphLcd8_Lsb__A0_A1_REG 0x40340020u
#define LCD_INTERFACE_GraphLcd8_Lsb__A0_REG 0x40341020u
#define LCD_INTERFACE_GraphLcd8_Lsb__A1_REG 0x40341120u
#define LCD_INTERFACE_GraphLcd8_Lsb__D0_D1_REG 0x40340120u
#define LCD_INTERFACE_GraphLcd8_Lsb__D0_REG 0x40341220u
#define LCD_INTERFACE_GraphLcd8_Lsb__D1_REG 0x40341320u
#define LCD_INTERFACE_GraphLcd8_Lsb__DP_AUX_CTL_REG 0x40341920u
#define LCD_INTERFACE_GraphLcd8_Lsb__DPATH_CFG0 0x40342840u
#define LCD_INTERFACE_GraphLcd8_Lsb__DPATH_CFG1 0x40342844u
#define LCD_INTERFACE_GraphLcd8_Lsb__DPATH_CFG2 0x40342848u
#define LCD_INTERFACE_GraphLcd8_Lsb__DPATH_CFG3 0x4034284Cu
#define LCD_INTERFACE_GraphLcd8_Lsb__DPATH_CFG4 0x40342850u
#define LCD_INTERFACE_GraphLcd8_Lsb__DPATH_OPC0 0x40342864u
#define LCD_INTERFACE_GraphLcd8_Lsb__DPATH_OPC1 0x40342868u
#define LCD_INTERFACE_GraphLcd8_Lsb__DPATH_OPC2 0x4034286Cu
#define LCD_INTERFACE_GraphLcd8_Lsb__DPATH_OPC3 0x40342870u
#define LCD_INTERFACE_GraphLcd8_Lsb__F0_F1_REG 0x40340220u
#define LCD_INTERFACE_GraphLcd8_Lsb__F0_REG 0x40341420u
#define LCD_INTERFACE_GraphLcd8_Lsb__F1_REG 0x40341520u
#define LCD_INTERFACE_GraphLcd8_Lsb__MSK_DP_AUX_CTL_REG 0x40340420u
#define LCD_INTERFACE_GraphLcd8_Lsb__PER_DP_AUX_CTL_REG 0x40340420u
#define LCD_INTERFACE_GraphLcd8_Lsb__RC_CFG0 0x4034285Cu
#define LCD_INTERFACE_GraphLcd8_Lsb__RC_CFG1 0x40342860u
#define LCD_INTERFACE_GraphLcd8_Lsb_PO__16BIT_CONTROL_AUX_CTL_REG 0x40341920u
#define LCD_INTERFACE_GraphLcd8_Lsb_PO__16BIT_CONTROL_CONTROL_REG 0x40341720u
#define LCD_INTERFACE_GraphLcd8_Lsb_PO__16BIT_CONTROL_COUNT_REG 0x40341720u
#define LCD_INTERFACE_GraphLcd8_Lsb_PO__16BIT_COUNT_CONTROL_REG 0x40341720u
#define LCD_INTERFACE_GraphLcd8_Lsb_PO__16BIT_COUNT_COUNT_REG 0x40341720u
#define LCD_INTERFACE_GraphLcd8_Lsb_PO__16BIT_MASK_MASK_REG 0x40341820u
#define LCD_INTERFACE_GraphLcd8_Lsb_PO__16BIT_MASK_PERIOD_REG 0x40341820u
#define LCD_INTERFACE_GraphLcd8_Lsb_PO__16BIT_PERIOD_MASK_REG 0x40341820u
#define LCD_INTERFACE_GraphLcd8_Lsb_PO__16BIT_PERIOD_PERIOD_REG 0x40341820u
#define LCD_INTERFACE_GraphLcd8_Lsb_PO__32BIT_CONTROL_AUX_CTL_REG 0x40341920u
#define LCD_INTERFACE_GraphLcd8_Lsb_PO__32BIT_CONTROL_REG 0x40341720u
#define LCD_INTERFACE_GraphLcd8_Lsb_PO__32BIT_COUNT_REG 0x40341720u
#define LCD_INTERFACE_GraphLcd8_Lsb_PO__32BIT_PERIOD_REG 0x40341820u
#define LCD_INTERFACE_GraphLcd8_Lsb_PO__CONTROL_AUX_CTL_REG 0x40341920u
#define LCD_INTERFACE_GraphLcd8_Lsb_PO__CONTROL_REG 0x40341720u
#define LCD_INTERFACE_GraphLcd8_Lsb_PO__CONTROL_ST_REG 0x40340320u
#define LCD_INTERFACE_GraphLcd8_Lsb_PO__COUNT_REG 0x40341720u
#define LCD_INTERFACE_GraphLcd8_Lsb_PO__COUNT_ST_REG 0x40340320u
#define LCD_INTERFACE_GraphLcd8_Lsb_PO__MASK_CTL_AUX_CTL_REG 0x40340420u
#define LCD_INTERFACE_GraphLcd8_Lsb_PO__PER_CTL_AUX_CTL_REG 0x40340420u
#define LCD_INTERFACE_GraphLcd8_Lsb_PO__PERIOD_REG 0x40341820u
#define LCD_INTERFACE_GraphLcd8_Lsb_PO__RC_CFG0 0x4034285Cu
#define LCD_INTERFACE_GraphLcd8_Lsb_PO__RC_CFG1 0x40342860u
#define LCD_INTERFACE_GraphLcd8_Lsb_PO__SC_CFG0 0x40342854u
#define LCD_INTERFACE_GraphLcd8_Lsb_PO__SC_CFG1 0x40342858u
#define LCD_INTERFACE_LsbReg__0__MASK 0x01u
#define LCD_INTERFACE_LsbReg__0__POS 0
#define LCD_INTERFACE_LsbReg__1__MASK 0x02u
#define LCD_INTERFACE_LsbReg__1__POS 1
#define LCD_INTERFACE_LsbReg__16BIT_STATUS_AUX_CTL_REG 0x40341920u
#define LCD_INTERFACE_LsbReg__16BIT_STATUS_REG 0x40341620u
#define LCD_INTERFACE_LsbReg__2__MASK 0x04u
#define LCD_INTERFACE_LsbReg__2__POS 2
#define LCD_INTERFACE_LsbReg__3__MASK 0x08u
#define LCD_INTERFACE_LsbReg__3__POS 3
#define LCD_INTERFACE_LsbReg__32BIT_MASK_REG 0x40341820u
#define LCD_INTERFACE_LsbReg__32BIT_STATUS_AUX_CTL_REG 0x40341920u
#define LCD_INTERFACE_LsbReg__32BIT_STATUS_REG 0x40341620u
#define LCD_INTERFACE_LsbReg__4__MASK 0x10u
#define LCD_INTERFACE_LsbReg__4__POS 4
#define LCD_INTERFACE_LsbReg__5__MASK 0x20u
#define LCD_INTERFACE_LsbReg__5__POS 5
#define LCD_INTERFACE_LsbReg__6__MASK 0x40u
#define LCD_INTERFACE_LsbReg__6__POS 6
#define LCD_INTERFACE_LsbReg__7__MASK 0x80u
#define LCD_INTERFACE_LsbReg__7__POS 7
#define LCD_INTERFACE_LsbReg__MASK 0xFFu
#define LCD_INTERFACE_LsbReg__MASK_REG 0x40341820u
#define LCD_INTERFACE_LsbReg__MASK_ST_AUX_CTL_REG 0x40340420u
#define LCD_INTERFACE_LsbReg__PER_ST_AUX_CTL_REG 0x40340420u
#define LCD_INTERFACE_LsbReg__RC_CFG0 0x4034285Cu
#define LCD_INTERFACE_LsbReg__RC_CFG1 0x40342860u
#define LCD_INTERFACE_LsbReg__SC_CFG0 0x40342854u
#define LCD_INTERFACE_LsbReg__SC_CFG1 0x40342858u
#define LCD_INTERFACE_LsbReg__STATUS_AUX_CTL_REG 0x40341920u
#define LCD_INTERFACE_LsbReg__STATUS_CNT_REG 0x40340320u
#define LCD_INTERFACE_LsbReg__STATUS_CONTROL_REG 0x40340320u
#define LCD_INTERFACE_LsbReg__STATUS_REG 0x40341620u
#define LCD_INTERFACE_StsReg__0__MASK 0x01u
#define LCD_INTERFACE_StsReg__0__POS 0
#define LCD_INTERFACE_StsReg__1__MASK 0x02u
#define LCD_INTERFACE_StsReg__1__POS 1
#define LCD_INTERFACE_StsReg__16BIT_STATUS_AUX_CTL_REG 0x40341924u
#define LCD_INTERFACE_StsReg__16BIT_STATUS_REG 0x40341624u
#define LCD_INTERFACE_StsReg__MASK 0x03u
#define LCD_INTERFACE_StsReg__MASK_REG 0x40341824u
#define LCD_INTERFACE_StsReg__RC_CFG0 0x403428DCu
#define LCD_INTERFACE_StsReg__RC_CFG1 0x403428E0u
#define LCD_INTERFACE_StsReg__SC_CFG0 0x403428D4u
#define LCD_INTERFACE_StsReg__SC_CFG1 0x403428D8u
#define LCD_INTERFACE_StsReg__STATUS_AUX_CTL_REG 0x40341924u
#define LCD_INTERFACE_StsReg__STATUS_REG 0x40341624u

/* DISP_TICK_TIMER */
#define DISP_TICK_TIMER_TCPWM__CNT_HW TCPWM0_CNT0
#define DISP_TICK_TIMER_TCPWM__CNT_IDX 0u
#define DISP_TICK_TIMER_TCPWM__HW TCPWM0
#define DISP_TICK_TIMER_TCPWM__IDX 0u

/* UART_KITPROG_USB */
#define UART_KITPROG_USB_SCB__HW SCB2
#define UART_KITPROG_USB_SCB__IDX 2
#define UART_KITPROG_USB_SCB__SS0_POSITION 0u
#define UART_KITPROG_USB_SCB__SS1_POSITION 1u
#define UART_KITPROG_USB_SCB__SS2_POSITION 2u
#define UART_KITPROG_USB_SCB__SS3_POSITION 3u
#define UART_KITPROG_USB_SCBCLK__DIV_IDX 8
#define UART_KITPROG_USB_SCBCLK__DIV_NUM 0
#define UART_KITPROG_USB_SCBCLK__DIV_TYPE CY_SYSCLK_DIV_16_BIT

/* Miscellaneous */
#define CPUSS__CTI_TR_IN_0 TRIG5_OUT_CPUSS_CTI_TR_IN0
#define CPUSS__CTI_TR_IN_1 TRIG5_OUT_CPUSS_CTI_TR_IN1
#define CY_CPUSS_SWJ_SWCLK_TCLK_0_DRIVEMODE CY_GPIO_DM_PULLDOWN
#define CY_CPUSS_SWJ_SWCLK_TCLK_0_INBUF_ENABLED 1u
#define CY_CPUSS_SWJ_SWCLK_TCLK_0_INIT_DRIVESTATE 0u
#define CY_CPUSS_SWJ_SWCLK_TCLK_0_INIT_MUXSEL 29u
#define CY_CPUSS_SWJ_SWCLK_TCLK_0_INPUT_SYNC 2u
#define CY_CPUSS_SWJ_SWCLK_TCLK_0_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define CY_CPUSS_SWJ_SWCLK_TCLK_0_NUM 7u
#define CY_CPUSS_SWJ_SWCLK_TCLK_0_PORT GPIO_PRT6
#define CY_CPUSS_SWJ_SWCLK_TCLK_0_SLEWRATE CY_GPIO_SLEW_FAST
#define CY_CPUSS_SWJ_SWCLK_TCLK_0_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS
#define CY_CPUSS_SWJ_SWCLK_TCLK_DRIVEMODE CY_GPIO_DM_PULLDOWN
#define CY_CPUSS_SWJ_SWCLK_TCLK_INBUF_ENABLED 1u
#define CY_CPUSS_SWJ_SWCLK_TCLK_INIT_DRIVESTATE 0u
#define CY_CPUSS_SWJ_SWCLK_TCLK_INIT_MUXSEL 29u
#define CY_CPUSS_SWJ_SWCLK_TCLK_INPUT_SYNC 2u
#define CY_CPUSS_SWJ_SWCLK_TCLK_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define CY_CPUSS_SWJ_SWCLK_TCLK_NUM 7u
#define CY_CPUSS_SWJ_SWCLK_TCLK_PORT GPIO_PRT6
#define CY_CPUSS_SWJ_SWCLK_TCLK_SLEWRATE CY_GPIO_SLEW_FAST
#define CY_CPUSS_SWJ_SWCLK_TCLK_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS
#define CY_CPUSS_SWJ_SWDIO_TMS_0_DRIVEMODE CY_GPIO_DM_PULLUP
#define CY_CPUSS_SWJ_SWDIO_TMS_0_INBUF_ENABLED 1u
#define CY_CPUSS_SWJ_SWDIO_TMS_0_INIT_DRIVESTATE 0u
#define CY_CPUSS_SWJ_SWDIO_TMS_0_INIT_MUXSEL 29u
#define CY_CPUSS_SWJ_SWDIO_TMS_0_INPUT_SYNC 2u
#define CY_CPUSS_SWJ_SWDIO_TMS_0_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define CY_CPUSS_SWJ_SWDIO_TMS_0_NUM 6u
#define CY_CPUSS_SWJ_SWDIO_TMS_0_PORT GPIO_PRT6
#define CY_CPUSS_SWJ_SWDIO_TMS_0_SLEWRATE CY_GPIO_SLEW_FAST
#define CY_CPUSS_SWJ_SWDIO_TMS_0_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS
#define CY_CPUSS_SWJ_SWDIO_TMS_DRIVEMODE CY_GPIO_DM_PULLUP
#define CY_CPUSS_SWJ_SWDIO_TMS_INBUF_ENABLED 1u
#define CY_CPUSS_SWJ_SWDIO_TMS_INIT_DRIVESTATE 0u
#define CY_CPUSS_SWJ_SWDIO_TMS_INIT_MUXSEL 29u
#define CY_CPUSS_SWJ_SWDIO_TMS_INPUT_SYNC 2u
#define CY_CPUSS_SWJ_SWDIO_TMS_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define CY_CPUSS_SWJ_SWDIO_TMS_NUM 6u
#define CY_CPUSS_SWJ_SWDIO_TMS_PORT GPIO_PRT6
#define CY_CPUSS_SWJ_SWDIO_TMS_SLEWRATE CY_GPIO_SLEW_FAST
#define CY_CPUSS_SWJ_SWDIO_TMS_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS
#define CY_PROJECT_NAME "tcom_displ_test_psoc6"
#define CY_VERSION "PSoC Creator  4.2"
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_PSOC4A 21u
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
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC6
#define CYDEV_CHIP_JTAG_ID 0xE2F02100u
#define CYDEV_CHIP_MEMBER_3A 1u
#define CYDEV_CHIP_MEMBER_4A 21u
#define CYDEV_CHIP_MEMBER_4D 16u
#define CYDEV_CHIP_MEMBER_4E 6u
#define CYDEV_CHIP_MEMBER_4F 22u
#define CYDEV_CHIP_MEMBER_4G 4u
#define CYDEV_CHIP_MEMBER_4H 20u
#define CYDEV_CHIP_MEMBER_4I 26u
#define CYDEV_CHIP_MEMBER_4J 17u
#define CYDEV_CHIP_MEMBER_4K 18u
#define CYDEV_CHIP_MEMBER_4L 25u
#define CYDEV_CHIP_MEMBER_4M 24u
#define CYDEV_CHIP_MEMBER_4N 11u
#define CYDEV_CHIP_MEMBER_4O 8u
#define CYDEV_CHIP_MEMBER_4P 23u
#define CYDEV_CHIP_MEMBER_4Q 14u
#define CYDEV_CHIP_MEMBER_4R 9u
#define CYDEV_CHIP_MEMBER_4S 12u
#define CYDEV_CHIP_MEMBER_4T 10u
#define CYDEV_CHIP_MEMBER_4U 5u
#define CYDEV_CHIP_MEMBER_4V 19u
#define CYDEV_CHIP_MEMBER_4W 13u
#define CYDEV_CHIP_MEMBER_4X 7u
#define CYDEV_CHIP_MEMBER_4Y 15u
#define CYDEV_CHIP_MEMBER_5A 3u
#define CYDEV_CHIP_MEMBER_5B 2u
#define CYDEV_CHIP_MEMBER_6A 27u
#define CYDEV_CHIP_MEMBER_FM3 31u
#define CYDEV_CHIP_MEMBER_FM4 32u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 28u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 29u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 30u
#define CYDEV_CHIP_MEMBER_UNKNOWN 0u
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_6A
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
#define CYDEV_CHIP_REVISION_4W_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4X_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Y_PRODUCTION 0u
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
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_6A_PRODUCTION
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REVISION_USED
#define CYDEV_CLK_ALTSYSTICKCLK__HZ 32000U
#define CYDEV_CLK_ALTSYSTICKCLK__KHZ 32U
#define CYDEV_CLK_ALTSYSTICKCLK__MHZ 0U
#define CYDEV_CLK_BAKCLK__HZ 32000U
#define CYDEV_CLK_BAKCLK__KHZ 32U
#define CYDEV_CLK_BAKCLK__MHZ 0U
#define CYDEV_CLK_FASTCLK__HZ 100000000U
#define CYDEV_CLK_FASTCLK__KHZ 100000U
#define CYDEV_CLK_FASTCLK__MHZ 100U
#define CYDEV_CLK_FLL__HZ 100000000U
#define CYDEV_CLK_FLL__KHZ 100000U
#define CYDEV_CLK_FLL__MHZ 100U
#define CYDEV_CLK_HFCLK0__HZ 100000000U
#define CYDEV_CLK_HFCLK0__KHZ 100000U
#define CYDEV_CLK_HFCLK0__MHZ 100U
#define CYDEV_CLK_ILO__HZ 32000U
#define CYDEV_CLK_ILO__KHZ 32U
#define CYDEV_CLK_ILO__MHZ 0U
#define CYDEV_CLK_IMO__HZ 8000000U
#define CYDEV_CLK_IMO__KHZ 8000U
#define CYDEV_CLK_IMO__MHZ 8U
#define CYDEV_CLK_LFCLK__HZ 32000U
#define CYDEV_CLK_LFCLK__KHZ 32U
#define CYDEV_CLK_LFCLK__MHZ 0U
#define CYDEV_CLK_PATHMUX0__HZ 8000000U
#define CYDEV_CLK_PATHMUX0__KHZ 8000U
#define CYDEV_CLK_PATHMUX0__MHZ 8U
#define CYDEV_CLK_PATHMUX1__HZ 8000000U
#define CYDEV_CLK_PATHMUX1__KHZ 8000U
#define CYDEV_CLK_PATHMUX1__MHZ 8U
#define CYDEV_CLK_PATHMUX2__HZ 8000000U
#define CYDEV_CLK_PATHMUX2__KHZ 8000U
#define CYDEV_CLK_PATHMUX2__MHZ 8U
#define CYDEV_CLK_PATHMUX3__HZ 8000000U
#define CYDEV_CLK_PATHMUX3__KHZ 8000U
#define CYDEV_CLK_PATHMUX3__MHZ 8U
#define CYDEV_CLK_PATHMUX4__HZ 8000000U
#define CYDEV_CLK_PATHMUX4__KHZ 8000U
#define CYDEV_CLK_PATHMUX4__MHZ 8U
#define CYDEV_CLK_PERICLK__HZ 50000000U
#define CYDEV_CLK_PERICLK__KHZ 50000U
#define CYDEV_CLK_PERICLK__MHZ 50U
#define CYDEV_CLK_PUMPCLK__HZ 25000000U
#define CYDEV_CLK_PUMPCLK__KHZ 25000U
#define CYDEV_CLK_PUMPCLK__MHZ 25U
#define CYDEV_CLK_SLOWCLK__HZ 50000000U
#define CYDEV_CLK_SLOWCLK__KHZ 50000U
#define CYDEV_CLK_SLOWCLK__MHZ 50U
#define CYDEV_CLK_TIMERCLK__HZ 8000000U
#define CYDEV_CLK_TIMERCLK__KHZ 8000U
#define CYDEV_CLK_TIMERCLK__MHZ 8U
#define CYDEV_CONFIG_READ_ACCELERATOR 1
#define CYDEV_CONFIG_UNUSED_IO_AllowButWarn 0
#define CYDEV_CONFIG_UNUSED_IO CYDEV_CONFIG_UNUSED_IO_AllowButWarn
#define CYDEV_CONFIG_UNUSED_IO_AllowWithInfo 1
#define CYDEV_CONFIG_UNUSED_IO_Disallowed 2
#define CYDEV_CONFIGURATION_COMPRESSED 1
#define CYDEV_CONFIGURATION_MODE_COMPRESSED 0
#define CYDEV_CONFIGURATION_MODE CYDEV_CONFIGURATION_MODE_COMPRESSED
#define CYDEV_CONFIGURATION_MODE_DMA 2
#define CYDEV_CONFIGURATION_MODE_UNCOMPRESSED 1
#define CYDEV_CORE_VOLTAGE CY_SYSPM_LDO_VOLTAGE_1_1V
#define CYDEV_DEBUGGING_DPS_Disable 3
#define CYDEV_DEBUGGING_DPS_JTAG_4 1
#define CYDEV_DEBUGGING_DPS_JTAG_5 0
#define CYDEV_DEBUGGING_DPS_SWD 2
#define CYDEV_DEBUGGING_DPS CYDEV_DEBUGGING_DPS_SWD
#define CYDEV_DEBUGGING_DPS_SWD_SWV 6
#define CYDEV_DEBUGGING_ENABLE 1
#define CYDEV_ENABLE_SIMO_BUCK false
#define CYDEV_IS_EXPORTING_CODE 0
#define CYDEV_IS_IMPORTING_CODE 0
#define CYDEV_PMIC_ENABLED 0
#define CYDEV_PMIC_MODE CYDEV_PMIC_MODE_DISABLED
#define CYDEV_POWER_MODE CYDEV_POWER_MODE_LDO_LINEAR_REG_1_1V
#define CYDEV_PROJ_TYPE 0
#define CYDEV_PROJ_TYPE_BOOTLOADER 1
#define CYDEV_PROJ_TYPE_LAUNCHER 5
#define CYDEV_PROJ_TYPE_LOADABLE 2
#define CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER 4
#define CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER 3
#define CYDEV_PROJ_TYPE_STANDARD 0
#define CYDEV_SYSTEM_AREF_CURRENT_HIGH 1
#define CYDEV_SYSTEM_AREF_CURRENT CYDEV_SYSTEM_AREF_CURRENT_HIGH
#define CYDEV_SYSTEM_AREF_CURRENT_LOW 0
#define CYDEV_SYSTEM_AREF_DEEPSLEEP 0
#define CYDEV_SYSTEM_AREF_SOURCE CY_SYSANALOG_VREF_SOURCE_LOCAL_1_2V
#define CYDEV_VARIABLE_VDDA 0
#define CYDEV_VBAC_SUPPLY CYDEV_VBAC_SUPPLY_VDDD
#define CYDEV_VBACKUP 3.3
#define CYDEV_VBACKUP_MV 3300
#define CYDEV_VDD 3.3
#define CYDEV_VDD_MV 3300
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */
