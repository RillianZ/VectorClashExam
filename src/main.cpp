#include <raylib.h>
#include <string>
#include <iostream>


/*
The goal of this project is to create a 2D vector class that can be used to perform basic vector operations such as addition, 
subtraction, scalar multiplication, and magnitude calculation.

I need to make sure they all have good naming, good commenting, and that the class is usuable and understandable in the future
It should also output to the console the results of the operations performed on the vectors.


*/
class Vector2D
{

public:
	float x;
	float y;

	float offsetX = 1.0f;
	float offsetY = 1.0f;

	float ScalarMultipler = 4.0f;


	float CalculateMagnitude()
	{
		return  sqrtf(x * x + y * y);
	}

	float CalculateMagnitudeDetailed()
	{
		float magnitudeSquared = x * x + y * y;
		float magnitude = sqrtf(magnitudeSquared);
		return  magnitude;
	}

	Vector2D SetVectorOffset(Vector2D InvectorToAdd)
	{
		float outVectorX = x + InvectorToAdd.x;
		float outVectorY = y + InvectorToAdd.y;
		Vector2D outvector = { outVectorX, outVectorY };
		return outvector;

		// specific version underneath
		//return { ((outVectorX), (outVectorY)) };
	}

	Vector2D ScalarVector(float ScalarMultipler)
	{
	float scaledXVector = x * ScalarMultipler;
	float scaledYVector = y * ScalarMultipler;
	Vector2D scaledVector = { scaledXVector, scaledYVector };
	return scaledVector;
	}

	Vector2D VectorTowardsTarget (Vector2D inTargetVector)
	{
		float outVectorXTarget = x - inTargetVector.x;
		float outVectorYTarget = y - inTargetVector.y;

		Vector2D TargetVector = { outVectorXTarget, outVectorYTarget };
		return TargetVector;
	}

	float DistanceToTarget(Vector2D inTargetVector)
	{
		Vector2D targetVector = VectorTowardsTarget(inTargetVector);
		float lengthoftargetedVector = targetVector.CalculateMagnitude();

		return lengthoftargetedVector;

	}
};

int main()
{

	int screenWidth = 1280;
	int screenHeight = 1024;

	InitWindow(screenWidth, screenHeight, "Vector Math");
	SetTargetFPS(60);


	Vector2D coolVector = { 100,100 };
	std::cout << "X: " << coolVector.x << " Y: " << coolVector.y << std::endl;

	coolVector = coolVector.SetVectorOffset({ 50,10 });

	std::cout << "X: " << coolVector.x << " Y: " << coolVector.y << std::endl;



	//Subtraction
	Vector2D TESTVARIABLE = { 10, 10 };

	TESTVARIABLE = TESTVARIABLE.VectorTowardsTarget({ 50,50 });

	std::cout << "X: " << TESTVARIABLE.x << " Y: " << TESTVARIABLE.y << std::endl;



	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(BLACK);

		EndDrawing();
	}

	CloseWindow();
}