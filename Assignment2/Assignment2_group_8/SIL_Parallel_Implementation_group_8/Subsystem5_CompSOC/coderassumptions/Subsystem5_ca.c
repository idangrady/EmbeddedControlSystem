/*
 * File: Subsystem5_ca.c
 *
 * Abstract: Tests assumptions in the generated code.
 */

#include "Subsystem5_ca.h"

CA_HWImpl_TestResults CA_Subsystem5_HWRes;
CA_PWS_TestResults CA_Subsystem5_PWSRes;
const CA_HWImpl CA_Subsystem5_ExpHW = {
  8,                                   /* BitPerChar */
  16,                                  /* BitPerShort */
  32,                                  /* BitPerInt */
  32,                                  /* BitPerLong */
  64,                                  /* BitPerLongLong */
  32,                                  /* BitPerFloat */
  64,                                  /* BitPerDouble */
  32,                                  /* BitPerPointer */
  32,                                  /* BitPerSizeT */
  32,                                  /* BitPerPtrDiffT */
  CA_LITTLE_ENDIAN,                    /* Endianess */
  CA_ZERO,                             /* IntDivRoundTo */
  1,                                   /* ShiftRightIntArith */
  1,                                   /* LongLongMode */
  0,                                   /* PortableWordSizes */
  "Custom Processor",                  /* HWDeviceType */
  0,                                   /* MemoryAtStartup */
  0,                                   /* DenormalFlushToZero */
  0                                    /* DenormalAsZero */
};

CA_HWImpl CA_Subsystem5_ActHW;
void Subsystem5_caRunTests(void)
{
  /* verify hardware implementation */
  caVerifyPortableWordSizes(&CA_Subsystem5_ActHW, &CA_Subsystem5_ExpHW,
    &CA_Subsystem5_PWSRes);
  caVerifyHWImpl(&CA_Subsystem5_ActHW, &CA_Subsystem5_ExpHW,
                 &CA_Subsystem5_HWRes);
}
