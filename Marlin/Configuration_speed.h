// ************************************************************************** //
// *********************** Ender 3 Pro - Custom Orange ********************** //
// ************************************************************************** //

  #pragma once
  #define CONFIGURATION_SPEED_H_VERSION 02010300

// **************************** Feedrate Settings *************************** //
  #if ENABLED(LIMIT_Z_SPEED_5)
    #define DEFAULT_MAX_FEEDRATE { 400, 400, 5, 200 }
  #elif ENABLED(LIMIT_Z_SPEED_10)
    #define DEFAULT_MAX_FEEDRATE { 400, 400, 10, 200 }
  #else
    #define DEFAULT_MAX_FEEDRATE { 400, 400, 15, 200 }
  #endif

// ************************** Acceleration Settings ************************* //
  #if MAX_X_ACCEL > 1
    #if DISABLED(MAX_Y_ACCEL)
      #define MAX_Y_ACCEL MAX_X_ACCEL
    #endif
    #define DEFAULT_MAX_ACCELERATION { MAX_X_ACCEL, MAX_Y_ACCEL, 500, 5000 }
  #elif MAX_Y_ACCEL > 1
    #if DISABLED(MAX_X_ACCEL)
      #define MAX_X_ACCEL MAX_Y_ACCEL
    #endif
    #define DEFAULT_MAX_ACCELERATION { MAX_X_ACCEL, MAX_Y_ACCEL, 500, 5000 }
  #else
    #define DEFAULT_MAX_ACCELERATION      { 4000, 4000, 500, 5000 } 
  #endif

  #define DEFAULT_ACCELERATION           2000  //> X, Y, Z and E acceleration for printing moves
  #define DEFAULT_RETRACT_ACCELERATION   1000  //> E acceleration for retracts
  #define DEFAULT_TRAVEL_ACCELERATION   DEFAULT_ACCELERATION  //> X, Y, Z acceleration for travel (non printing) moves


// ************************** Motion Jerk Settings ************************** //

  //#define CLASSIC_JERK
  #if ENABLED(CLASSIC_JERK)
    #define DEFAULT_XJERK  8.0
    #define DEFAULT_YJERK  DEFAULT_XJERK
    #define DEFAULT_ZJERK  0.3
  #elif DISABLED(CLASSIC_JERK)
    #define JUNCTION_DEVIATION_MM 0.013 //> (mm) Distance from real junction edge (jyers firmware 0.013)
    #define JD_HANDLE_SMALL_SEGMENTS    //> Use curvature estimation instead of just the junction angle for small segments (< 1mm) with large junction angles (> 135°).
  #endif  //> CLASSIC_JERK

  #define DEFAULT_EJERK    5.0  //> May be used by Linear Advance
  #define S_CURVE_ACCELERATION