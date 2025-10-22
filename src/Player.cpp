#include "Player.h"
//Change this to be  modular so it can contain movement controls for up to 4 players. (A,D/ArrowLeft,ArrowRight/1,3/U,O)
//Character must be modular, must move forward at a "set pace" and tail being generated must grow at a steady tick.
void Player::Move()
{
	Vector2D offsetPosition{ 0.f, 0.f };
	
	//Change this from X position movement to rotating the player instead)
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
//Draws the snake
void Player::Draw(Vector2D aimDirection)
{
	DrawCircle(position.x, position.y, size, DARKPURPLE);
	DrawLine(position.x, position.y, position.x + aimDirection.x * 30.f,
		position.y + aimDirection.y * 30.f, GREEN);
}

//rewrite this to aim forward on the snake visually and update to the new direction as the snake turns towards it.
//The snake is always trying to move towards aim direction
Vector2D Player::AimDirection()
{
	Vector2D mousePosition{ GetMouseX(),GetMouseY() };
	Vector2D towardsMouseVector = position.VectorTowardsTarget(mousePosition).NormalizeVector();

	return towardsMouseVector;
}