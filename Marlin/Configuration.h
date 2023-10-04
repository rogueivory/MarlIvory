// ************************************************************************** //
// *********************** Ender 3 Pro - Custom Orange ********************** //
// ************************************************************************** //
  //> Auto Build Marlin - STM32F103RE_btt (512k)
  //> Send M502 > M500 to seed settings

  #pragma once
  #define CONFIGURATION_H_VERSION 02010300

  #define STRING_CONFIG_H_AUTHOR "(t3rrr, E3Pro-Custom-Orange)" 
  #define CUSTOM_MACHINE_NAME "E3Pro Custom Orange"
    
  #define MACHINE_UUID "903dc3b4-7e3a-429b-b52a-1f5d768d7e5d"

  #ifndef MOTHERBOARD
    #define MOTHERBOARD BOARD_BTT_SKR_MINI_E3_V2_0
  #endif

  #define SERIAL_PORT 2 //> Specified for TFT35 E3 V3.0
  #define SERIAL_PORT_2 -1 //> Specified for TFT35 E3 V3.0  
  #define BAUDRATE 115200   //> TFT35 Default

// ************************************************************************** //
// ****************************** User Settings ***************************** //
// ************************************************************************** //

  #define X_BED_SIZE  235
  #define Y_BED_SIZE  235  

  //#define LIMIT_Z_SPEED_5
  //#define LIMIT_Z_SPEED_10

  //#define MAX_X_ACCEL
  //#define MAX_Y_ACCEL

  #define PROBE_GRID_POINTS_MAX 5  //>Defines GRID_MAX_POINTS_X, GRID_MAX_POINTS_Y
  #define PROBE_EDGE 35             //> Defines either PROBING_MARGIN or MESH_INSET, depending on settings

  #define HIGH_TEMP_THERMISTOR
  #define HIGH_TEMP_THERMISTOR_TEMP   300
  #define NORMAL_TEMP_THERMISTOR_TEMP 275

  //#define BED_HIGHTEMP
  #define HIGH_TEMP_BED_TEMP          150
  #define NORMAL_TEMP_BED_TEMP        120

  #define AUTO_BED_LEVELING_UBL
  //#define MANUAL_MESH_LEVELING

  //#define PREHEAT_BEFORE_LEVELING
  //#define PREHEAT_BEFORE_PROBING
  
  #define EXTRUDE_MAXLENGTH 170 //> or use length measures (mm) from the extruder gear to the nozzle through the PTFE tube if it is longer than the set value

  #define EZNEO_220
  //#define FILAMENT_RUNOUT_SENSOR
		
  //#define AVOID_OBSTACLES
  
  #define MULTIPLE_PROBING    2
  //#define EXTRA_PROBING     1  //> more atypical reading(s) will be disregarded

  //#define PROBE_TROUBLESHOOT
  //#define SLOWER_PROBE_MOVES          //> If machine makes weird noises/vibrations when probing the mesh, enable this to slow down the speed between probe points.
  //#define PROBING_STEPPERS_OFF        //> This will cycle the XYE stepper motors during probing to reduce interference from them. When using this do NOT touch the X or Y during probing as they will not be locked.
  #define SLOWER_HOMING               //> If your printer is homing to the endstops hard uncomment this to change the homing speed/divisor to make it less aggressive.
  //#define FAN_FIX                     //>If you have a 5015 fan that whines when under 100% speed uncomment the below line.

  //#define FINE_BABYSTEPPING           //> Enabling sets the babystep resolution from 0.025mm to 0.010mm for finer control.

  #define LINEAR_ADVANCE      //> See here on how to use Linear Advance: http://marlinfw.org/docs/features/lin_advance.html
  #define LINEAR_ADVANCE_K 0  //> Change the K Value here or use M900 KX.XX in your starting code (recommended).

  #define DEFAULT_AXIS_STEPS_PER_UNIT   { 400, 400, 6400, 415 } //> { X, Y, Z, E0 } //> E0=415 per DDX V3 docs

  //> Enable HOME_ADJUST to define X/Y MIN_POS values below. Otherwise X/Y MIN_POS values defined as 0. 
  //#define HOME_ADJUST
  #define X_HOME_LOCATION -10
  #define Y_HOME_LOCATION -10    

// ***************************** Motor Settings ***************************** //

  //> Invert the stepper direction. Change (or reverse the motor connector) if an axis goes the wrong way.
  #define INVERT_X_DIR  true
  #define INVERT_Y_DIR  true
  #define INVERT_Z_DIR  false
  #define INVERT_E0_DIR true  //> For direct drive extruder v9 set to true, for geared extruder set to false.

  #define X_DRIVER_TYPE  TMC2209
  #define Y_DRIVER_TYPE  TMC2209
  #define Z_DRIVER_TYPE  TMC2209
  #define E0_DRIVER_TYPE TMC2209

  #define X_ENABLE_ON 0
  #define Y_ENABLE_ON 0
  #define Z_ENABLE_ON 0
  #define E_ENABLE_ON 0  

