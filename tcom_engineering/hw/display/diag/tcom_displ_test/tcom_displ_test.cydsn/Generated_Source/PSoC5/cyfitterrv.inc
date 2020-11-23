;
; File Name: cyfitterrv.inc
; 
; PSoC Creator  4.2
;
; Description:
; 
;
;-------------------------------------------------------------------------------
; Copyright (c) 2007-2018 Cypress Semiconductor.  All rights reserved.
; You may use this file only in accordance with the license, terms, conditions, 
; disclaimers, and limitations in the end user license agreement accompanying 
; the software package with which this file was provided.
;-------------------------------------------------------------------------------

    IF :LNOT::DEF:INCLUDED_CYFITTERRV_INC
INCLUDED_CYFITTERRV_INC EQU 1
    GET cydevicerv.inc
    GET cydevicerv_trm.inc

; d_c
d_c__0__INTTYPE EQU CYREG_PICU2_INTTYPE7
d_c__0__MASK EQU 0x80
d_c__0__PC EQU CYREG_PRT2_PC7
d_c__0__PORT EQU 2
d_c__0__SHIFT EQU 7
d_c__AG EQU CYREG_PRT2_AG
d_c__AMUX EQU CYREG_PRT2_AMUX
d_c__BIE EQU CYREG_PRT2_BIE
d_c__BIT_MASK EQU CYREG_PRT2_BIT_MASK
d_c__BYP EQU CYREG_PRT2_BYP
d_c__CTL EQU CYREG_PRT2_CTL
d_c__DM0 EQU CYREG_PRT2_DM0
d_c__DM1 EQU CYREG_PRT2_DM1
d_c__DM2 EQU CYREG_PRT2_DM2
d_c__DR EQU CYREG_PRT2_DR
d_c__INP_DIS EQU CYREG_PRT2_INP_DIS
d_c__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU2_BASE
d_c__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
d_c__LCD_EN EQU CYREG_PRT2_LCD_EN
d_c__MASK EQU 0x80
d_c__PORT EQU 2
d_c__PRT EQU CYREG_PRT2_PRT
d_c__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
d_c__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
d_c__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
d_c__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
d_c__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
d_c__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
d_c__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
d_c__PS EQU CYREG_PRT2_PS
d_c__SHIFT EQU 7
d_c__SLW EQU CYREG_PRT2_SLW

; ncs
ncs__0__INTTYPE EQU CYREG_PICU12_INTTYPE4
ncs__0__MASK EQU 0x10
ncs__0__PC EQU CYREG_PRT12_PC4
ncs__0__PORT EQU 12
ncs__0__SHIFT EQU 4
ncs__AG EQU CYREG_PRT12_AG
ncs__BIE EQU CYREG_PRT12_BIE
ncs__BIT_MASK EQU CYREG_PRT12_BIT_MASK
ncs__BYP EQU CYREG_PRT12_BYP
ncs__DM0 EQU CYREG_PRT12_DM0
ncs__DM1 EQU CYREG_PRT12_DM1
ncs__DM2 EQU CYREG_PRT12_DM2
ncs__DR EQU CYREG_PRT12_DR
ncs__INP_DIS EQU CYREG_PRT12_INP_DIS
ncs__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU12_BASE
ncs__MASK EQU 0x10
ncs__PORT EQU 12
ncs__PRT EQU CYREG_PRT12_PRT
ncs__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT12_DBL_SYNC_IN
ncs__PRTDSI__OE_SEL0 EQU CYREG_PRT12_OE_SEL0
ncs__PRTDSI__OE_SEL1 EQU CYREG_PRT12_OE_SEL1
ncs__PRTDSI__OUT_SEL0 EQU CYREG_PRT12_OUT_SEL0
ncs__PRTDSI__OUT_SEL1 EQU CYREG_PRT12_OUT_SEL1
ncs__PRTDSI__SYNC_OUT EQU CYREG_PRT12_SYNC_OUT
ncs__PS EQU CYREG_PRT12_PS
ncs__SHIFT EQU 4
ncs__SIO_CFG EQU CYREG_PRT12_SIO_CFG
ncs__SIO_DIFF EQU CYREG_PRT12_SIO_DIFF
ncs__SIO_HYST_EN EQU CYREG_PRT12_SIO_HYST_EN
ncs__SIO_REG_HIFREQ EQU CYREG_PRT12_SIO_REG_HIFREQ
ncs__SLW EQU CYREG_PRT12_SLW

; nrd
nrd__0__INTTYPE EQU CYREG_PICU2_INTTYPE6
nrd__0__MASK EQU 0x40
nrd__0__PC EQU CYREG_PRT2_PC6
nrd__0__PORT EQU 2
nrd__0__SHIFT EQU 6
nrd__AG EQU CYREG_PRT2_AG
nrd__AMUX EQU CYREG_PRT2_AMUX
nrd__BIE EQU CYREG_PRT2_BIE
nrd__BIT_MASK EQU CYREG_PRT2_BIT_MASK
nrd__BYP EQU CYREG_PRT2_BYP
nrd__CTL EQU CYREG_PRT2_CTL
nrd__DM0 EQU CYREG_PRT2_DM0
nrd__DM1 EQU CYREG_PRT2_DM1
nrd__DM2 EQU CYREG_PRT2_DM2
nrd__DR EQU CYREG_PRT2_DR
nrd__INP_DIS EQU CYREG_PRT2_INP_DIS
nrd__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU2_BASE
nrd__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
nrd__LCD_EN EQU CYREG_PRT2_LCD_EN
nrd__MASK EQU 0x40
nrd__PORT EQU 2
nrd__PRT EQU CYREG_PRT2_PRT
nrd__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
nrd__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
nrd__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
nrd__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
nrd__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
nrd__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
nrd__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
nrd__PS EQU CYREG_PRT2_PS
nrd__SHIFT EQU 6
nrd__SLW EQU CYREG_PRT2_SLW

; nwr
nwr__0__INTTYPE EQU CYREG_PICU12_INTTYPE5
nwr__0__MASK EQU 0x20
nwr__0__PC EQU CYREG_PRT12_PC5
nwr__0__PORT EQU 12
nwr__0__SHIFT EQU 5
nwr__AG EQU CYREG_PRT12_AG
nwr__BIE EQU CYREG_PRT12_BIE
nwr__BIT_MASK EQU CYREG_PRT12_BIT_MASK
nwr__BYP EQU CYREG_PRT12_BYP
nwr__DM0 EQU CYREG_PRT12_DM0
nwr__DM1 EQU CYREG_PRT12_DM1
nwr__DM2 EQU CYREG_PRT12_DM2
nwr__DR EQU CYREG_PRT12_DR
nwr__INP_DIS EQU CYREG_PRT12_INP_DIS
nwr__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU12_BASE
nwr__MASK EQU 0x20
nwr__PORT EQU 12
nwr__PRT EQU CYREG_PRT12_PRT
nwr__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT12_DBL_SYNC_IN
nwr__PRTDSI__OE_SEL0 EQU CYREG_PRT12_OE_SEL0
nwr__PRTDSI__OE_SEL1 EQU CYREG_PRT12_OE_SEL1
nwr__PRTDSI__OUT_SEL0 EQU CYREG_PRT12_OUT_SEL0
nwr__PRTDSI__OUT_SEL1 EQU CYREG_PRT12_OUT_SEL1
nwr__PRTDSI__SYNC_OUT EQU CYREG_PRT12_SYNC_OUT
nwr__PS EQU CYREG_PRT12_PS
nwr__SHIFT EQU 5
nwr__SIO_CFG EQU CYREG_PRT12_SIO_CFG
nwr__SIO_DIFF EQU CYREG_PRT12_SIO_DIFF
nwr__SIO_HYST_EN EQU CYREG_PRT12_SIO_HYST_EN
nwr__SIO_REG_HIFREQ EQU CYREG_PRT12_SIO_REG_HIFREQ
nwr__SLW EQU CYREG_PRT12_SLW

