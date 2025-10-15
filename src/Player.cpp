#include "Player.h"

void Player::Move()
{
	Vector2D offsetPosition{ 0.f, 0.f };
	if (IsKeyDown(KEY_W))
	{
		offsetPosition.y -= 1;
	}

	if (IsKeyDown(KEY_S))
	{
		offsetPosition.y += 1;
	}

	if (IsKeyDown(KEY_A))
	{
		offsetPosition.x -= 1;
	}

	if (IsKeyDown(KEY_D))
	{
		offsetPosition.x += 1;
	}

	offsetPosition = offsetPosition.NormalizeVector();

	position = position.SetVectorOffset(offsetPosition.ScaleVector(speed * GetFrameTime()));
}

void Player::Draw(Vector2D aimDirection)
{
	DrawCircle(position.x, position.y, size, DARKPURPLE);
	DrawLine(position.x, position.y, position.x + aimDirection.x * 30.f,
		position.y + aimDirection.y * 30.f, GREEN);
}

Vector2D Player::AimDirection()
{
	Vector2D mousePosition{ GetMouseX(),GetMouseY() };
	Vector2D towardsMouseVector = position.VectorTowardsTarget(mousePosition).NormalizeVector();

	return towardsMouseVector;
}