// **************************** Endstop Settings **************************** //

  #define ENDSTOPPULLUPS //> Enabled per Antclabs BLTOUCH docs
  #define ENDSTOP_INTERRUPTS_FEATURE //> Enabled per Antclabs BLTOUCH docs

  #define DETECT_BROKEN_ENDSTOP //> Check for stuck or disconnected endstops during homing moves.

  #define MIN_SOFTWARE_ENDSTOPS
  #if ENABLED(MIN_SOFTWARE_ENDSTOPS)
    #define MIN_SOFTWARE_ENDSTOP_X
    #define MIN_SOFTWARE_ENDSTOP_Y
  #endif

  #define MAX_SOFTWARE_ENDSTOPS
  #if ENABLED(MAX_SOFTWARE_ENDSTOPS)
    #define MAX_SOFTWARE_ENDSTOP_X
    #define MAX_SOFTWARE_ENDSTOP_Y
    #define MAX_SOFTWARE_ENDSTOP_Z
  #endif    

// ************************************************************************** //
// ***************************** HOMING SETTINGS **************************** //
// ************************************************************************** //

  #define X_HOME_DIR -1
  #define Y_HOME_DIR -1
  #define Z_HOME_DIR -1

  #define NO_MOTION_BEFORE_HOMING //> Inhibit movement until all axes have been homed. Also enable HOME_AFTER_DEACTIVATE for extra safety.
  #define HOME_AFTER_DEACTIVATE   //> Require rehoming after steppers are deactivated. Also enable NO_MOTION_BEFORE_HOMING for extra safety.

  //> Travel limits (mm) after homing, corresponding to endstop positions.
  #if ENABLED(HOME_ADJUST)
    #define X_MIN_POS X_HOME_LOCATION
    #define Y_MIN_POS Y_HOME_LOCATION
  #else
    #define X_MIN_POS 0
    #define Y_MIN_POS 0
  #endif //> HOME_ADJUST

  //#define Z_HOMING_HEIGHT  4    //> (mm) Minimal Z height before homing (G28) for Z clearance above the bed, clamps, ... Be sure to have this much clearance over your Z_MAX_POS to prevent grinding.

// ************************************************************************** //
// ************************* BED LEVELING - BL TOUCH ************************ //
// ************************************************************************** //

  #define EXTRAPOLATE_BEYOND_GRID //> This will use the mesh data to make assumptions of the bed outside the probe area. Disable if you are getting incorrect results on the edges of the bed.

  #define BLTOUCH
  #define BLTOUCH_ON_5PIN

  #define SERVO0_PIN PA1
  #define Z_MIN_PROBE_PIN PC14  //> white cable = ZMIN = PC14

  #if ENABLED(BLTOUCH_ON_5PIN)
    #define USE_PROBE_FOR_Z_HOMING
  #else
    #define Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN  //> Automatically enables USE_PROBE_FOR_Z_HOMING
  #endif

  #define Z_AFTER_PROBING     5   //> Z position after probing is done

// ************************** PROBE TROUBLESHOOTING ************************* //

  #define PROBING_ESTEPPERS_OFF     //> Turn all extruder steppers off when probing

  #if ENABLED(PROBE_TROUBLESHOOT)
    #define PROBING_FANS_OFF          //> Turn fans off when probing
    #define PROBING_STEPPERS_OFF      //> Turn all steppers off (unless needed to hold position) when probing (including extruders)
    #define PROBING_HEATERS_OFF       //> Turn heaters off when probing

    #if ENABLED(PROBING_HEATERS_OFF)
      #define WAIT_FOR_BED_HEATER     //> Wait for bed to heat back up between probes (to improve accuracy)
      #define WAIT_FOR_HOTEND         //> Wait for hotend to heat back up between probes (to improve accuracy & prevent cold extrude)
    #endif
  #endif //> PROBE_TROUBLESHOOT

  //> Require minimum nozzle and/or bed temperature for probing
  #if ANY(PREHEAT_BEFORE_PROBING, PREHEAT_BEFORE_LEVELING)
    #define PROBING_NOZZLE_TEMP 120
    #define PROBING_BED_TEMP     50
  #endif

// **************************** Neopixel / EZNEO **************************** //

  #if ENABLED(EZNEO_220)
    #define RGB_LIGHTS

    #define NEOPIXEL_LED
    #if ENABLED(NEOPIXEL_LED)
      #define NEOPIXEL_TYPE   NEO_GRB
      #if DISABLED(NEOPIXEL_PIN)
        #define NEOPIXEL_PIN     PA8     //> LED driving pin
      #endif
      #define NEOPIXEL_PIXELS 15       //> Number of LEDs in the strip. (Longest strip when NEOPIXEL2_SEPARATE is disabled.)
      #define NEOPIXEL_IS_SEQUENTIAL   //> Sequential display for temperature change - LED by LED. Disable to change all LEDs at once.
      #define NEOPIXEL_BRIGHTNESS 127  //> Initial brightness (0-255)
      #define NEOPIXEL_STARTUP_TEST  //> Cycle through colors at startup
    #endif //> NEOPIXEL_LED

		//#define NEOPIXEL_BKGD_ENABLE
		#if ENABLED(NEOPIXEL_BKGD_ENABLE)
			#define NEOPIXEL_BKGD_INDEX_FIRST  0              //> Index of the first background LED
			#define NEOPIXEL_BKGD_INDEX_LAST   5              //> Index of the last background LED
			#define NEOPIXEL_BKGD_COLOR { 255, 255, 255, 0 }  //> R, G, B, W
			#define NEOPIXEL_BKGD_ALWAYS_ON
		#endif //> NEOPIXEL_BKGD_ENABLE

    #define PRINTER_EVENT_LEDS
  #endif //> EZNEO_220
  
// *************************** Additional Settings ************************** //

  #include "Configuration_backend.h"
  #include "Configuration_speed.h"