/*
 * File: Subsystem5_ca.h
 *
 * Abstract: Tests assumptions in the generated code.
 */

#ifndef SUBSYSTEM5_CA_H
#define SUBSYSTEM5_CA_H

/* preprocessor validation checks */
#include "Subsystem5_ca_preproc.h"
#include "coder_assumptions_hwimpl.h"

/* variables holding test results */
extern CA_HWImpl_TestResults CA_Subsystem5_HWRes;
extern CA_PWS_TestResults CA_Subsystem5_PWSRes;

/* variables holding "expected" and "actual" hardware implementation */
extern const CA_HWImpl CA_Subsystem5_ExpHW;
extern CA_HWImpl CA_Subsystem5_ActHW;

/* entry point function to run tests */
void Subsystem5_caRunTests(void);

#endif                                 /* SUBSYSTEM5_CA_H */
