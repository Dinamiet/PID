#ifndef _PID_H_
#define _PID_H_

/**
 * \file
 * PID
 *
 * Proportional Integral Derivative control
 */

#include <stdbool.h>

/**
 * PID structure state storage
 */
typedef struct _PID_
{
	float P;
	float I;
	float D;
	float Target;
	float Integral;
	float Error;
	float WindupLimit;
	bool  PreventWindup;
} PID;

/**
 * Initialize a PID control
 * \param pid PID to initialize
 * \param p Proportional factor
 * \param i Integral factor
 * \param d Derivative factor
 */
void PID_Init(PID* pid, float p, float i, float d);

/**
 * Changes or updates the Proportional control of PID
 * \param pid PID to update
 * \param p New proportional factor
 */
void PID_Proportional(PID* pid, float p);

/**
 * Changes or updates the Integral control of PID
 * \param pid PID to update
 * \param p New integral factor
 */
void PID_Integral(PID* pid, float i);

/**
 * Changes or updates the Derivative control of PID
 * \param pid PID to update
 * \param p New derivative factor
 */
void PID_Derivative(PID* pid, float d);

/**
 * Windup prevention settings for PID
 * \param pid PID to setup windup prevention for
 * \param enabled Enable or Disable windup prevention for PID
 * \param limit The windup prevention limit to apply to PID
 */
void PID_WindupPrevention(PID* pid, bool enabled, float limit);

/**
 * Clears the state and history of PID
 * \param pid The PID to clear
 */
void PID_ClearState(PID* pid);

/**
 * Set the target value for the PID
 * \param pid The PID target to set
 * \param value The target value
 */
void PID_Target(PID* pid, float value);

/**
 * Calculate the PID control output for the input and time delta
 * \param pid The PID for which the output should be calculated
 * \param input The input value/reading to use
 * \param dt Time delta from last calculation
 * \return Output value for PID control
 */
float PID_Output(PID* pid, float input, float dt);

/**
 * Last error value of PID
 * \param pid The PID to check error for
 * \return The error from the target value of the PID control
 */
float PID_Error(PID* pid);

#endif