; Pin_0
Pin_0__0__INTTYPE EQU CYREG_PICU3_INTTYPE7
Pin_0__0__MASK EQU 0x80
Pin_0__0__PC EQU CYREG_PRT3_PC7
Pin_0__0__PORT EQU 3
Pin_0__0__SHIFT EQU 7
Pin_0__AG EQU CYREG_PRT3_AG
Pin_0__AMUX EQU CYREG_PRT3_AMUX
Pin_0__BIE EQU CYREG_PRT3_BIE
Pin_0__BIT_MASK EQU CYREG_PRT3_BIT_MASK
Pin_0__BYP EQU CYREG_PRT3_BYP
Pin_0__CTL EQU CYREG_PRT3_CTL
Pin_0__DM0 EQU CYREG_PRT3_DM0
Pin_0__DM1 EQU CYREG_PRT3_DM1
Pin_0__DM2 EQU CYREG_PRT3_DM2
Pin_0__DR EQU CYREG_PRT3_DR
Pin_0__INP_DIS EQU CYREG_PRT3_INP_DIS
Pin_0__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU3_BASE
Pin_0__LCD_COM_SEG EQU CYREG_PRT3_LCD_COM_SEG
Pin_0__LCD_EN EQU CYREG_PRT3_LCD_EN
Pin_0__MASK EQU 0x80
Pin_0__PORT EQU 3
Pin_0__PRT EQU CYREG_PRT3_PRT
Pin_0__PRTDSI__CAPS_SEL EQU CYREG_PRT3_CAPS_SEL
Pin_0__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT3_DBL_SYNC_IN
Pin_0__PRTDSI__OE_SEL0 EQU CYREG_PRT3_OE_SEL0
Pin_0__PRTDSI__OE_SEL1 EQU CYREG_PRT3_OE_SEL1
Pin_0__PRTDSI__OUT_SEL0 EQU CYREG_PRT3_OUT_SEL0
Pin_0__PRTDSI__OUT_SEL1 EQU CYREG_PRT3_OUT_SEL1
Pin_0__PRTDSI__SYNC_OUT EQU CYREG_PRT3_SYNC_OUT
Pin_0__PS EQU CYREG_PRT3_PS
Pin_0__SHIFT EQU 7
Pin_0__SLW EQU CYREG_PRT3_SLW

; Pin_1
Pin_1__0__INTTYPE EQU CYREG_PICU3_INTTYPE6
Pin_1__0__MASK EQU 0x40
Pin_1__0__PC EQU CYREG_PRT3_PC6
Pin_1__0__PORT EQU 3
Pin_1__0__SHIFT EQU 6
Pin_1__AG EQU CYREG_PRT3_AG
Pin_1__AMUX EQU CYREG_PRT3_AMUX
Pin_1__BIE EQU CYREG_PRT3_BIE
Pin_1__BIT_MASK EQU CYREG_PRT3_BIT_MASK
Pin_1__BYP EQU CYREG_PRT3_BYP
Pin_1__CTL EQU CYREG_PRT3_CTL
Pin_1__DM0 EQU CYREG_PRT3_DM0
Pin_1__DM1 EQU CYREG_PRT3_DM1
Pin_1__DM2 EQU CYREG_PRT3_DM2
Pin_1__DR EQU CYREG_PRT3_DR
Pin_1__INP_DIS EQU CYREG_PRT3_INP_DIS
Pin_1__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU3_BASE
Pin_1__LCD_COM_SEG EQU CYREG_PRT3_LCD_COM_SEG
Pin_1__LCD_EN EQU CYREG_PRT3_LCD_EN
Pin_1__MASK EQU 0x40
Pin_1__PORT EQU 3
Pin_1__PRT EQU CYREG_PRT3_PRT
Pin_1__PRTDSI__CAPS_SEL EQU CYREG_PRT3_CAPS_SEL
Pin_1__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT3_DBL_SYNC_IN
Pin_1__PRTDSI__OE_SEL0 EQU CYREG_PRT3_OE_SEL0
Pin_1__PRTDSI__OE_SEL1 EQU CYREG_PRT3_OE_SEL1
Pin_1__PRTDSI__OUT_SEL0 EQU CYREG_PRT3_OUT_SEL0
Pin_1__PRTDSI__OUT_SEL1 EQU CYREG_PRT3_OUT_SEL1
Pin_1__PRTDSI__SYNC_OUT EQU CYREG_PRT3_SYNC_OUT
Pin_1__PS EQU CYREG_PRT3_PS
Pin_1__SHIFT EQU 6
Pin_1__SLW EQU CYREG_PRT3_SLW

; Pin_2
Pin_2__0__INTTYPE EQU CYREG_PICU3_INTTYPE5
Pin_2__0__MASK EQU 0x20
Pin_2__0__PC EQU CYREG_PRT3_PC5
Pin_2__0__PORT EQU 3
Pin_2__0__SHIFT EQU 5
Pin_2__AG EQU CYREG_PRT3_AG
Pin_2__AMUX EQU CYREG_PRT3_AMUX
Pin_2__BIE EQU CYREG_PRT3_BIE
Pin_2__BIT_MASK EQU CYREG_PRT3_BIT_MASK
Pin_2__BYP EQU CYREG_PRT3_BYP
Pin_2__CTL EQU CYREG_PRT3_CTL
Pin_2__DM0 EQU CYREG_PRT3_DM0
Pin_2__DM1 EQU CYREG_PRT3_DM1
Pin_2__DM2 EQU CYREG_PRT3_DM2
Pin_2__DR EQU CYREG_PRT3_DR
Pin_2__INP_DIS EQU CYREG_PRT3_INP_DIS
Pin_2__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU3_BASE
Pin_2__LCD_COM_SEG EQU CYREG_PRT3_LCD_COM_SEG
Pin_2__LCD_EN EQU CYREG_PRT3_LCD_EN
Pin_2__MASK EQU 0x20
Pin_2__PORT EQU 3
Pin_2__PRT EQU CYREG_PRT3_PRT
Pin_2__PRTDSI__CAPS_SEL EQU CYREG_PRT3_CAPS_SEL
Pin_2__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT3_DBL_SYNC_IN
Pin_2__PRTDSI__OE_SEL0 EQU CYREG_PRT3_OE_SEL0
Pin_2__PRTDSI__OE_SEL1 EQU CYREG_PRT3_OE_SEL1
Pin_2__PRTDSI__OUT_SEL0 EQU CYREG_PRT3_OUT_SEL0
Pin_2__PRTDSI__OUT_SEL1 EQU CYREG_PRT3_OUT_SEL1
Pin_2__PRTDSI__SYNC_OUT EQU CYREG_PRT3_SYNC_OUT
Pin_2__PS EQU CYREG_PRT3_PS
Pin_2__SHIFT EQU 5
Pin_2__SLW EQU CYREG_PRT3_SLW

