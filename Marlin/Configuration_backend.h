// ************************************************************************** //
// *********************** Ender 3 Pro - Custom Orange ********************** //
// ************************************************************************** //
	#pragma once
	#define CONFIGURATION_BACKEND_H_VERSION 02010300

	#define DEFAULT_NOMINAL_FILAMENT_DIA 1.75
	#define EXTRUDERS 1	

	#define X_MAX_POS X_BED_SIZE
	#define Y_MAX_POS Y_BED_SIZE

	#define Z_MIN_POS 0
	#define Z_MAX_POS 250

	#define VALIDATE_HOMING_ENDSTOPS
	#define PRINTJOB_TIMER_AUTOSTART

	#if ENABLED(FAN_FIX)
		#define FAN_SOFT_PWM
		#define SOFT_PWM_SCALE 1
	#else
		#define SOFT_PWM_SCALE 0
	#endif

// **************************** Preheat Constants *************************** //

	#define PREHEAT_1_LABEL       "Warmup"
	#define PREHEAT_1_TEMP_HOTEND 150
	#define PREHEAT_1_TEMP_BED     45
	#define PREHEAT_1_FAN_SPEED   	0 //> Value from 0 to 255. Affects parts cooling fan.

	#define PREHEAT_2_LABEL       "PLA"
	#define PREHEAT_2_TEMP_HOTEND 190
	#define PREHEAT_2_TEMP_BED     55
	#define PREHEAT_2_FAN_SPEED   255 //> Value from 0 to 255

	#define PREHEAT_3_LABEL       "PETG"
	#define PREHEAT_3_TEMP_HOTEND 240
	#define PREHEAT_3_TEMP_BED     70
	#define PREHEAT_3_FAN_SPEED    64 //> Value from 0 to 255

	#define PREHEAT_4_LABEL       "ABS"
	#define PREHEAT_4_TEMP_HOTEND 240
	#define PREHEAT_4_TEMP_BED     70
	#define PREHEAT_4_FAN_SPEED   255 //> Value from 0 to 255

// ************************************************************************** //
// ****************************** HOMING SPEED ****************************** //
// ************************************************************************** //

	#if ENABLED(SLOWER_HOMING)
		#define HOMING_FEEDRATE_MM_M { (20*60), (20*60), (4*60) }	//> Homing speeds (mm/min)
		#define Z_PROBE_FEEDRATE_FAST (4*60)	//> Feedrate (mm/min) for the first approach when double-probing (MULTIPLE_PROBING == 2)
	#else
		#define HOMING_FEEDRATE_MM_M { (50*60), (50*60), (5*60) }
		#define Z_PROBE_FEEDRATE_FAST (5*60)
	#endif		

// ************************************************************************** //
// ************************* BED LEVELING + PROBING ************************* //
// ************************************************************************** //

	#define NOZZLE_TO_PROBE_OFFSET { -27.625, 0, -4.330 }

	#define Z_PROBE_OFFSET_RANGE_MIN 	-10
	#define Z_PROBE_OFFSET_RANGE_MAX 		1
	
