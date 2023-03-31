/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Subsystem2.c
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

#include "Subsystem2.h"

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Model step function */
void Subsystem2_step(void)
{
  /* S-Function (sensing_task2_Sfunction): '<S1>/S-Function1' incorporates:
   *  Inport: '<Root>/In1'
   *  Outport: '<Root>/Out1'
   *  Outport: '<Root>/Out2'
   *  Outport: '<Root>/Out3'
   *  Outport: '<Root>/Out4'
   */
  sensing_task((uint8_T*)&rtU.In1[0], &rtY.Out1, &rtY.Out2, &rtY.Out3, &rtY.Out4);
}

/* Model initialize function */
void Subsystem2_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
