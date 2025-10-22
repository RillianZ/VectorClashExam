#include <raylib.h>
#include <string>
#include <iostream>
#include <vector>
#include "Vector2D.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

using namespace std;

/*
The goal of this project is to create a 2D vector class that can be used to perform basic vector operations such as addition,
subtraction, scalar multiplication, and magnitude calculation.

I need to make sure they all have good naming, good commenting, and that the class is usuable and understandable in the future
It should also output to the console the results of the operations performed on the vectors.
*/

int main()
{
	//Screen Setup...
	int screenWidth = 1280;
	int screenHeight = 1024;

	float halfScreenWidth = (float)(screenWidth / 2);
	float halfScreenHeight = (float)(screenHeight / 2);

	// Player Setup
	Player player;
	player.position = { halfScreenWidth, halfScreenHeight };

	// Bullet Setup

	// Enemy Setup

	//Window setup
	InitWindow(screenWidth, screenHeight, "Vector Math Game");
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		// Update
		

		// Drawing
		BeginDrawing();
		ClearBackground(BLACK);

		

		EndDrawing();
	}

	CloseWindow();
	return 0;
}