/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PIL_simulation_External_mode.c
 *
 * Code generated for Simulink model 'PIL_simulation_External_mode'.
 *
 * Model version                  : 1.434
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 29 15:42:02 2023
 *
 * Target selection: CompSOC_ec.tlc
 * Embedded hardware selection: Custom Processor
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PIL_simulation_External_mode.h"
#include "PIL_simulation_External_mode_private.h"
#include "PIL_simulation_External_mode_dt.h"

/* Real-time model */
RT_MODEL_PIL_simulation_Exter_T PIL_simulation_External_mode_M_;
RT_MODEL_PIL_simulation_Exter_T *const PIL_simulation_External_mode_M =
  &PIL_simulation_External_mode_M_;

/* Model step function */
void PIL_simulation_External_mode_step(void)
{
  /* S-Function (sensing_block_2): '<Root>/S-Function' */
  hough_transform();

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.015s, 0.0s] */
    rtExtModeUpload(0, (real_T)PIL_simulation_External_mode_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.015s, 0.0s] */
    if ((rtmGetTFinal(PIL_simulation_External_mode_M)!=-1) &&
        !((rtmGetTFinal(PIL_simulation_External_mode_M)-
           PIL_simulation_External_mode_M->Timing.taskTime0) >
          PIL_simulation_External_mode_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(PIL_simulation_External_mode_M, "Simulation finished");
    }

    if (rtmGetStopRequested(PIL_simulation_External_mode_M)) {
      rtmSetErrorStatus(PIL_simulation_External_mode_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  PIL_simulation_External_mode_M->Timing.taskTime0 =
    (++PIL_simulation_External_mode_M->Timing.clockTick0) *
    PIL_simulation_External_mode_M->Timing.stepSize0;
}

/* Model initialize function */
void PIL_simulation_External_mode_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)PIL_simulation_External_mode_M, 0,
                sizeof(RT_MODEL_PIL_simulation_Exter_T));
  rtmSetTFinal(PIL_simulation_External_mode_M, 99.99);
  PIL_simulation_External_mode_M->Timing.stepSize0 = 0.015;

  /* External mode info */
  PIL_simulation_External_mode_M->Sizes.checksums[0] = (1304774729U);
  PIL_simulation_External_mode_M->Sizes.checksums[1] = (883480965U);
  PIL_simulation_External_mode_M->Sizes.checksums[2] = (3727220126U);
  PIL_simulation_External_mode_M->Sizes.checksums[3] = (801315666U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    PIL_simulation_External_mode_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(PIL_simulation_External_mode_M->extModeInfo,
      &PIL_simulation_External_mode_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(PIL_simulation_External_mode_M->extModeInfo,
                        PIL_simulation_External_mode_M->Sizes.checksums);
    rteiSetTPtr(PIL_simulation_External_mode_M->extModeInfo, rtmGetTPtr
                (PIL_simulation_External_mode_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    PIL_simulation_External_mode_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];
  }
}

/* Model terminate function */
void PIL_simulation_External_mode_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
