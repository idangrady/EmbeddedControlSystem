/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Subsystem5.c
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

#include "Subsystem5.h"

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Model step function */
void Subsystem5_step(void)
{
  int16_T rtb_Add;
  int16_T rtb_Add1;
  int16_T rtb_Add2;
  int16_T rtb_Add3;

  /* Sum: '<S1>/Add' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/In5'
   */
  rtb_Add = (int16_T)(rtU.In1 + rtU.In5);

  /* Sum: '<S1>/Add1' incorporates:
   *  Inport: '<Root>/In2'
   *  Inport: '<Root>/In6'
   */
  rtb_Add1 = (int16_T)(rtU.In2 + rtU.In6);

  /* Sum: '<S1>/Add2' incorporates:
   *  Inport: '<Root>/In3'
   *  Inport: '<Root>/In7'
   */
  rtb_Add2 = (int16_T)(rtU.In3 + rtU.In7);

  /* Sum: '<S1>/Add3' incorporates:
   *  Inport: '<Root>/In4'
   *  Inport: '<Root>/In8'
   */
  rtb_Add3 = (int16_T)(rtU.In4 + rtU.In8);

  /* S-Function (merging_task_Sfunction): '<S1>/S-Function' */

  /* Outport: '<Root>/Out1' incorporates:
   *  S-Function (merging_task_Sfunction): '<S1>/S-Function'
   */
  rtY.Out1 = merging_task((int16_T*)&rtb_Add, (int16_T*)&rtb_Add1, (int16_T*)
    &rtb_Add2, (int16_T*)&rtb_Add3);
}

/* Model initialize function */
void Subsystem5_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