// ************************** Unified Bed Leveling ************************** //	
	#if ENABLED(AUTO_BED_LEVELING_UBL)

    #define RESTORE_LEVELING_AFTER_G28
		#define MESH_INSET 1  
		#define G26_MESH_VALIDATION
		#if ENABLED(G26_MESH_VALIDATION)
			#define MESH_TEST_NOZZLE_SIZE     0.4   //> (mm) Diameter of primary nozzle.
			#define MESH_TEST_LAYER_HEIGHT    0.2   //> (mm) Default layer height for G26.
			#define MESH_TEST_HOTEND_TEMP     205   //> (°C) Default nozzle temperature for G26.
			#define MESH_TEST_BED_TEMP         60   //> (°C) Default bed temperature for G26.
			#define G26_XY_FEEDRATE            20   //> (mm/s) Feedrate for G26 XY moves.
			#define G26_XY_FEEDRATE_TRAVEL    100   //> (mm/s) Feedrate for G26 XY travel moves.
			#define G26_RETRACT_MULTIPLIER    1.0   //> G26 Q (retraction) used by default between mesh test elements.
		#endif  //> G26_MESH_VALIDATION

		#define MANUAL_PROBE_START_Z 0.2  //> Set a height for the start of manual adjustment (mm), Comment out to use the last-measured height
		#define MESH_EDIT_GFX_OVERLAY     //> Display a graphics overlay while editing the mesh
		#define UBL_MESH_EDIT_MOVES_Z     //> Sophisticated users prefer no movement of nozzle
		#define UBL_SAVE_ACTIVE_ON_M500   //> Save the currently active mesh in the current slot on M500
		#define UBL_MESH_WIZARD           //> Run several commands in a row to get a complete mesh  

		//#define Z_PROBE_END_SCRIPT "G1 Z10 F12000\nG1 X15 Y330\nG1 Z0.5\nG1 Z10"  //> Exec at end of G29, use to retract/move Z probe
		#define UBL_HILBERT_CURVE       //> Use Hilbert distribution for less travel when probing multiple points
		//#define UBL_Z_RAISE_WHEN_OFF_MESH 2.5 //> When the nozzle is off the mesh, this value is used as the Z-Height correction value.
		//#define DEBUG_LEVELING_FEATURE  //> Turn on with the command 'M111 S32'  	

		//#define ENABLE_LEVELING_FADE_HEIGHT
		#if ENABLED(ENABLE_LEVELING_FADE_HEIGHT)
			#define DEFAULT_LEVELING_FADE_HEIGHT 0 //> (mm) Default fade height. Disable by default to prevent user issues. Configure M420 Z10 for fading over first 10mm of layer printing. 
		#endif

		#define SEGMENT_LEVELED_MOVES
		#define LEVELED_SEGMENT_LENGTH 5.0 //> (mm) Length of all segments (except the last one)

		#undef Z_PROBE_OFFSET_RANGE_MIN
		#define Z_PROBE_OFFSET_RANGE_MIN -10
		#undef Z_PROBE_OFFSET_RANGE_MAX
		#define Z_PROBE_OFFSET_RANGE_MAX 1	

		#define Z_MIN_PROBE_REPEATABILITY_TEST  //> Enable the M48 repeatability test to test probe accuracy
		#define Z_AFTER_HOMING      5   //> (mm) Height to move to after homing Z
		#define Z_PROBE_LOW_POINT  -2   //> Farthest distance below the trigger-point to go before stopping	

		#if ANY(SLOWER_PROBE_MOVES, PROBING_STEPPERS_OFF)
			#define XY_PROBE_FEEDRATE (133*60)	//> X and Y axis travel speed (mm/min) between probes
		#else
			#define XY_PROBE_FEEDRATE (200*60)
		#endif		

		#define PROBING_MARGIN PROBE_EDGE

		#define GRID_MAX_POINTS_X PROBE_GRID_POINTS_MAX      //> Don't use more than 15 points per axis, implementation limited. (default 10)
		#define GRID_MAX_POINTS_Y GRID_MAX_POINTS_X

		#define Z_SAFE_HOMING
		#if ENABLED(Z_SAFE_HOMING)
			#define Z_SAFE_HOMING_X_POINT X_CENTER  //> X point for Z homing
			#define Z_SAFE_HOMING_Y_POINT Y_CENTER  //> Y point for Z homing
		#endif	

// ************************* BL TOUCH - UBL LEVELING ************************ //
		#if ENABLED(BLTOUCH)
				#undef Z_MIN_PROBE_ENDSTOP_INVERTING
				#define Z_MIN_PROBE_ENDSTOP_INVERTING false	//> enabled if using a build before July 2021. 
				#undef Z_MIN_ENDSTOP_INVERTING
				#define Z_MIN_ENDSTOP_INVERTING false		
		#endif	//> BLTOUCH	
		 
