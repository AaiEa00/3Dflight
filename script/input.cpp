#include "input.h"

bool existsGamepad(void)
{
	return ((MINIMUM_NUMBER_OF_PEOPLE <= GetJoypadNum()) ? true : false);
}

void inputPlayer(VECTOR* position)
{
	XINPUT_STATE input;
	GetJoypadXInputState(DX_INPUT_PAD1, &input);
	position->x += input.ThumbLX * PLAYER_MOVE_SPEED;
	//printf("player[x: %.1f, y: %.1f, z: %.1f]\n", position->x, position->y, position->z);
}