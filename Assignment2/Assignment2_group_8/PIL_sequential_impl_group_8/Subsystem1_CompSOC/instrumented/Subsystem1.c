/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Subsystem1.c
 *
 * Code generated for Simulink model 'Subsystem1'.
 *
 * Model version                  : 1.1213
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Mar 27 16:05:06 2023
 *
 * Target selection: CompSOC_ec.tlc
 * Embedded hardware selection: Custom Processor
 * Code generation objectives:
 *    1. RAM efficiency
 *    2. Execution efficiency
 * Validation result: Not run
 */

#include "Subsystem1.h"

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Model step function */
void Subsystem1_step(void)
{
  /* S-Function (monitor_app_block): '<S1>/S-Function' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/In2'
   *  Outport: '<Root>/Out1'
   *  Outport: '<Root>/Out2'
   *  Outport: '<Root>/Out3'
   */
  profileStart_Subsystem1(1U); /* original_line:44 */monitor((uint8_T*)&rtU.In1[0], &rtY.Out1, &rtY.Out2, (uint32_T*)&rtU.In2,
          &rtY.Out3);profileEnd_Subsystem1(1U); /* original_line:45 */
}

/* Model initialize function */
void Subsystem1_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
