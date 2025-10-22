#include <raylib.h>
#include <string>
#include <iostream>
#include <vector>
#include "Vector2D.h"
#include "Player.h"
#include "Enemy.h"

using namespace std;

/*
* README---------------------------------------------------
The goal of this project is to create a game that is a mix of Snake and Troncycles, it must have good use of classes. 

And needs to show of math that can be used to perform basic vector operations such as addition,
subtraction, scalar multiplication, and magnitude calculation.

I need to make sure they all have good naming, good commenting, and that the class is usuable and understandable in the future

It should also output to the console the results of the operations performed on the vectors. For Debugging

The main planned classes are 
Player, Enemy, Powerups, Math/Vector2D, A game manager, map editor
The rest of the calculations goes into the main

There are 2 stages to start with, (more to be added later?) 
The first stage is just wall boundaries, 
the second has some obstacles in the center of the screen.

There are 3 powerups to start with (one with a twist) (more to be added later?) 
Speedup/down, Split tail(Allows collison with tail to cut of the tail), and ghost mode (collison off for a few seconds)
All powerups are just simple different colored rectangles

There are 3 "Bikes"/Players to start with, (More to be added later?)
Viper(Normal) Bruiser(Slow and grows fast), Ghost(Fast and grows slow)

It should have a dynamic growing tail for the player
The player moves in 2 directions left and right
the Tail follows the player object

Collison checks on tail, walls, and powerups

First i will make and test the player and the movement and tail, then add the powerups, then the enemies, then the stages, scoring , and finally polish

README END------------------------------------------------

*/

//Global variables
Vector2D Test = { 1.f, 0.f };

int main()
{
	//Screen Setup...
	int screenWidth = 1280;
	int screenHeight = 1024;

	float halfScreenWidth = (float)(screenWidth / 2);
	float halfScreenHeight = (float)(screenHeight / 2);

	// Player Setup
	//Needs to change placing based on amount of active players
	Player player;
	player.position = { halfScreenWidth, halfScreenHeight };

	//Powerups
	//After PLAYER
	
	// Enemy Setup
	//AFTER PLAYER!

	//Window setup
	InitWindow(screenWidth, screenHeight, "Vector Clash");
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		// Update
		player.Move();

		// Drawing
		BeginDrawing();
		ClearBackground(BLACK);
		player.Draw(Test);

		

		EndDrawing();
	}

	CloseWindow();
	return 0;
}