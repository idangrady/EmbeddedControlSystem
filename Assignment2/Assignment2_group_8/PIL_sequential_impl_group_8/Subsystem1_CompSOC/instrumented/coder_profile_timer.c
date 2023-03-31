/*
 * File: coder_profile_timer.c
 *
 * Code generated for instrumentation.
 *
 * This file contains stub implementations of the instrumentation utility
 * functions. These stubs allow instrumented code to be compiled
 * into an executable that does not support collection of execution
 * instrumentation data.
 *
 */

#include "coder_profile_timer.h"

/* Code instrumentation offset(s) for model Subsystem1 */
#define profileStart_Subsystem1_offset 0
#define profileEnd_Subsystem1_offset   0

/* A function parameter may be intentionally unused */
#ifndef UNUSED_PARAMETER
# if defined(__LCC__)
#   define UNUSED_PARAMETER(x)
# else
#   define UNUSED_PARAMETER(x)         (void) (x)
# endif
#endif

void xilProfilingTimerFreeze(void)
{
}

void xilProfilingTimerUnFreeze(void)
{
}

void profileStart(uint32_T sectionId)
{
  UNUSED_PARAMETER(sectionId);
}

void profileEnd(uint32_T sectionId)
{
  UNUSED_PARAMETER(sectionId);
}

/* Code instrumentation method(s) for model Subsystem1 */
void profileStart_Subsystem1(uint32_T sectionId)
{
  profileStart(profileStart_Subsystem1_offset + sectionId);
}

void profileEnd_Subsystem1(uint32_T sectionId)
{
  profileEnd(profileEnd_Subsystem1_offset + sectionId);
}
