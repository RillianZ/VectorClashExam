#include "Bullet.h"
#include <raylib.h>

void Bullet::Shoot(Vector2D inStart, Vector2D inDirection, float speed)
{
	position = inStart;
	velocity = inDirection.ScaleVector(speed);
	isAlive = true;
}

void Bullet::Update()
{
	if (isAlive)
	{
		position = position.SetVectorOffset(velocity.ScaleVector(GetFrameTime()));

		if (position.x < 0 || position.x > GetScreenWidth() || position.y < 0 || position.y > GetScreenHeight())
		{
			isAlive = false;
		}
	}
}

void Bullet::Draw()
{
	if (isAlive)
	{
		DrawCircle(position.x, position.y, 10.f, YELLOW);
	}
}