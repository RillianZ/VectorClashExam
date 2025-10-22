#include "Enemy.h"

void Enemy::Respawn(int inScreenWidth, int inScreenHeight)
{
	position = { (float)(rand() % inScreenWidth), (float)(rand() % inScreenHeight) };
}

void Enemy::Update(Vector2D inTargetPosition)
{
	
}

void Enemy::Draw()
{
	
}