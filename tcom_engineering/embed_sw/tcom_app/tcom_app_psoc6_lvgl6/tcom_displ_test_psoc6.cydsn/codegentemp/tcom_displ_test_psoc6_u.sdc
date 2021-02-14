# Component constraints for E:\College Work\SeniorProject\Oscilloscope_Senior_Project\tcom_engineering\embed_sw\tcom_app\tcom_app_psoc6_lvgl6\tcom_displ_test_psoc6.cydsn\TopDesign\TopDesign.cysch
# Project: E:\College Work\SeniorProject\Oscilloscope_Senior_Project\tcom_engineering\embed_sw\tcom_app\tcom_app_psoc6_lvgl6\tcom_displ_test_psoc6.cydsn\tcom_displ_test_psoc6.cyprj
# Date: Thu, 11 Feb 2021 23:49:18 GMT
# LCD_INTERFACE
# False paths present for both 8 and 16 bits Graphic LCD Interface configurations 
expr {(8) == 8 ?
   [set_false_path -from [get_pins {\LCD_INTERFACE:GraphLcd8:Lsb\/p_out_0}] -to [get_pins {\LCD_INTERFACE:LsbReg\/status_0}]] : \
   [set_false_path -from [get_pins {\LCD_INTERFACE:GraphLcd16:Lsb\/p_out_0}] -to [get_pins {\LCD_INTERFACE:LsbReg\/status_0}]]} 
   
expr {(8) == 8 ?
   [set_false_path -from [get_pins {\LCD_INTERFACE:GraphLcd8:Lsb\/p_out_1}] -to [get_pins {\LCD_INTERFACE:LsbReg\/status_1}]] : \
   [set_false_path -from [get_pins {\LCD_INTERFACE:GraphLcd16:Lsb\/p_out_1}] -to [get_pins {\LCD_INTERFACE:LsbReg\/status_1}]]} 
   
expr {(8) == 8 ?
   [set_false_path -from [get_pins {\LCD_INTERFACE:GraphLcd8:Lsb\/p_out_2}] -to [get_pins {\LCD_INTERFACE:LsbReg\/status_2}]] : \
   [set_false_path -from [get_pins {\LCD_INTERFACE:GraphLcd16:Lsb\/p_out_2}] -to [get_pins {\LCD_INTERFACE:LsbReg\/status_2}]]} 
   
expr {(8) == 8 ?
   [set_false_path -from [get_pins {\LCD_INTERFACE:GraphLcd8:Lsb\/p_out_3}] -to [get_pins {\LCD_INTERFACE:LsbReg\/status_3}]] : \
   [set_false_path -from [get_pins {\LCD_INTERFACE:GraphLcd16:Lsb\/p_out_3}] -to [get_pins {\LCD_INTERFACE:LsbReg\/status_3}]]} 
   
expr {(8) == 8 ?
   [set_false_path -from [get_pins {\LCD_INTERFACE:GraphLcd8:Lsb\/p_out_4}] -to [get_pins {\LCD_INTERFACE:LsbReg\/status_4}]] : \
   [set_false_path -from [get_pins {\LCD_INTERFACE:GraphLcd16:Lsb\/p_out_4}] -to [get_pins {\LCD_INTERFACE:LsbReg\/status_4}]]} 
   
expr {(8) == 8 ?
   [set_false_path -from [get_pins {\LCD_INTERFACE:GraphLcd8:Lsb\/p_out_5}] -to [get_pins {\LCD_INTERFACE:LsbReg\/status_5}]] : \
   [set_false_path -from [get_pins {\LCD_INTERFACE:GraphLcd16:Lsb\/p_out_5}] -to [get_pins {\LCD_INTERFACE:LsbReg\/status_5}]]} 
   
expr {(8) == 8 ?
   [set_false_path -from [get_pins {\LCD_INTERFACE:GraphLcd8:Lsb\/p_out_6}] -to [get_pins {\LCD_INTERFACE:LsbReg\/status_6}]] : \
   [set_false_path -from [get_pins {\LCD_INTERFACE:GraphLcd16:Lsb\/p_out_6}] -to [get_pins {\LCD_INTERFACE:LsbReg\/status_6}]]} 
 
expr {(8) == 8 ?
   [set_false_path -from [get_pins {\LCD_INTERFACE:GraphLcd8:Lsb\/p_out_7}] -to [get_pins {\LCD_INTERFACE:LsbReg\/status_7}]] : \
   [set_false_path -from [get_pins {\LCD_INTERFACE:GraphLcd16:Lsb\/p_out_7}] -to [get_pins {\LCD_INTERFACE:LsbReg\/status_7}]]} 
   
# False paths present only for 16 bits Graphic LCD Interface configuration
expr {(8) == 16 ?
   [set_false_path -from [get_pins {\LCD_INTERFACE:GraphLcd16:Msb\/p_out_0}] -to [get_pins {\LCD_INTERFACE:GraphLcd16:MsbReg\/status_0}]] : {}}
   
expr {(8) == 16 ?
   [set_false_path -from [get_pins {\LCD_INTERFACE:GraphLcd16:Msb\/p_out_1}] -to [get_pins {\LCD_INTERFACE:GraphLcd16:MsbReg\/status_1}]] : {}}
   
expr {(8) == 16 ?
   [set_false_path -from [get_pins {\LCD_INTERFACE:GraphLcd16:Msb\/p_out_2}] -to [get_pins {\LCD_INTERFACE:GraphLcd16:MsbReg\/status_2}]] : {}}

expr {(8) == 16 ?
   [set_false_path -from [get_pins {\LCD_INTERFACE:GraphLcd16:Msb\/p_out_3}] -to [get_pins {\LCD_INTERFACE:GraphLcd16:MsbReg\/status_3}]] : {}}
   
expr {(8) == 16 ?
   [set_false_path -from [get_pins {\LCD_INTERFACE:GraphLcd16:Msb\/p_out_4}] -to [get_pins {\LCD_INTERFACE:GraphLcd16:MsbReg\/status_4}]] : {}}
   
expr {(8) == 16 ?
   [set_false_path -from [get_pins {\LCD_INTERFACE:GraphLcd16:Msb\/p_out_5}] -to [get_pins {\LCD_INTERFACE:GraphLcd16:MsbReg\/status_5}]] : {}}
   
expr {(8) == 16 ?
   [set_false_path -from [get_pins {\LCD_INTERFACE:GraphLcd16:Msb\/p_out_6}] -to [get_pins {\LCD_INTERFACE:GraphLcd16:MsbReg\/status_6}]] : {}}
   
expr {(8) == 16 ?
   [set_false_path -from [get_pins {\LCD_INTERFACE:GraphLcd16:Msb\/p_out_7}] -to [get_pins {\LCD_INTERFACE:GraphLcd16:MsbReg\/status_7}]] : {}}