// **************************** Probing Obstacles *************************** //
		// Probing not allowed within the position of an obstacle.

		#if ENABLED(AVOID_OBSTACLES)
				#define CLIP_W  23  // Bed clip width, should be padded a few mm over its physical size
				#define CLIP_H  14  // Bed clip height, should be padded a few mm over its physical size

				// Obstacle Rectangles defined as { X1, Y1, X2, Y2 }
				#define OBSTACLE1 { (X_BED_SIZE) / 4     - (CLIP_W) / 2,                       0, (X_BED_SIZE) / 4     + (CLIP_W) / 2, CLIP_H }
				#define OBSTACLE2 { (X_BED_SIZE) * 3 / 4 - (CLIP_W) / 2,                       0, (X_BED_SIZE) * 3 / 4 + (CLIP_W) / 2, CLIP_H }
				#define OBSTACLE3 { (X_BED_SIZE) / 4     - (CLIP_W) / 2, (Y_BED_SIZE) - (CLIP_H), (X_BED_SIZE) / 4     + (CLIP_W) / 2, Y_BED_SIZE }
				#define OBSTACLE4 { (X_BED_SIZE) * 3 / 4 - (CLIP_W) / 2, (Y_BED_SIZE) - (CLIP_H), (X_BED_SIZE) * 3 / 4 + (CLIP_W) / 2, Y_BED_SIZE }

				// The probed grid must be inset for G29 J. This is okay, since it is
				// only used to compute a linear transformation for the mesh itself.
				#define G29J_MESH_TILT_MARGIN ((CLIP_H) + 1)
		#endif

	#endif	//> AUTO_BED_LEVELING_UBL

// ************************* BL TOUCH - ALL LEVELING ************************ //
	#if ENABLED(BLTOUCH)
		#define Z_CLEARANCE_DEPLOY_PROBE   10 //> Z Clearance for Deploy/Stow  //> Enabled per Antclabs BLTOUCH docs
		#define Z_CLEARANCE_BETWEEN_PROBES  5 //> Z Clearance between probe points //> Enabled per Antclabs BLTOUCH docs
		#define Z_CLEARANCE_MULTI_PROBE     5 //> Z Clearance between multiple probes
		#define Z_PROBE_FEEDRATE_SLOW (Z_PROBE_FEEDRATE_FAST / 2)   //> Feedrate (mm/min) for the "accurate" probe of each point		
		#define ENDSTOPPULLUP_ZMIN
		#define ENDSTOPPULLUP_ZMIN_PROBE		
	#else
		#define Z_CLEARANCE_DEPLOY_PROBE   5
		#define Z_CLEARANCE_BETWEEN_PROBES 3
		#define Z_CLEARANCE_MULTI_PROBE    3
		#define Z_PROBE_FEEDRATE_SLOW (Z_PROBE_FEEDRATE_FAST / 2)
	#endif	//> BLTOUCH

