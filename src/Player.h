#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Vector2D.h"
#include <raylib.h>

class Player
{
public:
	Vector2D position;
	float speed = 300.f;
	float size = 25.f;

	void Move();

	void Draw(Vector2D aimDirection);

	Vector2D AimDirection();
};