; Pin_3
Pin_3__0__INTTYPE EQU CYREG_PICU3_INTTYPE4
Pin_3__0__MASK EQU 0x10
Pin_3__0__PC EQU CYREG_PRT3_PC4
Pin_3__0__PORT EQU 3
Pin_3__0__SHIFT EQU 4
Pin_3__AG EQU CYREG_PRT3_AG
Pin_3__AMUX EQU CYREG_PRT3_AMUX
Pin_3__BIE EQU CYREG_PRT3_BIE
Pin_3__BIT_MASK EQU CYREG_PRT3_BIT_MASK
Pin_3__BYP EQU CYREG_PRT3_BYP
Pin_3__CTL EQU CYREG_PRT3_CTL
Pin_3__DM0 EQU CYREG_PRT3_DM0
Pin_3__DM1 EQU CYREG_PRT3_DM1
Pin_3__DM2 EQU CYREG_PRT3_DM2
Pin_3__DR EQU CYREG_PRT3_DR
Pin_3__INP_DIS EQU CYREG_PRT3_INP_DIS
Pin_3__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU3_BASE
Pin_3__LCD_COM_SEG EQU CYREG_PRT3_LCD_COM_SEG
Pin_3__LCD_EN EQU CYREG_PRT3_LCD_EN
Pin_3__MASK EQU 0x10
Pin_3__PORT EQU 3
Pin_3__PRT EQU CYREG_PRT3_PRT
Pin_3__PRTDSI__CAPS_SEL EQU CYREG_PRT3_CAPS_SEL
Pin_3__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT3_DBL_SYNC_IN
Pin_3__PRTDSI__OE_SEL0 EQU CYREG_PRT3_OE_SEL0
Pin_3__PRTDSI__OE_SEL1 EQU CYREG_PRT3_OE_SEL1
Pin_3__PRTDSI__OUT_SEL0 EQU CYREG_PRT3_OUT_SEL0
Pin_3__PRTDSI__OUT_SEL1 EQU CYREG_PRT3_OUT_SEL1
Pin_3__PRTDSI__SYNC_OUT EQU CYREG_PRT3_SYNC_OUT
Pin_3__PS EQU CYREG_PRT3_PS
Pin_3__SHIFT EQU 4
Pin_3__SLW EQU CYREG_PRT3_SLW

; Pin_4
Pin_4__0__INTTYPE EQU CYREG_PICU3_INTTYPE3
Pin_4__0__MASK EQU 0x08
Pin_4__0__PC EQU CYREG_PRT3_PC3
Pin_4__0__PORT EQU 3
Pin_4__0__SHIFT EQU 3
Pin_4__AG EQU CYREG_PRT3_AG
Pin_4__AMUX EQU CYREG_PRT3_AMUX
Pin_4__BIE EQU CYREG_PRT3_BIE
Pin_4__BIT_MASK EQU CYREG_PRT3_BIT_MASK
Pin_4__BYP EQU CYREG_PRT3_BYP
Pin_4__CTL EQU CYREG_PRT3_CTL
Pin_4__DM0 EQU CYREG_PRT3_DM0
Pin_4__DM1 EQU CYREG_PRT3_DM1
Pin_4__DM2 EQU CYREG_PRT3_DM2
Pin_4__DR EQU CYREG_PRT3_DR
Pin_4__INP_DIS EQU CYREG_PRT3_INP_DIS
Pin_4__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU3_BASE
Pin_4__LCD_COM_SEG EQU CYREG_PRT3_LCD_COM_SEG
Pin_4__LCD_EN EQU CYREG_PRT3_LCD_EN
Pin_4__MASK EQU 0x08
Pin_4__PORT EQU 3
Pin_4__PRT EQU CYREG_PRT3_PRT
Pin_4__PRTDSI__CAPS_SEL EQU CYREG_PRT3_CAPS_SEL
Pin_4__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT3_DBL_SYNC_IN
Pin_4__PRTDSI__OE_SEL0 EQU CYREG_PRT3_OE_SEL0
Pin_4__PRTDSI__OE_SEL1 EQU CYREG_PRT3_OE_SEL1
Pin_4__PRTDSI__OUT_SEL0 EQU CYREG_PRT3_OUT_SEL0
Pin_4__PRTDSI__OUT_SEL1 EQU CYREG_PRT3_OUT_SEL1
Pin_4__PRTDSI__SYNC_OUT EQU CYREG_PRT3_SYNC_OUT
Pin_4__PS EQU CYREG_PRT3_PS
Pin_4__SHIFT EQU 3
Pin_4__SLW EQU CYREG_PRT3_SLW

; Pin_5
Pin_5__0__INTTYPE EQU CYREG_PICU3_INTTYPE2
Pin_5__0__MASK EQU 0x04
Pin_5__0__PC EQU CYREG_PRT3_PC2
Pin_5__0__PORT EQU 3
Pin_5__0__SHIFT EQU 2
Pin_5__AG EQU CYREG_PRT3_AG
Pin_5__AMUX EQU CYREG_PRT3_AMUX
Pin_5__BIE EQU CYREG_PRT3_BIE
Pin_5__BIT_MASK EQU CYREG_PRT3_BIT_MASK
Pin_5__BYP EQU CYREG_PRT3_BYP
Pin_5__CTL EQU CYREG_PRT3_CTL
Pin_5__DM0 EQU CYREG_PRT3_DM0
Pin_5__DM1 EQU CYREG_PRT3_DM1
Pin_5__DM2 EQU CYREG_PRT3_DM2
Pin_5__DR EQU CYREG_PRT3_DR
Pin_5__INP_DIS EQU CYREG_PRT3_INP_DIS
Pin_5__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU3_BASE
Pin_5__LCD_COM_SEG EQU CYREG_PRT3_LCD_COM_SEG
Pin_5__LCD_EN EQU CYREG_PRT3_LCD_EN
Pin_5__MASK EQU 0x04
Pin_5__PORT EQU 3
Pin_5__PRT EQU CYREG_PRT3_PRT
Pin_5__PRTDSI__CAPS_SEL EQU CYREG_PRT3_CAPS_SEL
Pin_5__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT3_DBL_SYNC_IN
Pin_5__PRTDSI__OE_SEL0 EQU CYREG_PRT3_OE_SEL0
Pin_5__PRTDSI__OE_SEL1 EQU CYREG_PRT3_OE_SEL1
Pin_5__PRTDSI__OUT_SEL0 EQU CYREG_PRT3_OUT_SEL0
Pin_5__PRTDSI__OUT_SEL1 EQU CYREG_PRT3_OUT_SEL1
Pin_5__PRTDSI__SYNC_OUT EQU CYREG_PRT3_SYNC_OUT
Pin_5__PS EQU CYREG_PRT3_PS
Pin_5__SHIFT EQU 2
Pin_5__SLW EQU CYREG_PRT3_SLW

