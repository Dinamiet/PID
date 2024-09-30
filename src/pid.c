#include "pid.h"

void PID_Init(PID* pid, float p, float i, float d)
{
	pid->P             = p;
	pid->I             = i;
	pid->D             = d;
	pid->Target        = 0;
	pid->Integral      = 0;
	pid->Error         = 0;
	pid->PreventWindup = false;
	pid->WindupLimit   = 0;
}

void PID_SetProportional(PID* pid, float p) { pid->P = p; }

void PID_SetIntegral(PID* pid, float i) { pid->I = i; }

void PID_SetDerivative(PID* pid, float d) { pid->D = d; }

void PID_WindupPrevention(PID* pid, bool enabled, float limit)
{
	pid->PreventWindup = enabled;
	pid->WindupLimit   = limit;
}

void PID_ClearState(PID* pid)
{
	pid->Integral = 0;
	pid->Error    = 0;
}

void PID_Target(PID* pid, float value) { pid->Target = value; }

float PID_Output(PID* pid, float input, float dt)
{
	float error = pid->Target - input;

	pid->Integral += error * dt;
	if (pid->PreventWindup)
	{
		if (pid->Integral > pid->WindupLimit)
		{
			pid->Integral = pid->WindupLimit;
		}
		else if (pid->Integral < -pid->WindupLimit)
		{
			pid->Integral = -pid->WindupLimit;
		}
	}

	float p = pid->P * error * dt;
	float i = pid->I * pid->Integral;
	float d = pid->D * (error - pid->Error) * dt;

	pid->Error = error;

	return p + i + d;
}

float PID_Error(PID* pid) { return pid->Error; }
