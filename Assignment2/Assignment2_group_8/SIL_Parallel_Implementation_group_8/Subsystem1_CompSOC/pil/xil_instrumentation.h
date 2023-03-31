/*
 * File: xil_instrumentation.h
 *
 * Code generated for instrumentation.
 *
 */

/* Functions with a C call interface */
#ifdef __cplusplus

extern "C" {

#endif

#include "timer.h"
#ifdef __cplusplus

}
#endif

#include "rtwtypes.h"

/* Upload code instrumentation data point */
void xilUploadCodeInstrData(
  void* pData, uint32_T numMemUnits, uint32_T sectionId);

/* Called before starting a profiled section of code */
void taskTimeStart(uint32_T);

/* Called on finishing a profiled section of code */
void taskTimeEnd(uint32_T);

/* Uploads data */
void xilUploadProfilingData(uint32_T sectionId);

/* Pause the timer while running code associated with storing
 * and uploading the data. */
void xilProfilingTimerFreeze(void);

/* Restart the timer after a pause */
void xilProfilingTimerUnFreeze(void);

/* Code instrumentation method(s) for model Subsystem1 */

/* Code instrumentation method(s) for model Subsystem1 */
void taskTimeStart_Subsystem1(uint32_T sectionId);
void taskTimeEnd_Subsystem1(uint32_T sectionId);