; Pin_6
Pin_6__0__INTTYPE EQU CYREG_PICU3_INTTYPE1
Pin_6__0__MASK EQU 0x02
Pin_6__0__PC EQU CYREG_PRT3_PC1
Pin_6__0__PORT EQU 3
Pin_6__0__SHIFT EQU 1
Pin_6__AG EQU CYREG_PRT3_AG
Pin_6__AMUX EQU CYREG_PRT3_AMUX
Pin_6__BIE EQU CYREG_PRT3_BIE
Pin_6__BIT_MASK EQU CYREG_PRT3_BIT_MASK
Pin_6__BYP EQU CYREG_PRT3_BYP
Pin_6__CTL EQU CYREG_PRT3_CTL
Pin_6__DM0 EQU CYREG_PRT3_DM0
Pin_6__DM1 EQU CYREG_PRT3_DM1
Pin_6__DM2 EQU CYREG_PRT3_DM2
Pin_6__DR EQU CYREG_PRT3_DR
Pin_6__INP_DIS EQU CYREG_PRT3_INP_DIS
Pin_6__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU3_BASE
Pin_6__LCD_COM_SEG EQU CYREG_PRT3_LCD_COM_SEG
Pin_6__LCD_EN EQU CYREG_PRT3_LCD_EN
Pin_6__MASK EQU 0x02
Pin_6__PORT EQU 3
Pin_6__PRT EQU CYREG_PRT3_PRT
Pin_6__PRTDSI__CAPS_SEL EQU CYREG_PRT3_CAPS_SEL
Pin_6__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT3_DBL_SYNC_IN
Pin_6__PRTDSI__OE_SEL0 EQU CYREG_PRT3_OE_SEL0
Pin_6__PRTDSI__OE_SEL1 EQU CYREG_PRT3_OE_SEL1
Pin_6__PRTDSI__OUT_SEL0 EQU CYREG_PRT3_OUT_SEL0
Pin_6__PRTDSI__OUT_SEL1 EQU CYREG_PRT3_OUT_SEL1
Pin_6__PRTDSI__SYNC_OUT EQU CYREG_PRT3_SYNC_OUT
Pin_6__PS EQU CYREG_PRT3_PS
Pin_6__SHIFT EQU 1
Pin_6__SLW EQU CYREG_PRT3_SLW

; Pin_7
Pin_7__0__INTTYPE EQU CYREG_PICU3_INTTYPE0
Pin_7__0__MASK EQU 0x01
Pin_7__0__PC EQU CYREG_PRT3_PC0
Pin_7__0__PORT EQU 3
Pin_7__0__SHIFT EQU 0
Pin_7__AG EQU CYREG_PRT3_AG
Pin_7__AMUX EQU CYREG_PRT3_AMUX
Pin_7__BIE EQU CYREG_PRT3_BIE
Pin_7__BIT_MASK EQU CYREG_PRT3_BIT_MASK
Pin_7__BYP EQU CYREG_PRT3_BYP
Pin_7__CTL EQU CYREG_PRT3_CTL
Pin_7__DM0 EQU CYREG_PRT3_DM0
Pin_7__DM1 EQU CYREG_PRT3_DM1
Pin_7__DM2 EQU CYREG_PRT3_DM2
Pin_7__DR EQU CYREG_PRT3_DR
Pin_7__INP_DIS EQU CYREG_PRT3_INP_DIS
Pin_7__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU3_BASE
Pin_7__LCD_COM_SEG EQU CYREG_PRT3_LCD_COM_SEG
Pin_7__LCD_EN EQU CYREG_PRT3_LCD_EN
Pin_7__MASK EQU 0x01
Pin_7__PORT EQU 3
Pin_7__PRT EQU CYREG_PRT3_PRT
Pin_7__PRTDSI__CAPS_SEL EQU CYREG_PRT3_CAPS_SEL
Pin_7__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT3_DBL_SYNC_IN
Pin_7__PRTDSI__OE_SEL0 EQU CYREG_PRT3_OE_SEL0
Pin_7__PRTDSI__OE_SEL1 EQU CYREG_PRT3_OE_SEL1
Pin_7__PRTDSI__OUT_SEL0 EQU CYREG_PRT3_OUT_SEL0
Pin_7__PRTDSI__OUT_SEL1 EQU CYREG_PRT3_OUT_SEL1
Pin_7__PRTDSI__SYNC_OUT EQU CYREG_PRT3_SYNC_OUT
Pin_7__PS EQU CYREG_PRT3_PS
Pin_7__SHIFT EQU 0
Pin_7__SLW EQU CYREG_PRT3_SLW

; Pin_9
Pin_9__0__INTTYPE EQU CYREG_PICU12_INTTYPE6
Pin_9__0__MASK EQU 0x40
Pin_9__0__PC EQU CYREG_PRT12_PC6
Pin_9__0__PORT EQU 12
Pin_9__0__SHIFT EQU 6
Pin_9__AG EQU CYREG_PRT12_AG
Pin_9__BIE EQU CYREG_PRT12_BIE
Pin_9__BIT_MASK EQU CYREG_PRT12_BIT_MASK
Pin_9__BYP EQU CYREG_PRT12_BYP
Pin_9__DM0 EQU CYREG_PRT12_DM0
Pin_9__DM1 EQU CYREG_PRT12_DM1
Pin_9__DM2 EQU CYREG_PRT12_DM2
Pin_9__DR EQU CYREG_PRT12_DR
Pin_9__INP_DIS EQU CYREG_PRT12_INP_DIS
Pin_9__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU12_BASE
Pin_9__MASK EQU 0x40
Pin_9__PORT EQU 12
Pin_9__PRT EQU CYREG_PRT12_PRT
Pin_9__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT12_DBL_SYNC_IN
Pin_9__PRTDSI__OE_SEL0 EQU CYREG_PRT12_OE_SEL0
Pin_9__PRTDSI__OE_SEL1 EQU CYREG_PRT12_OE_SEL1
Pin_9__PRTDSI__OUT_SEL0 EQU CYREG_PRT12_OUT_SEL0
Pin_9__PRTDSI__OUT_SEL1 EQU CYREG_PRT12_OUT_SEL1
Pin_9__PRTDSI__SYNC_OUT EQU CYREG_PRT12_SYNC_OUT
Pin_9__PS EQU CYREG_PRT12_PS
Pin_9__SHIFT EQU 6
Pin_9__SIO_CFG EQU CYREG_PRT12_SIO_CFG
Pin_9__SIO_DIFF EQU CYREG_PRT12_SIO_DIFF
Pin_9__SIO_HYST_EN EQU CYREG_PRT12_SIO_HYST_EN
Pin_9__SIO_REG_HIFREQ EQU CYREG_PRT12_SIO_REG_HIFREQ
Pin_9__SLW EQU CYREG_PRT12_SLW

