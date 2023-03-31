/*
 * File: Subsystem1_ca.h
 *
 * Abstract: Tests assumptions in the generated code.
 */

#ifndef SUBSYSTEM1_CA_H
#define SUBSYSTEM1_CA_H

/* preprocessor validation checks */
#include "Subsystem1_ca_preproc.h"
#include "coder_assumptions_hwimpl.h"

/* variables holding test results */
extern CA_HWImpl_TestResults CA_Subsystem1_HWRes;
extern CA_PWS_TestResults CA_Subsystem1_PWSRes;

/* variables holding "expected" and "actual" hardware implementation */
extern const CA_HWImpl CA_Subsystem1_ExpHW;
extern CA_HWImpl CA_Subsystem1_ActHW;

/* entry point function to run tests */
void Subsystem1_caRunTests(void);

#endif                                 /* SUBSYSTEM1_CA_H */
