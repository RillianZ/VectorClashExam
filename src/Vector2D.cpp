#include "Vector2D.h"

float Vector2D::CalculateMagnitude()
{
	float magnitudeSquared = x * x + y * y;
	float magnitude = sqrtf(magnitudeSquared);
	return magnitude;
}

Vector2D Vector2D::SetVectorOffset(Vector2D inVectorToAdd)
{
	float outVectorX = x + inVectorToAdd.x;
	float outVectorY = y + inVectorToAdd.y;
	Vector2D outVector{ outVectorX, outVectorY };

	return outVector;
}

Vector2D Vector2D::ScaleVector(float inScalar)
{
	float scaledXVector = x * inScalar;
	float scaledYVector = y * inScalar;
	Vector2D scaledVector{ scaledXVector, scaledYVector };

	return scaledVector;
}

Vector2D Vector2D::VectorTowardsTarget(Vector2D inTargetVector)
{
	float targetedXVector = inTargetVector.x - x;
	float targetedYVector = inTargetVector.y - y;
	Vector2D targetedVector{ targetedXVector , targetedYVector };

	return targetedVector;
}

float Vector2D::DistanceToTarget(Vector2D inTargetedVector)
{
	Vector2D targetedVector = VectorTowardsTarget(inTargetedVector);
	float distanceToTargetedVector = targetedVector.CalculateMagnitude();

	return distanceToTargetedVector;
}

Vector2D Vector2D::NormalizeVector()
{
	if (CalculateMagnitude() == 0)
	{
		return { 0, 0 };
	}

	float normalizedXVector = x / CalculateMagnitude();
	float normalizedYVector = y / CalculateMagnitude();
	Vector2D normalizedVector{ normalizedXVector,normalizedYVector };

	return normalizedVector;
}

Vector2D Vector2D::CosineMovement(Vector2D inCenter, float inAmplitude, float inAngle)
{
	float x = inCenter.x + inAmplitude * cosf(inAngle);
	float y = inCenter.y;

	return { x, y };
}

Vector2D Vector2D::CircularMotion(Vector2D inCenter, float inRadius, float inAngle)
{
	float cosX = inCenter.x + inRadius * cosf(inAngle);
	float sinY = inCenter.y + inRadius * sinf(inAngle);

	return { cosX, sinY };
}