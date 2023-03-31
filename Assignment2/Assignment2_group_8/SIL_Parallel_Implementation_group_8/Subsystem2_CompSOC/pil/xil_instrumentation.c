/*
 * File: xil_instrumentation.c
 *
 * Code generated for instrumentation.
 *
 */

#include "xil_instrumentation.h"

/* Code instrumentation offset(s) for model Subsystem2 */
#define profileStart_Subsystem2_offset 2
#define profileEnd_Subsystem2_offset   2

/* Code instrumentation offset(s) for model Subsystem2 */
#define taskTimeStart_Subsystem2_offset 0
#define taskTimeEnd_Subsystem2_offset  0
#define SIZEOF_SECTION_ID_CONTAINER    sizeof(uint64_T)
#define SIZEOF_TIMER_TYPE              sizeof(uint64_T)

static uint64_T xsd_xil_timer_corrected = 0;
static uint64_T xsd_xil_timer_unfreeze = 0;
void xilUploadProfilingData(uint32_T sectionId)
{
  xilUploadCodeInstrData((void *)(&xsd_xil_timer_corrected), (uint32_T)
    (SIZEOF_TIMER_TYPE), sectionId);
}

void xilProfilingTimerFreeze(void)
{
  /* Update the value of the corrected timer to exclude time spent in the
   * instrumentation code.
   *
   * Using a timer that increments on each tick.
   */
  xsd_xil_timer_corrected = xsd_xil_timer_corrected
    + (((uint64_T)(read_time())) - xsd_xil_timer_unfreeze);
}

void xilProfilingTimerUnFreeze(void)
{
  xsd_xil_timer_unfreeze = ( uint64_T ) (read_time());
}

void taskTimeStart(uint32_T sectionId)
{
  /* Send execution profiling data to host */
  xilUploadProfilingData(sectionId);
  xilProfilingTimerUnFreeze();
}

void taskTimeEnd(uint32_T sectionId)
{
  uint32_T sectionIdNeg = ~sectionId;
  xilProfilingTimerFreeze();

  /* Send execution profiling data to host */
  xilUploadProfilingData(sectionIdNeg);
}

void profileStart(uint32_T sectionId)
{
  xilProfilingTimerFreeze();

  /* Send execution profiling data to host */
  xilUploadProfilingData(sectionId);
  xilProfilingTimerUnFreeze();
}

void profileEnd(uint32_T sectionId)
{
  uint32_T sectionIdNeg = ~sectionId;
  xilProfilingTimerFreeze();

  /* Send execution profiling data to host */
  xilUploadProfilingData(sectionIdNeg);
  xilProfilingTimerUnFreeze();
}

/* Code instrumentation method(s) for model Subsystem2 */
void profileStart_Subsystem2(uint32_T sectionId)
{
  profileStart(profileStart_Subsystem2_offset + sectionId);
}

void profileEnd_Subsystem2(uint32_T sectionId)
{
  profileEnd(profileEnd_Subsystem2_offset + sectionId);
}

/* Code instrumentation method(s) for model Subsystem2 */
void taskTimeStart_Subsystem2(uint32_T sectionId)
{
  taskTimeStart(taskTimeStart_Subsystem2_offset + sectionId);
}

void taskTimeEnd_Subsystem2(uint32_T sectionId)
{
  taskTimeEnd(taskTimeEnd_Subsystem2_offset + sectionId);
}
