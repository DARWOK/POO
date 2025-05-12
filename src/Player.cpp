#include "Player.h"

// sobrecargar la función update de GameObject para mover el objeto con las teclas
void Player::update()
{
	if (IsKeyDown(KEY_A))
	{
		position.x -= speed*GetFrameTime();
	}
	if (IsKeyDown(KEY_D))
	{
		position.x += speed*GetFrameTime();
	}
	if (IsKeyDown(KEY_E))
	{
		position.y -= speed*GetFrameTime();
	}
	if (IsKeyDown(KEY_S))
	{
		position.y += speed*GetFrameTime();
	}
}