#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Vector2D.h"
#include "Player.h"

class Bullet
{
public:
	Vector2D position;
	Vector2D velocity;
	bool isAlive{ false };

	void Shoot(Vector2D inStart, Vector2D inDirection, float speed);

	void Update();

	void Draw();
};