; Timer
Timer_TimerUDB_rstSts_stsreg__0__MASK EQU 0x01
Timer_TimerUDB_rstSts_stsreg__0__POS EQU 0
Timer_TimerUDB_rstSts_stsreg__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB11_12_ACTL
Timer_TimerUDB_rstSts_stsreg__16BIT_STATUS_REG EQU CYREG_B0_UDB11_12_ST
Timer_TimerUDB_rstSts_stsreg__2__MASK EQU 0x04
Timer_TimerUDB_rstSts_stsreg__2__POS EQU 2
Timer_TimerUDB_rstSts_stsreg__3__MASK EQU 0x08
Timer_TimerUDB_rstSts_stsreg__3__POS EQU 3
Timer_TimerUDB_rstSts_stsreg__MASK EQU 0x0D
Timer_TimerUDB_rstSts_stsreg__MASK_REG EQU CYREG_B0_UDB11_MSK
Timer_TimerUDB_rstSts_stsreg__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB11_ACTL
Timer_TimerUDB_rstSts_stsreg__STATUS_REG EQU CYREG_B0_UDB11_ST
Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB09_10_ACTL
Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_CONTROL_REG EQU CYREG_B0_UDB09_10_CTL
Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_COUNT_REG EQU CYREG_B0_UDB09_10_CTL
Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_COUNT_CONTROL_REG EQU CYREG_B0_UDB09_10_CTL
Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_COUNT_COUNT_REG EQU CYREG_B0_UDB09_10_CTL
Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_MASK_MASK_REG EQU CYREG_B0_UDB09_10_MSK
Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_MASK_PERIOD_REG EQU CYREG_B0_UDB09_10_MSK
Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_PERIOD_MASK_REG EQU CYREG_B0_UDB09_10_MSK
Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_PERIOD_PERIOD_REG EQU CYREG_B0_UDB09_10_MSK
Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__7__MASK EQU 0x80
Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__7__POS EQU 7
Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB09_ACTL
Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG EQU CYREG_B0_UDB09_CTL
Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_ST_REG EQU CYREG_B0_UDB09_ST_CTL
Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__COUNT_REG EQU CYREG_B0_UDB09_CTL
Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__COUNT_ST_REG EQU CYREG_B0_UDB09_ST_CTL
Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__MASK EQU 0x80
Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__MASK_CTL_AUX_CTL_REG EQU CYREG_B0_UDB09_MSK_ACTL
Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__PER_CTL_AUX_CTL_REG EQU CYREG_B0_UDB09_MSK_ACTL
Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__PERIOD_REG EQU CYREG_B0_UDB09_MSK
Timer_TimerUDB_sT32_timerdp_u0__16BIT_A0_REG EQU CYREG_B0_UDB08_09_A0
Timer_TimerUDB_sT32_timerdp_u0__16BIT_A1_REG EQU CYREG_B0_UDB08_09_A1
Timer_TimerUDB_sT32_timerdp_u0__16BIT_D0_REG EQU CYREG_B0_UDB08_09_D0
Timer_TimerUDB_sT32_timerdp_u0__16BIT_D1_REG EQU CYREG_B0_UDB08_09_D1
Timer_TimerUDB_sT32_timerdp_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB08_09_ACTL
Timer_TimerUDB_sT32_timerdp_u0__16BIT_F0_REG EQU CYREG_B0_UDB08_09_F0
Timer_TimerUDB_sT32_timerdp_u0__16BIT_F1_REG EQU CYREG_B0_UDB08_09_F1
Timer_TimerUDB_sT32_timerdp_u0__A0_A1_REG EQU CYREG_B0_UDB08_A0_A1
Timer_TimerUDB_sT32_timerdp_u0__A0_REG EQU CYREG_B0_UDB08_A0
Timer_TimerUDB_sT32_timerdp_u0__A1_REG EQU CYREG_B0_UDB08_A1
Timer_TimerUDB_sT32_timerdp_u0__D0_D1_REG EQU CYREG_B0_UDB08_D0_D1
Timer_TimerUDB_sT32_timerdp_u0__D0_REG EQU CYREG_B0_UDB08_D0
Timer_TimerUDB_sT32_timerdp_u0__D1_REG EQU CYREG_B0_UDB08_D1
Timer_TimerUDB_sT32_timerdp_u0__DP_AUX_CTL_REG EQU CYREG_B0_UDB08_ACTL
Timer_TimerUDB_sT32_timerdp_u0__F0_F1_REG EQU CYREG_B0_UDB08_F0_F1
Timer_TimerUDB_sT32_timerdp_u0__F0_REG EQU CYREG_B0_UDB08_F0
Timer_TimerUDB_sT32_timerdp_u0__F1_REG EQU CYREG_B0_UDB08_F1
Timer_TimerUDB_sT32_timerdp_u1__16BIT_A0_REG EQU CYREG_B0_UDB09_10_A0
Timer_TimerUDB_sT32_timerdp_u1__16BIT_A1_REG EQU CYREG_B0_UDB09_10_A1
Timer_TimerUDB_sT32_timerdp_u1__16BIT_D0_REG EQU CYREG_B0_UDB09_10_D0
Timer_TimerUDB_sT32_timerdp_u1__16BIT_D1_REG EQU CYREG_B0_UDB09_10_D1
Timer_TimerUDB_sT32_timerdp_u1__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB09_10_ACTL
Timer_TimerUDB_sT32_timerdp_u1__16BIT_F0_REG EQU CYREG_B0_UDB09_10_F0
Timer_TimerUDB_sT32_timerdp_u1__16BIT_F1_REG EQU CYREG_B0_UDB09_10_F1
Timer_TimerUDB_sT32_timerdp_u1__A0_A1_REG EQU CYREG_B0_UDB09_A0_A1
Timer_TimerUDB_sT32_timerdp_u1__A0_REG EQU CYREG_B0_UDB09_A0
Timer_TimerUDB_sT32_timerdp_u1__A1_REG EQU CYREG_B0_UDB09_A1
Timer_TimerUDB_sT32_timerdp_u1__D0_D1_REG EQU CYREG_B0_UDB09_D0_D1
Timer_TimerUDB_sT32_timerdp_u1__D0_REG EQU CYREG_B0_UDB09_D0
Timer_TimerUDB_sT32_timerdp_u1__D1_REG EQU CYREG_B0_UDB09_D1
Timer_TimerUDB_sT32_timerdp_u1__DP_AUX_CTL_REG EQU CYREG_B0_UDB09_ACTL
Timer_TimerUDB_sT32_timerdp_u1__F0_F1_REG EQU CYREG_B0_UDB09_F0_F1
Timer_TimerUDB_sT32_timerdp_u1__F0_REG EQU CYREG_B0_UDB09_F0
Timer_TimerUDB_sT32_timerdp_u1__F1_REG EQU CYREG_B0_UDB09_F1
Timer_TimerUDB_sT32_timerdp_u1__MSK_DP_AUX_CTL_REG EQU CYREG_B0_UDB09_MSK_ACTL
Timer_TimerUDB_sT32_timerdp_u1__PER_DP_AUX_CTL_REG EQU CYREG_B0_UDB09_MSK_ACTL
Timer_TimerUDB_sT32_timerdp_u2__16BIT_A0_REG EQU CYREG_B0_UDB10_11_A0
Timer_TimerUDB_sT32_timerdp_u2__16BIT_A1_REG EQU CYREG_B0_UDB10_11_A1
Timer_TimerUDB_sT32_timerdp_u2__16BIT_D0_REG EQU CYREG_B0_UDB10_11_D0
Timer_TimerUDB_sT32_timerdp_u2__16BIT_D1_REG EQU CYREG_B0_UDB10_11_D1
Timer_TimerUDB_sT32_timerdp_u2__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB10_11_ACTL
Timer_TimerUDB_sT32_timerdp_u2__16BIT_F0_REG EQU CYREG_B0_UDB10_11_F0
Timer_TimerUDB_sT32_timerdp_u2__16BIT_F1_REG EQU CYREG_B0_UDB10_11_F1
Timer_TimerUDB_sT32_timerdp_u2__A0_A1_REG EQU CYREG_B0_UDB10_A0_A1
Timer_TimerUDB_sT32_timerdp_u2__A0_REG EQU CYREG_B0_UDB10_A0
Timer_TimerUDB_sT32_timerdp_u2__A1_REG EQU CYREG_B0_UDB10_A1
Timer_TimerUDB_sT32_timerdp_u2__D0_D1_REG EQU CYREG_B0_UDB10_D0_D1
Timer_TimerUDB_sT32_timerdp_u2__D0_REG EQU CYREG_B0_UDB10_D0
Timer_TimerUDB_sT32_timerdp_u2__D1_REG EQU CYREG_B0_UDB10_D1
Timer_TimerUDB_sT32_timerdp_u2__DP_AUX_CTL_REG EQU CYREG_B0_UDB10_ACTL
Timer_TimerUDB_sT32_timerdp_u2__F0_F1_REG EQU CYREG_B0_UDB10_F0_F1
Timer_TimerUDB_sT32_timerdp_u2__F0_REG EQU CYREG_B0_UDB10_F0
Timer_TimerUDB_sT32_timerdp_u2__F1_REG EQU CYREG_B0_UDB10_F1
Timer_TimerUDB_sT32_timerdp_u3__16BIT_A0_REG EQU CYREG_B0_UDB11_12_A0
Timer_TimerUDB_sT32_timerdp_u3__16BIT_A1_REG EQU CYREG_B0_UDB11_12_A1
Timer_TimerUDB_sT32_timerdp_u3__16BIT_D0_REG EQU CYREG_B0_UDB11_12_D0
Timer_TimerUDB_sT32_timerdp_u3__16BIT_D1_REG EQU CYREG_B0_UDB11_12_D1
Timer_TimerUDB_sT32_timerdp_u3__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB11_12_ACTL
Timer_TimerUDB_sT32_timerdp_u3__16BIT_F0_REG EQU CYREG_B0_UDB11_12_F0
Timer_TimerUDB_sT32_timerdp_u3__16BIT_F1_REG EQU CYREG_B0_UDB11_12_F1
Timer_TimerUDB_sT32_timerdp_u3__A0_A1_REG EQU CYREG_B0_UDB11_A0_A1
Timer_TimerUDB_sT32_timerdp_u3__A0_REG EQU CYREG_B0_UDB11_A0
Timer_TimerUDB_sT32_timerdp_u3__A1_REG EQU CYREG_B0_UDB11_A1
Timer_TimerUDB_sT32_timerdp_u3__D0_D1_REG EQU CYREG_B0_UDB11_D0_D1
Timer_TimerUDB_sT32_timerdp_u3__D0_REG EQU CYREG_B0_UDB11_D0
Timer_TimerUDB_sT32_timerdp_u3__D1_REG EQU CYREG_B0_UDB11_D1
Timer_TimerUDB_sT32_timerdp_u3__DP_AUX_CTL_REG EQU CYREG_B0_UDB11_ACTL
Timer_TimerUDB_sT32_timerdp_u3__F0_F1_REG EQU CYREG_B0_UDB11_F0_F1
Timer_TimerUDB_sT32_timerdp_u3__F0_REG EQU CYREG_B0_UDB11_F0
Timer_TimerUDB_sT32_timerdp_u3__F1_REG EQU CYREG_B0_UDB11_F1

