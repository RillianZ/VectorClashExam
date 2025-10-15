#include "Enemy.h"

void Enemy::Respawn(int inScreenWidth, int inScreenHeight)
{
	position = { (float)(rand() % inScreenWidth), (float)(rand() % inScreenHeight) };
}

void Enemy::Update(Vector2D inTargetPosition)
{
	if (isAlive)
	{
		Vector2D direction = position.VectorTowardsTarget(inTargetPosition).NormalizeVector();
		position = position.SetVectorOffset(direction.ScaleVector(speed * GetFrameTime()));

		if (position.DistanceToTarget(inTargetPosition) < 25.f)
		{
			Respawn(GetScreenWidth(), GetScreenHeight());
		}
	}
}

void Enemy::Draw()
{
	if (isAlive)
	{
		DrawCircle(position.x, position.y, size, BLUE);
	}
}