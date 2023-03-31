/*
 * File: Subsystem2_ca.c
 *
 * Abstract: Tests assumptions in the generated code.
 */

#include "Subsystem2_ca.h"

CA_HWImpl_TestResults CA_Subsystem2_HWRes;
CA_PWS_TestResults CA_Subsystem2_PWSRes;
const CA_HWImpl CA_Subsystem2_ExpHW = {
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

CA_HWImpl CA_Subsystem2_ActHW;
void Subsystem2_caRunTests(void)
{
  /* verify hardware implementation */
  caVerifyPortableWordSizes(&CA_Subsystem2_ActHW, &CA_Subsystem2_ExpHW,
    &CA_Subsystem2_PWSRes);
  caVerifyHWImpl(&CA_Subsystem2_ActHW, &CA_Subsystem2_ExpHW,
                 &CA_Subsystem2_HWRes);
}