; Clock_1
Clock_1__CFG0 EQU CYREG_CLKDIST_DCFG0_CFG0
Clock_1__CFG1 EQU CYREG_CLKDIST_DCFG0_CFG1
Clock_1__CFG2 EQU CYREG_CLKDIST_DCFG0_CFG2
Clock_1__CFG2_SRC_SEL_MASK EQU 0x07
Clock_1__INDEX EQU 0x00
Clock_1__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
Clock_1__PM_ACT_MSK EQU 0x01
Clock_1__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
Clock_1__PM_STBY_MSK EQU 0x01

; GraphicLCDIntf_1
GraphicLCDIntf_1_GraphLcd8_Lsb__16BIT_A0_REG EQU CYREG_B1_UDB06_07_A0
GraphicLCDIntf_1_GraphLcd8_Lsb__16BIT_A1_REG EQU CYREG_B1_UDB06_07_A1
GraphicLCDIntf_1_GraphLcd8_Lsb__16BIT_D0_REG EQU CYREG_B1_UDB06_07_D0
GraphicLCDIntf_1_GraphLcd8_Lsb__16BIT_D1_REG EQU CYREG_B1_UDB06_07_D1
GraphicLCDIntf_1_GraphLcd8_Lsb__16BIT_DP_AUX_CTL_REG EQU CYREG_B1_UDB06_07_ACTL
GraphicLCDIntf_1_GraphLcd8_Lsb__16BIT_F0_REG EQU CYREG_B1_UDB06_07_F0
GraphicLCDIntf_1_GraphLcd8_Lsb__16BIT_F1_REG EQU CYREG_B1_UDB06_07_F1
GraphicLCDIntf_1_GraphLcd8_Lsb__A0_A1_REG EQU CYREG_B1_UDB06_A0_A1
GraphicLCDIntf_1_GraphLcd8_Lsb__A0_REG EQU CYREG_B1_UDB06_A0
GraphicLCDIntf_1_GraphLcd8_Lsb__A1_REG EQU CYREG_B1_UDB06_A1
GraphicLCDIntf_1_GraphLcd8_Lsb__D0_D1_REG EQU CYREG_B1_UDB06_D0_D1
GraphicLCDIntf_1_GraphLcd8_Lsb__D0_REG EQU CYREG_B1_UDB06_D0
GraphicLCDIntf_1_GraphLcd8_Lsb__D1_REG EQU CYREG_B1_UDB06_D1
GraphicLCDIntf_1_GraphLcd8_Lsb__DP_AUX_CTL_REG EQU CYREG_B1_UDB06_ACTL
GraphicLCDIntf_1_GraphLcd8_Lsb__F0_F1_REG EQU CYREG_B1_UDB06_F0_F1
GraphicLCDIntf_1_GraphLcd8_Lsb__F0_REG EQU CYREG_B1_UDB06_F0
GraphicLCDIntf_1_GraphLcd8_Lsb__F1_REG EQU CYREG_B1_UDB06_F1
GraphicLCDIntf_1_GraphLcd8_Lsb__MSK_DP_AUX_CTL_REG EQU CYREG_B1_UDB06_MSK_ACTL
GraphicLCDIntf_1_GraphLcd8_Lsb__PER_DP_AUX_CTL_REG EQU CYREG_B1_UDB06_MSK_ACTL
GraphicLCDIntf_1_GraphLcd8_Lsb_PO__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_B1_UDB06_07_ACTL
GraphicLCDIntf_1_GraphLcd8_Lsb_PO__16BIT_CONTROL_CONTROL_REG EQU CYREG_B1_UDB06_07_CTL
GraphicLCDIntf_1_GraphLcd8_Lsb_PO__16BIT_CONTROL_COUNT_REG EQU CYREG_B1_UDB06_07_CTL
GraphicLCDIntf_1_GraphLcd8_Lsb_PO__16BIT_COUNT_CONTROL_REG EQU CYREG_B1_UDB06_07_CTL
GraphicLCDIntf_1_GraphLcd8_Lsb_PO__16BIT_COUNT_COUNT_REG EQU CYREG_B1_UDB06_07_CTL
GraphicLCDIntf_1_GraphLcd8_Lsb_PO__16BIT_MASK_MASK_REG EQU CYREG_B1_UDB06_07_MSK
GraphicLCDIntf_1_GraphLcd8_Lsb_PO__16BIT_MASK_PERIOD_REG EQU CYREG_B1_UDB06_07_MSK
GraphicLCDIntf_1_GraphLcd8_Lsb_PO__16BIT_PERIOD_MASK_REG EQU CYREG_B1_UDB06_07_MSK
GraphicLCDIntf_1_GraphLcd8_Lsb_PO__16BIT_PERIOD_PERIOD_REG EQU CYREG_B1_UDB06_07_MSK
GraphicLCDIntf_1_GraphLcd8_Lsb_PO__CONTROL_AUX_CTL_REG EQU CYREG_B1_UDB06_ACTL
GraphicLCDIntf_1_GraphLcd8_Lsb_PO__CONTROL_REG EQU CYREG_B1_UDB06_CTL
GraphicLCDIntf_1_GraphLcd8_Lsb_PO__CONTROL_ST_REG EQU CYREG_B1_UDB06_ST_CTL
GraphicLCDIntf_1_GraphLcd8_Lsb_PO__COUNT_REG EQU CYREG_B1_UDB06_CTL
GraphicLCDIntf_1_GraphLcd8_Lsb_PO__COUNT_ST_REG EQU CYREG_B1_UDB06_ST_CTL
GraphicLCDIntf_1_GraphLcd8_Lsb_PO__MASK_CTL_AUX_CTL_REG EQU CYREG_B1_UDB06_MSK_ACTL
GraphicLCDIntf_1_GraphLcd8_Lsb_PO__PER_CTL_AUX_CTL_REG EQU CYREG_B1_UDB06_MSK_ACTL
GraphicLCDIntf_1_GraphLcd8_Lsb_PO__PERIOD_REG EQU CYREG_B1_UDB06_MSK
GraphicLCDIntf_1_LsbReg__0__MASK EQU 0x01
GraphicLCDIntf_1_LsbReg__0__POS EQU 0
GraphicLCDIntf_1_LsbReg__1__MASK EQU 0x02
GraphicLCDIntf_1_LsbReg__1__POS EQU 1
GraphicLCDIntf_1_LsbReg__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B1_UDB06_07_ACTL
GraphicLCDIntf_1_LsbReg__16BIT_STATUS_REG EQU CYREG_B1_UDB06_07_ST
GraphicLCDIntf_1_LsbReg__2__MASK EQU 0x04
GraphicLCDIntf_1_LsbReg__2__POS EQU 2
GraphicLCDIntf_1_LsbReg__3__MASK EQU 0x08
GraphicLCDIntf_1_LsbReg__3__POS EQU 3
GraphicLCDIntf_1_LsbReg__4__MASK EQU 0x10
GraphicLCDIntf_1_LsbReg__4__POS EQU 4
GraphicLCDIntf_1_LsbReg__5__MASK EQU 0x20
GraphicLCDIntf_1_LsbReg__5__POS EQU 5
GraphicLCDIntf_1_LsbReg__6__MASK EQU 0x40
GraphicLCDIntf_1_LsbReg__6__POS EQU 6
GraphicLCDIntf_1_LsbReg__7__MASK EQU 0x80
GraphicLCDIntf_1_LsbReg__7__POS EQU 7
GraphicLCDIntf_1_LsbReg__MASK EQU 0xFF
GraphicLCDIntf_1_LsbReg__MASK_REG EQU CYREG_B1_UDB06_MSK
GraphicLCDIntf_1_LsbReg__MASK_ST_AUX_CTL_REG EQU CYREG_B1_UDB06_MSK_ACTL
GraphicLCDIntf_1_LsbReg__PER_ST_AUX_CTL_REG EQU CYREG_B1_UDB06_MSK_ACTL
GraphicLCDIntf_1_LsbReg__STATUS_AUX_CTL_REG EQU CYREG_B1_UDB06_ACTL
GraphicLCDIntf_1_LsbReg__STATUS_CNT_REG EQU CYREG_B1_UDB06_ST_CTL
GraphicLCDIntf_1_LsbReg__STATUS_CONTROL_REG EQU CYREG_B1_UDB06_ST_CTL
GraphicLCDIntf_1_LsbReg__STATUS_REG EQU CYREG_B1_UDB06_ST
GraphicLCDIntf_1_StsReg__0__MASK EQU 0x01
GraphicLCDIntf_1_StsReg__0__POS EQU 0
GraphicLCDIntf_1_StsReg__1__MASK EQU 0x02
GraphicLCDIntf_1_StsReg__1__POS EQU 1
GraphicLCDIntf_1_StsReg__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B1_UDB07_08_ACTL
GraphicLCDIntf_1_StsReg__16BIT_STATUS_REG EQU CYREG_B1_UDB07_08_ST
GraphicLCDIntf_1_StsReg__MASK EQU 0x03
GraphicLCDIntf_1_StsReg__MASK_REG EQU CYREG_B1_UDB07_MSK
GraphicLCDIntf_1_StsReg__STATUS_AUX_CTL_REG EQU CYREG_B1_UDB07_ACTL
GraphicLCDIntf_1_StsReg__STATUS_REG EQU CYREG_B1_UDB07_ST

