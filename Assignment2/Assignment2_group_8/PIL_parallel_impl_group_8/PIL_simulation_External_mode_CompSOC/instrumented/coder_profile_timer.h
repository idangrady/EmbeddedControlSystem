/*
 * File: coder_profile_timer.h
 *
 * Code generated for instrumentation.
 *
 */

#include "rtwtypes.h"

/* Called before starting a profiled section of code */
void profileStart(uint32_T);

/* Called on finishing a profiled section of code */
void profileEnd(uint32_T);

/* Pause the timer while running code associated with storing
 * and uploading the data. */
void xilProfilingTimerFreeze(void);

/* Restart the timer after a pause */
void xilProfilingTimerUnFreeze(void);

/* Code instrumentation method(s) for model PIL_simulation_External_mode */
void profileStart_P_454deff6677e0cc2(uint32_T sectionId);
void profileEnd_PIL_c11dff6f632b516b(uint32_T sectionId);
