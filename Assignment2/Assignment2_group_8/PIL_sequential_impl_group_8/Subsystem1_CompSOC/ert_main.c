/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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

/* Overrun counter */
static uint8_t uOverrunCounter;
uint8_t GetOverrunCounter(void)
{
  return uOverrunCounter;
}

#define STEP_SIZE                      30000UL                   /* Sample Time in microseconds */

int main(void)
{
  unsigned long oldTime;
  unsigned long actualTime;

  /* Initialize CompSOC */
  init();

  /* Initialize model */
  Subsystem1_initialize();
  oldTime = micros();
  while (true) {
    Subsystem1_step();

    /* Get model outputs here */
    actualTime = micros();

    /* Overrun check */
    if ((actualTime - oldTime) >= STEP_SIZE) {
      /* We missed our time slot for actual step, report it! */
      if (uOverrunCounter < 255U) {
        uOverrunCounter++;
      }

      oldTime = actualTime;            /* Update time stamp of last step */
      continue;                        /* We are late, continue with next step */
    }

    /* Waiting with pooling method */
    while ((actualTime - oldTime) < STEP_SIZE) {
      actualTime = micros();           /* Get actual time */
    }

    oldTime = actualTime;              /* Update time stamp of last step */
  }

  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
