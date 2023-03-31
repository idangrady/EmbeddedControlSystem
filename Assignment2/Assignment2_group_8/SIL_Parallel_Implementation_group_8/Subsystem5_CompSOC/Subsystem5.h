/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Subsystem5.h
 *
 * Code generated for Simulink model 'Subsystem5'.
 *
 * Model version                  : 1.1227
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Mar 18 19:50:42 2023
 *
 * Target selection: CompSOC_ec.tlc
 * Embedded hardware selection: Custom Processor
 * Code generation objectives:
 *    1. RAM efficiency
 *    2. Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Subsystem5_h_
#define RTW_HEADER_Subsystem5_h_
#ifndef Subsystem5_COMMON_INCLUDES_
# define Subsystem5_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "merging_task.h"
#endif                                 /* Subsystem5_COMMON_INCLUDES_ */

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
  int16_T In1;                         /* '<Root>/In1' */
  int16_T In2;                         /* '<Root>/In2' */
  int16_T In3;                         /* '<Root>/In3' */
  int16_T In4;                         /* '<Root>/In4' */
  int16_T In5;                         /* '<Root>/In5' */
  int16_T In6;                         /* '<Root>/In6' */
  int16_T In7;                         /* '<Root>/In7' */
  int16_T In8;                         /* '<Root>/In8' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T Out1;                       /* '<Root>/Out1' */
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
extern void Subsystem5_initialize(void);
extern void Subsystem5_step(void);

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
 * hilite_system('SIL_Simulation_Parallel_Implementation/Subsystem5')    - opens subsystem SIL_Simulation_Parallel_Implementation/Subsystem5
 * hilite_system('SIL_Simulation_Parallel_Implementation/Subsystem5/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'SIL_Simulation_Parallel_Implementation'
 * '<S1>'   : 'SIL_Simulation_Parallel_Implementation/Subsystem5'
 */
#endif                                 /* RTW_HEADER_Subsystem5_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
