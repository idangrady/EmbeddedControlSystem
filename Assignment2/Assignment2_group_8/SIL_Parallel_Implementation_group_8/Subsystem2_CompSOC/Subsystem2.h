/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Subsystem2.h
 *
 * Code generated for Simulink model 'Subsystem2'.
 *
 * Model version                  : 1.1227
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Mar 18 19:44:49 2023
 *
 * Target selection: CompSOC_ec.tlc
 * Embedded hardware selection: Custom Processor
 * Code generation objectives:
 *    1. RAM efficiency
 *    2. Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Subsystem2_h_
#define RTW_HEADER_Subsystem2_h_
#ifndef Subsystem2_COMMON_INCLUDES_
# define Subsystem2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "sensing_task2.h"
#endif                                 /* Subsystem2_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* External inputs (root inport signals with default storage) */
typedef struct {
  uint8_T In1[12496];                  /* '<Root>/In1' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  int16_T Out1;                        /* '<Root>/Out1' */
  int16_T Out2;                        /* '<Root>/Out2' */
  int16_T Out3;                        /* '<Root>/Out3' */
  int16_T Out4;                        /* '<Root>/Out4' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void Subsystem2_initialize(void);
extern void Subsystem2_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('SIL_Simulation_Parallel_Implementation/Subsystem2')    - opens subsystem SIL_Simulation_Parallel_Implementation/Subsystem2
 * hilite_system('SIL_Simulation_Parallel_Implementation/Subsystem2/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'SIL_Simulation_Parallel_Implementation'
 * '<S1>'   : 'SIL_Simulation_Parallel_Implementation/Subsystem2'
 */
#endif                                 /* RTW_HEADER_Subsystem2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
