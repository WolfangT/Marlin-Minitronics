/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * Minitronics v1.0/1.1 pin assignments
 */

/**
 * 
 * Rev B   2 JAN 2017
 *
 *  Added pin definitions for M3, M4 & M5 spindle control commands
 */

/**
 * Modifications on 30 Sep 2022
 * For use with platformio on env atmega1280
 * based on atmega 1280 pinout https://camo.githubusercontent.com/90c3301e9f9d2e07269f15f89ee823ea1ae3dca96e9b7d3e73a6a4d8d626c2b8/68747470733a2f2f692e696d6775722e636f6d2f4f37577457416a2e6a7067
 * and https://reprap.org/mediawiki/images/b/b6/MinitronicsPDF.zip
 * but NOT on http://reprapworld.com/datasheets/datasheet%20minitronics%20v1.pdf Pin Defition
 */

#if NOT_TARGET(__AVR_ATmega1280__)
  #error "Oops! Select 'Minitronics' in 'Tools > Board.'"
#elif HOTENDS > 2 || E_STEPPERS > 2
  #error "Minitronics supports up to 2 hotends / E steppers."
#endif

#define BOARD_INFO_NAME "Minitronics v1.0/1.1"
#define DEFAULT_MACHINE_NAME "Minitronics"

//
// Limit Switches
//
#define X_MIN_PIN                              5
#define X_MAX_PIN                             -1
#define Y_MIN_PIN                              2
#define Y_MAX_PIN                             -1
#define Z_MIN_PIN                             10
#define Z_MAX_PIN                             -1

//
// Steppers
//
#define X_DIR_PIN                             55
#define X_STEP_PIN                            56
#define X_ENABLE_PIN                          57

#define Y_ENABLE_PIN                          22
#define Y_STEP_PIN                            23
#define Y_DIR_PIN                             24

#define Z_ENABLE_PIN                          25
#define Z_STEP_PIN                            26
#define Z_DIR_PIN                             27

#define E0_DIR_PIN                            28
#define E0_STEP_PIN                           29
#define E0_ENABLE_PIN                         39

#define E1_DIR_PIN                            30
#define E1_STEP_PIN                           31
#define E1_ENABLE_PIN                         32

//
// Temperature Sensors
//
#define TEMP_0_PIN                             7  // Analog Input
#define TEMP_1_PIN                             6  // Analog Input
#define TEMP_BED_PIN                           6  // Analog Input

//
// Heaters / Fans
//
// MOD: usign external driver for HB, so using the bigger FET for extruder heater
// this are the top screw headers from left to right
#define FAN_PIN                                  13 // Cooling part fan
#define E0_AUTO_FAN_PIN                          12 // Extruder 1 heat break fan
#define HEATER_BED_PIN                           11 // Bed
#define HEATER_0_PIN                             3  // Extruder 1

//
// Misc. Functions
//
#define SDSS                                  -1
#define LED_PIN                               54

//
// LCD / Controller
//
#define BEEPER_PIN                            -1

#if ENABLED(REPRAPWORLD_GRAPHICAL_LCD)

  #define LCD_PINS_RS                         15  // CS chip select /SS chip slave select
  #define LCD_PINS_ENABLE                     11  // SID (MOSI)
  #define LCD_PINS_D4                         10  // SCK (CLK) clock

  #define BTN_EN1                             18
  #define BTN_EN2                             17
  #define BTN_ENC                             25

  #define SD_DETECT_PIN                       30

#else

  #define LCD_PINS_RS                         -1
  #define LCD_PINS_ENABLE                     -1

  // Buttons are directly attached using keypad
  #define BTN_EN1                             -1
  #define BTN_EN2                             -1
  #define BTN_ENC                             -1

  #define SD_DETECT_PIN                       -1  // Minitronics doesn't use this
#endif

//
// M3/M4/M5 - Spindle/Laser Control
//
#if HAS_CUTTER                                    // assumes we're only doing CNC work (no 3D printing)
  #undef HEATER_BED_PIN
  #undef TEMP_BED_PIN                             // need to free up some pins but also need to
  #undef TEMP_0_PIN                               // re-assign them (to unused pins) because Marlin
  #undef TEMP_1_PIN                               // requires the presence of certain pins or else it
  #define HEATER_BED_PIN                       4  // won't compile
  #define TEMP_BED_PIN                        50
  #define TEMP_0_PIN                          51
  #define SPINDLE_LASER_ENA_PIN               52  // using A6 because it already has a pullup
  #define SPINDLE_LASER_PWM_PIN                3  // WARNING - LED & resistor pull up to +12/+24V stepper voltage
  #define SPINDLE_DIR_PIN                     53
#endif
