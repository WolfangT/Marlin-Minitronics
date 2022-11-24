/**
 * Custom thermistor table for Ntc 3950 - 100k thermistor i found locally
 *
 */

#pragma once
// Thermistor lookup table for Marlin
// ./createTemperatureLookupMarlin.py --rp=4700 --t1=25.0:100000.0 --t2=126.0:3603.0 --t3=196.0:725.0 --num-temps=36
// Steinhart-Hart Coefficients: a=0.000732760307117864, b=0.000204933589303875, c=1.71605146634421e-07 
// Theoretical limits of thermistor: -51.46 to 683.00 degC

constexpr temp_entry_t temptable_990[] PROGMEM = {
    { OV(  23.87),  313 },
    { OV(  28.37),  298 },
    { OV(  30.00),  290 },
    { OV(  34.38),  283 },
    { OV(  36.00),  277 },
    { OV(  41.00),  275 },
    { OV(  41.00),  270 },
    { OV(  44.00),  265 },
    { OV(  48.50),  260 },
    { OV(  53.88),  255 },
    { OV(  57.00),  250 },
    { OV(  60.25),  245 },
    { OV(  71.12),  235 },
    { OV(  79.75),  228 },
    { OV(  88.50),  222 },
    { OV(  99.05),  216 },
    { OV( 112.00),  210 },
    { OV( 124.00),  205 },
    { OV( 148.00),  195 },
    { OV( 168.00),  189 },
    { OV( 180.83),  180 },
    { OV( 215.29),  173 },
    { OV( 263.00),  162 },
    { OV( 320.00),  150 },
    { OV( 400.00),  137 },
    { OV( 480.25),  123 },
    { OV( 571.88),  110 },
    { OV( 655.00),   98 },
    { OV( 740.00),   84 },
    { OV( 818.00),   71 },
    { OV( 880.50),   57 },
    { OV( 929.00),   45 },
    { OV( 971.00),   29 },
    { OV( 986.36),   20 },
    { OV( 999.27),   10 },
    { OV(1008.18),    0 }
};