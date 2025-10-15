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
	int screenWidth = 1280;
	int screenHeight = 1024;

	float halfScreenWidth = (float)(screenWidth / 2);
	float halfScreenHeight = (float)(screenHeight / 2);

	// Player Setup
	Player player;
	player.position = { halfScreenWidth, halfScreenHeight };

	// Bullet Setup
	int AmountOfBullets = 1000;
	vector<Bullet> bulletContainer(AmountOfBullets);

	// Enemy Setup
	int AmountOfEnemies = 1000;
	vector<Enemy> enemyContainer(AmountOfEnemies);

	for (Enemy& enemyInstance : enemyContainer)
	{
		enemyInstance.Respawn(screenWidth, screenHeight);
	}

	for (int i = 0; i < AmountOfEnemies; i++)
	{
		enemyContainer[i].Respawn(screenWidth, screenHeight);
	}


	//Window setup
	InitWindow(screenWidth, screenHeight, "Vector Math Game");
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		// Update
		player.Move();
		Vector2D aimDirection = player.AimDirection();
		for (Enemy& enemyObject : enemyContainer)
		{
			enemyObject.Update(player.position);
		}

		// Shoot bullets
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		{
			for (Bullet& bulletObject : bulletContainer)
			{
				if (bulletObject.isAlive == false)
				{
					bulletObject.Shoot(player.position, aimDirection, 2000.f);
				}
			}
		}
		for (Bullet& bulletObject : bulletContainer)
		{
			bulletObject.Update();
		}

		// Check collision between Bullet and Enemy
		for (Bullet& bulletObject : bulletContainer)
		{
			if (bulletObject.isAlive)
			{
				for (Enemy& enemyObject : enemyContainer)

					if (bulletObject.position.DistanceToTarget(enemyObject.position) < enemyObject.size*8 && bulletObject.isAlive && enemyObject.isAlive)
					{
						enemyObject.Respawn(screenWidth, screenHeight);
						bulletObject.isAlive = false;
					}
			}
		}

		// Drawing
		BeginDrawing();
		ClearBackground(BLACK);

		player.Draw(aimDirection);

		for (Enemy& enemyObject : enemyContainer)
		{
			enemyObject.Draw();
		}
		for (Bullet& bulletObject : bulletContainer)

		{
			bulletObject.Draw();
		}

		EndDrawing();
	}

	CloseWindow();
	return 0;
}