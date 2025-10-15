#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <cmath>

class Vector2D
{
public:

	float x;
	float y;

	float CalculateMagnitude();;

	Vector2D SetVectorOffset(Vector2D inVectorToAdd);;

	Vector2D ScaleVector(float inScalar);;

	Vector2D VectorTowardsTarget(Vector2D inTargetVector);;

	float DistanceToTarget(Vector2D inTargetedVector);;

	Vector2D NormalizeVector();;

	Vector2D CosineMovement(Vector2D inCenter, float inAmplitude, float inAngle);;

	Vector2D CircularMotion(Vector2D inCenter, float inRadius, float inAngle);
};