// ************************************************************************** //
// ************************* THERMAL + TEMP SETTINGS ************************ //
// ************************************************************************** //

	#define PREVENT_COLD_EXTRUSION
	#define EXTRUDE_MINTEMP 170

	#define DUMMY_THERMISTOR_998_VALUE  25
	#define DUMMY_THERMISTOR_999_VALUE 100

  #define TEMP_SENSOR_0    5  //> 100kΩ  ATC Semitec 104GT-2/104NT-4-R025H42G - Used in ParCan, J-Head, and E3D, SliceEngineering 300°C
  #define TEMP_SENSOR_BED 11  //> 100kΩ  Keenovo AC silicone mats, most Wanhao i3 machines - beta 3950, 1%

	#define PREVENT_LENGTHY_EXTRUDE

	#define TEMP_SENSOR_REDUNDANT 0
	#if TEMP_SENSOR_REDUNDANT
		#define TEMP_SENSOR_REDUNDANT_SOURCE    E1  //> The sensor that will provide the redundant reading.
		#define TEMP_SENSOR_REDUNDANT_TARGET    E0  //> The sensor that we are providing a redundant reading for.
		#define TEMP_SENSOR_REDUNDANT_MAX_DIFF  10  //> (°C) Temperature difference that will trigger a print abort.
	#endif

	#define HEATER_0_MINTEMP   5
	#define HEATER_1_MINTEMP   HEATER_0_MINTEMP
	#define HEATER_2_MINTEMP   HEATER_0_MINTEMP
	#define HEATER_3_MINTEMP   HEATER_0_MINTEMP
	#define HEATER_4_MINTEMP   HEATER_0_MINTEMP
	#define HEATER_5_MINTEMP   HEATER_0_MINTEMP
	#define HEATER_6_MINTEMP   HEATER_0_MINTEMP
	#define HEATER_7_MINTEMP   HEATER_0_MINTEMP
	#define BED_MINTEMP        HEATER_0_MINTEMP

	#if ENABLED(HIGH_TEMP_THERMISTOR)
		#define HEATER_0_MAXTEMP HIGH_TEMP_THERMISTOR_TEMP
		#define HEATER_1_MAXTEMP HIGH_TEMP_THERMISTOR_TEMP
		#define HEATER_2_MAXTEMP HIGH_TEMP_THERMISTOR_TEMP
		#define HEATER_3_MAXTEMP HIGH_TEMP_THERMISTOR_TEMP
		#define HEATER_4_MAXTEMP HIGH_TEMP_THERMISTOR_TEMP
		#define HEATER_5_MAXTEMP HIGH_TEMP_THERMISTOR_TEMP
		#define HEATER_6_MAXTEMP HIGH_TEMP_THERMISTOR_TEMP
		#define HEATER_7_MAXTEMP HIGH_TEMP_THERMISTOR_TEMP
	#else
		#define HEATER_0_MAXTEMP NORMAL_TEMP_THERMISTOR_TEMP
		#define HEATER_1_MAXTEMP HEATER_0_MAXTEMP
		#define HEATER_2_MAXTEMP HEATER_0_MAXTEMP
		#define HEATER_3_MAXTEMP HEATER_0_MAXTEMP
		#define HEATER_4_MAXTEMP HEATER_0_MAXTEMP
		#define HEATER_5_MAXTEMP HEATER_0_MAXTEMP
		#define HEATER_6_MAXTEMP HEATER_0_MAXTEMP
		#define HEATER_7_MAXTEMP HEATER_0_MAXTEMP
	#endif	//> HIGH_TEMP_THERMISTOR

	#if ENABLED(BED_HIGHTEMP)
		#define BED_MAXTEMP HIGH_TEMP_BED_TEMP
	#else
		#define BED_MAXTEMP NORMAL_TEMP_BED_TEMP
	#endif

	#define HOTEND_OVERSHOOT 15   //> (°C) Forbid temperatures over MAXTEMP - OVERSHOOT
	#define BED_OVERSHOOT    10   //> (°C) Forbid temperatures over MAXTEMP - OVERSHOOT
	#define COOLER_OVERSHOOT  2   //> (°C) Forbid temperatures closer than OVERSHOOT

	#define TEMP_RESIDENCY_TIME          3  //> (seconds) Time to wait for hotend to "settle" in M109
	#define TEMP_WINDOW                  1  //> (°C) Temperature proximity for the "temperature reached" timer
	#define TEMP_HYSTERESIS              3  //> (°C) Temperature proximity considered "close enough" to the target

	#define TEMP_BED_RESIDENCY_TIME      3  //> (seconds) Time to wait for bed to "settle" in M190
	#define TEMP_BED_WINDOW              1  //> (°C) Temperature proximity for the "temperature reached" timer
	#define TEMP_BED_HYSTERESIS          3  //> (°C) Temperature proximity considered "close enough" to the target

	#define THERMAL_PROTECTION_HOTENDS
	#define THERMAL_PROTECTION_BED

