/*
 * File: Subsystem2_ca.h
 *
 * Abstract: Tests assumptions in the generated code.
 */

#ifndef SUBSYSTEM2_CA_H
#define SUBSYSTEM2_CA_H

/* preprocessor validation checks */
#include "Subsystem2_ca_preproc.h"
#include "coder_assumptions_hwimpl.h"

/* variables holding test results */
extern CA_HWImpl_TestResults CA_Subsystem2_HWRes;
extern CA_PWS_TestResults CA_Subsystem2_PWSRes;

/* variables holding "expected" and "actual" hardware implementation */
extern const CA_HWImpl CA_Subsystem2_ExpHW;
extern CA_HWImpl CA_Subsystem2_ActHW;

/* entry point function to run tests */
void Subsystem2_caRunTests(void);

#endif                                 /* SUBSYSTEM2_CA_H */
