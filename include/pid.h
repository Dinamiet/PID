#ifndef _PID_H_
#define _PID_H_

#include <stdbool.h>

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

void PID_Init(PID* pid, float p, float i, float d);
void PID_Proportional(PID* pid, float p);
void PID_Integral(PID* pid, float i);
void PID_Derivative(PID* pid, float d);
void PID_WindupPrevention(PID* pid, bool enabled, float limit);
void PID_ClearState(PID* pid);

void  PID_Target(PID* pid, float value);
float PID_Output(PID* pid, float input, float dt);
float PID_Error(PID* pid);

#endif