// ******************************* PID Values ******************************* //

	#define PIDTEMP
	#define BANG_MAX 255     //> Limits current to nozzle while in bang-bang mode; 255=full current
	#define PID_MAX BANG_MAX //> Limits current to nozzle while PID is active (see PID_FUNCTIONAL_RANGE ); 255=full current
	#define PID_K1 0.95      //> Smoothing factor within any PID loop

	#if NONE(DWIN_CREALITY_LCD, DWIN_CREALITY_LCD_ENHANCED)
		#define PID_AUTOTUNE_MENU	//> Add PID auto-tuning to the "Advanced Settings" menu. (~250 bytes of PROGMEM)
		#if DISABLED(SPACE_SAVER)
			#define PID_EDIT_MENU	//> Add PID editing to the "Advanced Settings" menu. (~700 bytes of PROGMEM)	
		#endif
	#endif

	#define DEFAULT_Kp   22.5162
	#define DEFAULT_Ki    2.4002
	#define DEFAULT_Kd   52.8062

	#define PIDTEMPBED
	#if ENABLED(PIDTEMPBED)
		#define MAX_BED_POWER 255
		#define DEFAULT_bedKp  72.4328
		#define DEFAULT_bedKi  13.8986
		#define DEFAULT_bedKd 251.6556
	#endif

	#if ANY(PIDTEMP, PIDTEMPBED)
		#define PID_FUNCTIONAL_RANGE 10                                   
	#endif

	//> Disable axis steppers immediately when they're not being stepped.
	#define DISABLE_X false
	#define DISABLE_Y false
	#define DISABLE_Z false
	#define DISABLE_E false             //> Disable the extruder when not stepping
	#define DISABLE_INACTIVE_EXTRUDER   //> Keep only the active extruder enabled

	#define ENDSTOP_NOISE_THRESHOLD 2

	#define SERVO_DELAY { 300 }

// *************************** LCD SCREEN SETTINGS ************************** //

	#define CR10_STOCKDISPLAY //> Used for TFT35 V3 + SKR Mini E3 v2.0 combination.
	#define LCD_LANGUAGE en
	#define DISPLAY_CHARSET_HD44780 JAPANESE
	#define LCD_INFO_SCREEN_STYLE 0

	#if NONE(DWIN_CREALITY_LCD, DWIN_CREALITY_LCD_ENHANCED, LCD2004, TFT_COLOR_UI, DWIN_CREALITY_LCD_ENHANCED, DWIN_CREALITY_LCD_JYERSUI, DWIN_MARLINUI_PORTRAIT, DWIN_MARLINUI_LANDSCAPE)
		#define SHOW_BOOTSCREEN
		//#define SHOW_CUSTOM_BOOTSCREEN
	#endif

	#if NONE(DWIN_CREALITY_LCD, SPACE_SAVER)
		#define INDIVIDUAL_AXIS_HOMING_MENU
		#define INDIVIDUAL_AXIS_HOMING_SUBMENU	
	#endif

// *********************** LEVEL BED CORNERS SETTINGS *********************** //

	#if NONE(DWIN_CREALITY_LCD, DWIN_CREALITY_LCD_ENHANCED)
		#define LEVEL_BED_CORNERS	//> Add a menu item to move between bed corners for manual bed adjustment
	#endif

	#if ENABLED(LEVEL_BED_CORNERS)
		#define LEVEL_CORNERS_INSET_LFRB { 30, 30, 30, 30 } //> (mm) Left, Front, Right, Back insets
		#define LEVEL_CORNERS_HEIGHT      0.0   //> (mm) Z height of nozzle at leveling points, set to thickness of feeler gauge in use (default 0.0)
		#define LEVEL_CORNERS_Z_HOP       4.0   //> (mm) Z height of nozzle between leveling points
		#define LEVEL_CENTER_TOO              //> Move to the center after the last corner
		//#define LEVEL_CORNERS_USE_PROBE
		#if ENABLED(LEVEL_CORNERS_USE_PROBE)
			#define LEVEL_CORNERS_PROBE_TOLERANCE 0.1
			#define LEVEL_CORNERS_VERIFY_RAISED   //> After adjustment triggers the probe, re-probe to verify
			//#define LEVEL_CORNERS_AUDIO_FEEDBACK
		#endif

		#define LEVEL_CORNERS_LEVELING_ORDER { LF, LB } //> 3rd point is the center of the opposite edge
	#endif	//> LEVEL_BED_CORNERS

