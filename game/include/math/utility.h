#pragma once
#include <math.h>

bool floatEq(float x1, float x2) {
	return fabsf(x1 - x2) < .0001;
}
