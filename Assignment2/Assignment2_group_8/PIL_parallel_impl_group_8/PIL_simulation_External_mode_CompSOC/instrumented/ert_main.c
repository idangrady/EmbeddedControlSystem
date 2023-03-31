/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'PIL_simulation_External_mode'.
 *
 * Model version                  : 1.695
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 29 12:12:59 2023
 *
 * Target selection: CompSOC_ec.tlc
 * Embedded hardware selection: Custom Processor
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PIL_simulation_External_mode.h"
#include <stddef.h>
#include <stdio.h>                     /* This ert_main.c example uses printf/fflush */
#include <time.h>
#include "rtwtypes.h"
#include "multiword_types.h"
#include "ext_work.h"                  /* External mode header file */

void rt_OneStep(void)
{
  static boolean_T OverrunFlag = false;

  //volatile uint64_t *timer = 0x00FC0000;
  //uint64_t t_iter = 0;
  //uint64_t hp = 100000000;
  /* Disable interrupts here */

  /* Check for overrun */
  if (OverrunFlag) {
    rtmSetErrorStatus(PIL_simulation_External_mode_M, "Overrun");
    return;
  }

  OverrunFlag = true;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /* Set model inputs here */

  /* Step the model for base rate */
  PIL_simulation_External_mode_step();

  /* Get model outputs here */

  /* Indicate task complete */
  OverrunFlag = false;

  /* Disable interrupts here */
  // t_iter = *timer;
  /*asm("sleep");*/
  //while(*timer < t_iter+hp);

  /* Restore FPU context here (if necessary) */
  /* Enable interrupts here */
  rtExtModeCheckEndTrigger();
}

/*
 * The example "main" function illustrates what is required by your
 * application code to initialize, execute, and terminate the generated code.
 * Attaching rt_OneStep to a real-time clock is target specific.  This example
 * illustrates how you do this relative to initializing the model.
 */
int_T main(int_T argc, const char *argv[])
{
  /* External mode */
  rtParseArgsForExtMode(argc, argv);

  /* Initialize model */
  PIL_simulation_External_mode_initialize();

  /* External mode */
  rtSetTFinalForExtMode(&rtmGetTFinal(PIL_simulation_External_mode_M));
  rtExtModeCheckInit(1);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(PIL_simulation_External_mode_M->extModeInfo, 1,
      &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(PIL_simulation_External_mode_M, true);
    }
  }

  rtERTExtModeStartMsg();

  /* The External Mode option selected; therefore,
   *  simulating the model step behavior (in non real-time).
   */
  /*volatile uint64_t *timer = 0x00FC0000;
     uint64_t t_iter = 0;
     uint64_t hp = 100000;*/
  while (rtmGetErrorStatus(PIL_simulation_External_mode_M) == (NULL) &&
         !rtmGetStopRequested(PIL_simulation_External_mode_M)) {
    {
      boolean_T rtmStopReq = false;
      rtExtModePauseIfNeeded(PIL_simulation_External_mode_M->extModeInfo, 1,
        &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(PIL_simulation_External_mode_M, true);
      }

      if (rtmGetStopRequested(PIL_simulation_External_mode_M) == true) {
        rtmSetErrorStatus(PIL_simulation_External_mode_M, "Simulation finished");
        break;
      }
    }

    /* External mode */
    {
      boolean_T rtmStopReq = false;
      rtExtModeOneStep(PIL_simulation_External_mode_M->extModeInfo, 1,
                       &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(PIL_simulation_External_mode_M, true);
      }
    }

    //t_iter = *timer;
    rt_OneStep();
    asm("wfi");

    //while(*timer < t_iter+1000);
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  PIL_simulation_External_mode_terminate();

  /* External mode */
  rtExtModeShutdown(1);
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