// **************************** LCD BED LEVELING **************************** //

	#if ENABLED(MANUAL_MESH_LEVELING) && DISABLED(AUTO_BED_LEVELING_UBL)
		#define LCD_BED_LEVELING
		#define MESH_BED_LEVELING
		#define RESTORE_LEVELING_AFTER_G28
		#define MESH_EDIT_Z_STEP  0.025   //> (mm) Step size while manually probing Z axis.
		#define LCD_PROBE_Z_RANGE     4   //> (mm) Z Range centered on Z_MIN_POS for LCD Z adjustment
		#define MESH_INSET PROBE_EDGE     //> Set Mesh bounds as an inset region of the bed (default 1)

		#define SEGMENT_LEVELED_MOVES
		#define LEVELED_SEGMENT_LENGTH 5.0 //> (mm) Length of all segments (except the last one)

		#define GRID_MAX_POINTS_X 3
		#define GRID_MAX_POINTS_Y GRID_MAX_POINTS_X	

		#define MESH_EDIT_MENU            //> Add a menu to edit mesh points
	#endif

// ***************************** EEPROM Settings **************************** //

	#define SDSUPPORT

	#define EEPROM_SETTINGS     //> Persistent storage with M500 and M501
	#if ENABLED(EEPROM_SETTINGS)
		#define EEPROM_AUTO_INIT  //> Init EEPROM automatically on any errors.
		//#define EEPROM_INIT_NOW   //> Init EEPROM on first boot after a new build.
	#endif

	#define EEPROM_CHITCHAT       //> Give feedback on EEPROM commands. Disable to save PROGMEM.
	#define EEPROM_BOOT_SILENT    //> Keep M503 quiet and only give errors during first load

	#define HOST_KEEPALIVE_FEATURE        
	#define DEFAULT_KEEPALIVE_INTERVAL 2 
	#define BUSY_WHILE_HEATING

	#define TEMPERATURE_UNITS_SUPPORT //> M149 Set temperature units support

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

// ************************* Filament Runout Sensor ************************* //

  #if ENABLED(FILAMENT_RUNOUT_SENSOR)
    #define FIL_RUNOUT_ENABLED_DEFAULT true //> Enable the sensor on startup. Override with M412 followed by M500.
    #define NUM_RUNOUT_SENSORS 1            //> Number of sensors, up to one per extruder. Define a FIL_RUNOUT#_PIN for each.

    #define FIL_RUNOUT_STATE LOW            //> Pin state indicating that filament is NOT present.
    #define FIL_RUNOUT_PULLUP               //> Use internal pullup for filament runout pins.
    #define FILAMENT_RUNOUT_SCRIPT "M600"

    #define FILAMENT_RUNOUT_DISTANCE_MM 7   //> set at 7mm per BTT smart filament sensor docs
    #if ENABLED(FILAMENT_RUNOUT_DISTANCE_MM)
      #define FILAMENT_MOTION_SENSOR
    #endif

  #endif //> FILAMENT_RUNOUT_SENSOR	

// ******************************* Nozzle Park ****************************** //

  #define NOZZLE_PARK_FEATURE

  #if ENABLED(NOZZLE_PARK_FEATURE)
    #define NOZZLE_PARK_POINT { (X_MIN_POS + 10), (Y_MAX_POS - 10), 20 } //> Specify a park position as { X, Y, Z_raise }
    #define NOZZLE_PARK_Z_RAISE_MIN   5   //> (mm) Always raise Z by at least this distance
    #define NOZZLE_PARK_XY_FEEDRATE 100   //> (mm/s) X and Y axes feedrate (also used for delta Z axis)
    #define NOZZLE_PARK_Z_FEEDRATE    8   //> (mm/s) Z axis feedrate (not used for delta printers)
  #endif  //> NOZZLE_PARK_FEATURE	

