#include "input.h"

/// <summary>
/// ゲームパッドの接続数を確認する
/// </summary>
/// <returns>ゲームパッドが1つ以上接続されていればtrue</returns>
bool existsGamepad(void)
{
	// 要確認（メッセージ出す？）
	return ((MINIMUM_NUMBER_OF_PEOPLE <= GetJoypadNum()) ? true : false);
}

/// <summary>
/// プレイヤーに関する入力情報を受け付ける
/// </summary>
/// <param name="object">プレイヤーの情報</param>
void inputPlayer(gameObject* object)
{
	XINPUT_STATE input;
	GetJoypadXInputState(DX_INPUT_PAD1, &input);

	// RTで加速
	// 要確認（加速の仕方）
	object->position.z += input.RightTrigger * PLAYER_ACCELERATION;
	
	// Lスティック縦軸で機首を上げ下げ
	object->rotation.x += input.ThumbLY * PLAYER_ROTATE_SPEED;
	printf("%d\n", input.ThumbLY);

	//printf("player[x: %.1f, y: %.1f, z: %.1f]\n", 
		//object->position.x, object->position.y, object->position.z);

}