; Miscellaneous
BCLK__BUS_CLK__HZ EQU 24000000
BCLK__BUS_CLK__KHZ EQU 24000
BCLK__BUS_CLK__MHZ EQU 24
CYDEV_CHIP_DIE_LEOPARD EQU 1
CYDEV_CHIP_DIE_PSOC4A EQU 21
CYDEV_CHIP_DIE_PSOC5LP EQU 2
CYDEV_CHIP_DIE_PSOC5TM EQU 3
CYDEV_CHIP_DIE_TMA4 EQU 4
CYDEV_CHIP_DIE_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_FM0P EQU 5
CYDEV_CHIP_FAMILY_FM3 EQU 6
CYDEV_CHIP_FAMILY_FM4 EQU 7
CYDEV_CHIP_FAMILY_PSOC3 EQU 1
CYDEV_CHIP_FAMILY_PSOC4 EQU 2
CYDEV_CHIP_FAMILY_PSOC5 EQU 3
CYDEV_CHIP_FAMILY_PSOC6 EQU 4
CYDEV_CHIP_FAMILY_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_USED EQU CYDEV_CHIP_FAMILY_PSOC5
CYDEV_CHIP_JTAG_ID EQU 0x2E161069
CYDEV_CHIP_MEMBER_3A EQU 1
CYDEV_CHIP_MEMBER_4A EQU 21
CYDEV_CHIP_MEMBER_4D EQU 16
CYDEV_CHIP_MEMBER_4E EQU 6
CYDEV_CHIP_MEMBER_4F EQU 22
CYDEV_CHIP_MEMBER_4G EQU 4
CYDEV_CHIP_MEMBER_4H EQU 20
CYDEV_CHIP_MEMBER_4I EQU 26
CYDEV_CHIP_MEMBER_4J EQU 17
CYDEV_CHIP_MEMBER_4K EQU 18
CYDEV_CHIP_MEMBER_4L EQU 25
CYDEV_CHIP_MEMBER_4M EQU 24
CYDEV_CHIP_MEMBER_4N EQU 11
CYDEV_CHIP_MEMBER_4O EQU 8
CYDEV_CHIP_MEMBER_4P EQU 23
CYDEV_CHIP_MEMBER_4Q EQU 14
CYDEV_CHIP_MEMBER_4R EQU 9
CYDEV_CHIP_MEMBER_4S EQU 12
CYDEV_CHIP_MEMBER_4T EQU 10
CYDEV_CHIP_MEMBER_4U EQU 5
CYDEV_CHIP_MEMBER_4V EQU 19
CYDEV_CHIP_MEMBER_4W EQU 13
CYDEV_CHIP_MEMBER_4X EQU 7
CYDEV_CHIP_MEMBER_4Y EQU 15
CYDEV_CHIP_MEMBER_5A EQU 3
CYDEV_CHIP_MEMBER_5B EQU 2
CYDEV_CHIP_MEMBER_6A EQU 27
CYDEV_CHIP_MEMBER_FM3 EQU 31
CYDEV_CHIP_MEMBER_FM4 EQU 32
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 EQU 28
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 EQU 29
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 EQU 30
CYDEV_CHIP_MEMBER_UNKNOWN EQU 0
CYDEV_CHIP_MEMBER_USED EQU CYDEV_CHIP_MEMBER_5B
CYDEV_CHIP_DIE_EXPECT EQU CYDEV_CHIP_MEMBER_USED
CYDEV_CHIP_DIE_ACTUAL EQU CYDEV_CHIP_DIE_EXPECT
CYDEV_CHIP_REV_LEOPARD_ES1 EQU 0
CYDEV_CHIP_REV_LEOPARD_ES2 EQU 1
CYDEV_CHIP_REV_LEOPARD_ES3 EQU 3
CYDEV_CHIP_REV_LEOPARD_PRODUCTION EQU 3
CYDEV_CHIP_REV_PSOC4A_ES0 EQU 17
CYDEV_CHIP_REV_PSOC4A_PRODUCTION EQU 17
CYDEV_CHIP_REV_PSOC5LP_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5LP_PRODUCTION EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES1 EQU 1
CYDEV_CHIP_REV_PSOC5TM_PRODUCTION EQU 1
CYDEV_CHIP_REV_TMA4_ES EQU 17
CYDEV_CHIP_REV_TMA4_ES2 EQU 33
CYDEV_CHIP_REV_TMA4_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_3A_ES1 EQU 0
CYDEV_CHIP_REVISION_3A_ES2 EQU 1
CYDEV_CHIP_REVISION_3A_ES3 EQU 3
CYDEV_CHIP_REVISION_3A_PRODUCTION EQU 3
CYDEV_CHIP_REVISION_4A_ES0 EQU 17
CYDEV_CHIP_REVISION_4A_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4D_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD EQU 0
CYDEV_CHIP_REVISION_4E_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256K EQU 0
CYDEV_CHIP_REVISION_4G_ES EQU 17
CYDEV_CHIP_REVISION_4G_ES2 EQU 33
CYDEV_CHIP_REVISION_4G_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4H_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4I_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4J_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4K_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4L_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4M_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4N_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4O_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4P_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4Q_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4R_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4S_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4T_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4U_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4V_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4W_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4X_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4Y_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_5A_ES0 EQU 0
CYDEV_CHIP_REVISION_5A_ES1 EQU 1
CYDEV_CHIP_REVISION_5A_PRODUCTION EQU 1
CYDEV_CHIP_REVISION_5B_ES0 EQU 0
CYDEV_CHIP_REVISION_5B_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_6A_ES EQU 17
CYDEV_CHIP_REVISION_6A_NO_UDB EQU 33
CYDEV_CHIP_REVISION_6A_PRODUCTION EQU 33
CYDEV_CHIP_REVISION_FM3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_FM4_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_USED EQU CYDEV_CHIP_REVISION_5B_PRODUCTION
CYDEV_CHIP_REV_EXPECT EQU CYDEV_CHIP_REVISION_USED
CYDEV_CONFIG_FASTBOOT_ENABLED EQU 1
CYDEV_CONFIG_UNUSED_IO_AllowButWarn EQU 0
CYDEV_CONFIG_UNUSED_IO EQU CYDEV_CONFIG_UNUSED_IO_AllowButWarn
CYDEV_CONFIG_UNUSED_IO_AllowWithInfo EQU 1
CYDEV_CONFIG_UNUSED_IO_Disallowed EQU 2
CYDEV_CONFIGURATION_COMPRESSED EQU 1
CYDEV_CONFIGURATION_DMA EQU 0
CYDEV_CONFIGURATION_ECC EQU 1
CYDEV_CONFIGURATION_IMOENABLED EQU CYDEV_CONFIG_FASTBOOT_ENABLED
CYDEV_CONFIGURATION_MODE_COMPRESSED EQU 0
CYDEV_CONFIGURATION_MODE EQU CYDEV_CONFIGURATION_MODE_COMPRESSED
CYDEV_CONFIGURATION_MODE_DMA EQU 2
CYDEV_CONFIGURATION_MODE_UNCOMPRESSED EQU 1
CYDEV_DEBUG_ENABLE_MASK EQU 0x20
CYDEV_DEBUG_ENABLE_REGISTER EQU CYREG_MLOGIC_DEBUG
CYDEV_DEBUGGING_DPS_Disable EQU 3
CYDEV_DEBUGGING_DPS_JTAG_4 EQU 1
CYDEV_DEBUGGING_DPS_JTAG_5 EQU 0
CYDEV_DEBUGGING_DPS_SWD EQU 2
CYDEV_DEBUGGING_DPS EQU CYDEV_DEBUGGING_DPS_SWD
CYDEV_DEBUGGING_DPS_SWD_SWV EQU 6
CYDEV_DEBUGGING_ENABLE EQU 1
CYDEV_DEBUGGING_XRES EQU 0
CYDEV_DMA_CHANNELS_AVAILABLE EQU 24
CYDEV_ECC_ENABLE EQU 0
CYDEV_HEAP_SIZE EQU 0x80
CYDEV_INSTRUCT_CACHE_ENABLED EQU 1
CYDEV_INTR_RISING EQU 0x00000000
CYDEV_IS_EXPORTING_CODE EQU 0
CYDEV_IS_IMPORTING_CODE EQU 0
CYDEV_PROJ_TYPE EQU 0
CYDEV_PROJ_TYPE_BOOTLOADER EQU 1
CYDEV_PROJ_TYPE_LAUNCHER EQU 5
CYDEV_PROJ_TYPE_LOADABLE EQU 2
CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER EQU 4
CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER EQU 3
CYDEV_PROJ_TYPE_STANDARD EQU 0
CYDEV_PROTECTION_ENABLE EQU 0
CYDEV_STACK_SIZE EQU 0x0800
CYDEV_USE_BUNDLED_CMSIS EQU 1
CYDEV_VARIABLE_VDDA EQU 0
CYDEV_VDDA_MV EQU 5000
CYDEV_VDDD_MV EQU 5000
CYDEV_VDDIO0_MV EQU 5000
CYDEV_VDDIO1_MV EQU 5000
CYDEV_VDDIO2_MV EQU 5000
CYDEV_VDDIO3_MV EQU 5000
CYDEV_VIO0_MV EQU 5000
CYDEV_VIO1_MV EQU 5000
CYDEV_VIO2_MV EQU 5000
CYDEV_VIO3_MV EQU 5000
CYIPBLOCK_ARM_CM3_VERSION EQU 0
CYIPBLOCK_P3_ANAIF_VERSION EQU 0
CYIPBLOCK_P3_CAN_VERSION EQU 0
CYIPBLOCK_P3_CAPSENSE_VERSION EQU 0
CYIPBLOCK_P3_COMP_VERSION EQU 0
CYIPBLOCK_P3_DECIMATOR_VERSION EQU 0
CYIPBLOCK_P3_DFB_VERSION EQU 0
CYIPBLOCK_P3_DMA_VERSION EQU 0
CYIPBLOCK_P3_DRQ_VERSION EQU 0
CYIPBLOCK_P3_DSM_VERSION EQU 0
CYIPBLOCK_P3_EMIF_VERSION EQU 0
CYIPBLOCK_P3_I2C_VERSION EQU 0
CYIPBLOCK_P3_LCD_VERSION EQU 0
CYIPBLOCK_P3_LPF_VERSION EQU 0
CYIPBLOCK_P3_OPAMP_VERSION EQU 0
CYIPBLOCK_P3_PM_VERSION EQU 0
CYIPBLOCK_P3_SCCT_VERSION EQU 0
CYIPBLOCK_P3_TIMER_VERSION EQU 0
CYIPBLOCK_P3_USB_VERSION EQU 0
CYIPBLOCK_P3_VIDAC_VERSION EQU 0
CYIPBLOCK_P3_VREF_VERSION EQU 0
CYIPBLOCK_S8_GPIO_VERSION EQU 0
CYIPBLOCK_S8_IRQ_VERSION EQU 0
CYIPBLOCK_S8_SAR_VERSION EQU 0
CYIPBLOCK_S8_SIO_VERSION EQU 0
CYIPBLOCK_S8_UDB_VERSION EQU 0
DMA_CHANNELS_USED__MASK0 EQU 0x00000000
CYDEV_BOOTLOADER_ENABLE EQU 0
    ENDIF
    END