// ***************************** Skew Correction **************************** //

  //#define SKEW_CORRECTION
  #if ENABLED(SKEW_CORRECTION)
    //> Input all length measurements here:
    #define XY_DIAG_AC 282.8427124746
    #define XY_DIAG_BD 282.8427124746
    #define XY_SIDE_AD 200

    //> Or, set the default skew factors directly here to override the above measurements:
    #define XY_SKEW_FACTOR 0.0

    //#define SKEW_CORRECTION_FOR_Z
    #if ENABLED(SKEW_CORRECTION_FOR_Z)
      #define XZ_DIAG_AC     282.8427124746
      #define XZ_DIAG_BD     282.8427124746
      #define YZ_DIAG_AC     282.8427124746
      #define YZ_DIAG_BD     282.8427124746
      #define YZ_SIDE_AD     200
      #define XZ_SKEW_FACTOR 0.0
      #define YZ_SKEW_FACTOR 0.0
    #endif //> SKEW_CORRECTION_FOR_Z
    
    //#define SKEW_CORRECTION_GCODE //> Enable this option for M852 to set skew at runtime
  #endif //> SKEW_CORRECTION	

// ************************************************************************** //
// *********************** Unused Default Init Values *********************** //
// ************************************************************************** //

	#define INVERT_E1_DIR false
	#define INVERT_E2_DIR false
	#define INVERT_E3_DIR false
	#define INVERT_E4_DIR false
	#define INVERT_E5_DIR false
	#define INVERT_E6_DIR false
	#define INVERT_E7_DIR false

	#define ENCODER_PULSES_PER_STEP 4
	#define ENCODER_STEPS_PER_MENU_ITEM 1

	#define TEMP_SENSOR_1 0
	#define TEMP_SENSOR_2 0
	#define TEMP_SENSOR_3 0
	#define TEMP_SENSOR_4 0
	#define TEMP_SENSOR_5 0
	#define TEMP_SENSOR_6 0
	#define TEMP_SENSOR_7 0

	#define TEMP_SENSOR_PROBE   0
	#define TEMP_SENSOR_CHAMBER 0
	#define TEMP_SENSOR_BOARD   0  

// ************************************************************************** //
// *********************** Marlin 2.1 Version Settings ********************** //
// ************************************************************************** //

// *************************** Endstop "Hit" State ************************** //
    // Set to the state (HIGH or LOW) that applies to each endstop.
    // Settings replace "X_MIN_ENDSTOP_INVERTING" true/false settings
    #define X_MIN_ENDSTOP_HIT_STATE HIGH
    #define X_MAX_ENDSTOP_HIT_STATE HIGH
    #define Y_MIN_ENDSTOP_HIT_STATE HIGH
    #define Y_MAX_ENDSTOP_HIT_STATE HIGH
    #define Z_MIN_ENDSTOP_HIT_STATE HIGH
    #define Z_MAX_ENDSTOP_HIT_STATE HIGH
    #define Z_MIN_PROBE_ENDSTOP_HIT_STATE HIGH

