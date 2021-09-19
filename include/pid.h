#ifndef _PID_H_
#define _PID_H_

#include <stdbool.h>

typedef struct
{
	float P;
	float I;
	float D;
	float Target;
	float Integral;
	float Error;
	bool  PreventWindup;
	float WindupLimit;
} PID;

void PID_Init(PID* pid, float p, float i, float d);
void PID_ChangeP(PID* pid, float p);
void PID_ChangeI(PID* pid, float i);
void PID_ChangeD(PID* pid, float d);
void PID_WindupPrevention(PID* pid, bool enabled, float limit);

void  PID_Target(PID* pid, float value);
float PID_Output(PID* pid, float input, float dt);
float PID_Error(PID* pid);

#endif
