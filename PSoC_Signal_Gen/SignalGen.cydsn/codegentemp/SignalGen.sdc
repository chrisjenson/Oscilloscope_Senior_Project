# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\tmj32\Documents\TCNJ\Senior_Project\Oscilloscope_Senior_Project\Workspace01\SignalGen.cydsn\SignalGen.cyprj
# Date: Thu, 18 Mar 2021 15:19:21 GMT
#set_units -time ns
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyClk_LF} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyFLL} -period 10 -waveform {0 5} [list [get_pins {ClockBlock/fll}]]
create_clock -name {CyClk_HF0} -period 10 -waveform {0 5} [list [get_pins {ClockBlock/hfclk_0}]]
create_clock -name {CyClk_Fast} -period 10 -waveform {0 5} [list [get_pins {ClockBlock/fastclk}]]
create_clock -name {CyClk_Peri} -period 20 -waveform {0 10} [list [get_pins {ClockBlock/periclk}]]
create_generated_clock -name {CyClk_Slow} -source [get_pins {ClockBlock/periclk}] -edges {1 2 3} [list [get_pins {ClockBlock/slowclk}]]
create_generated_clock -name {Clock_1} -source [get_pins {ClockBlock/periclk}] -edges {1 101 201} [list [get_pins {ClockBlock/ff_div_47}]]
create_clock -name {CyPeriClk_App} -period 20 -waveform {0 10} [list [get_pins {ClockBlock/periclk_App}]]
create_clock -name {CyClk_HF4} -period 40 -waveform {0 20} [list [get_pins {ClockBlock/hfclk_4}]]
create_clock -name {CyIMO} -period 125 -waveform {0 62.5} [list [get_pins {ClockBlock/imo}]]


# Component constraints for C:\Users\tmj32\Documents\TCNJ\Senior_Project\Oscilloscope_Senior_Project\Workspace01\SignalGen.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\tmj32\Documents\TCNJ\Senior_Project\Oscilloscope_Senior_Project\Workspace01\SignalGen.cydsn\SignalGen.cyprj
# Date: Thu, 18 Mar 2021 15:18:57 GMT