// ************************** Clean Nozzle Feature ************************** //
	/**
	 *
	 * Adds the G12 command to perform a nozzle cleaning process.
	 *
	 * Parameters:
	 *   P  Pattern
	 *   S  Strokes / Repetitions
	 *   T  Triangles (P1 only)
	 *
	 * Patterns:
	 *   P0  Straight line (default). This process requires a sponge type material
	 *       at a fixed bed location. "S" specifies strokes (i.e. back-forth motions)
	 *       between the start / end points.
	 *
	 *   P1  Zig-zag pattern between (X0, Y0) and (X1, Y1), "T" specifies the
	 *       number of zig-zag triangles to do. "S" defines the number of strokes.
	 *       Zig-zags are done in whichever is the narrower dimension.
	 *       For example, "G12 P1 S1 T3" will execute:
	 *
	 *          --
	 *         |  (X0, Y1) |     /\        /\        /\     | (X1, Y1)
	 *         |           |    /  \      /  \      /  \    |
	 *       A |           |   /    \    /    \    /    \   |
	 *         |           |  /      \  /      \  /      \  |
	 *         |  (X0, Y0) | /        \/        \/        \ | (X1, Y0)
	 *          --         +--------------------------------+
	 *                       |________|_________|_________|
	 *                           T1        T2        T3
	 *
	 *   P2  Circular pattern with middle at NOZZLE_CLEAN_CIRCLE_MIDDLE.
	 *       "R" specifies the radius. "S" specifies the stroke count.
	 *       Before starting, the nozzle moves to NOZZLE_CLEAN_START_POINT.
	 *
	 *   Caveats: The ending Z should be the same as starting Z.
	 */
	//#define NOZZLE_CLEAN_FEATURE

	#if ENABLED(NOZZLE_CLEAN_FEATURE)
		#define NOZZLE_CLEAN_PATTERN_LINE     // Provide 'G12 P0' - a simple linear cleaning pattern
		#define NOZZLE_CLEAN_PATTERN_ZIGZAG   // Provide 'G12 P1' - a zigzag cleaning pattern
		#define NOZZLE_CLEAN_PATTERN_CIRCLE   // Provide 'G12 P2' - a circular cleaning pattern

		// Default pattern to use when 'P' is not provided to G12. One of the enabled options above.
		#define NOZZLE_CLEAN_DEFAULT_PATTERN 0

		#define NOZZLE_CLEAN_STROKES     12   // Default number of pattern repetitions

		#if ENABLED(NOZZLE_CLEAN_PATTERN_ZIGZAG)
			#define NOZZLE_CLEAN_TRIANGLES  3   // Default number of triangles
		#endif

		// Specify positions for each tool as { { X, Y, Z }, { X, Y, Z } }
		// Dual hotend system may use { {  -20, (Y_BED_SIZE / 2), (Z_MIN_POS + 1) },  {  420, (Y_BED_SIZE / 2), (Z_MIN_POS + 1) }}
		#define NOZZLE_CLEAN_START_POINT { {  30, 30, (Z_MIN_POS + 1) } }
		#define NOZZLE_CLEAN_END_POINT   { { 100, 60, (Z_MIN_POS + 1) } }

		#if ENABLED(NOZZLE_CLEAN_PATTERN_CIRCLE)
			#define NOZZLE_CLEAN_CIRCLE_RADIUS 6.5                      // (mm) Circular pattern radius
			#define NOZZLE_CLEAN_CIRCLE_FN 10                           // Circular pattern circle number of segments
			#define NOZZLE_CLEAN_CIRCLE_MIDDLE NOZZLE_CLEAN_START_POINT // Middle point of circle
		#endif

		// Move the nozzle to the initial position after cleaning
		#define NOZZLE_CLEAN_GOBACK

		// For a purge/clean station that's always at the gantry height (thus no Z move)
		//#define NOZZLE_CLEAN_NO_Z

		// For a purge/clean station mounted on the X axis
		//#define NOZZLE_CLEAN_NO_Y

		// Require a minimum hotend temperature for cleaning
		#define NOZZLE_CLEAN_MIN_TEMP 170
		//#define NOZZLE_CLEAN_HEATUP       // Heat up the nozzle instead of skipping wipe

		// Explicit wipe G-code script applies to a G12 with no arguments.
		//#define WIPE_SEQUENCE_COMMANDS "G1 X-17 Y25 Z10 F4000\nG1 Z1\nM114\nG1 X-17 Y25\nG1 X-17 Y95\nG1 X-17 Y25\nG1 X-17 Y95\nG1 X-17 Y25\nG1 X-17 Y95\nG1 X-17 Y25\nG1 X-17 Y95\nG1 X-17 Y25\nG1 X-17 Y95\nG1 X-17 Y25\nG1 X-17 Y95\nG1 Z15\nM400\nG0 X-10.0 Y-9.0"

	#endif



// ************************ Encoder EMI Noise Filter ************************ //
	// This option increases encoder samples to filter out phantom encoder clicks caused by EMI noise.

	//#define ENCODER_NOISE_FILTER
	#if ENABLED(ENCODER_NOISE_FILTER)
		#define ENCODER_SAMPLES 10
	#endif
