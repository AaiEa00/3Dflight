#include "player.h"

/// <summary>
/// プレイヤーの初期化
/// </summary>
/// <returns>プレイヤーデータ</returns>
gameObject initializePlayer(void)
{
	gameObject player;

	player.model = MV1LoadModel(PLAYER_MODEL_PATH);
	player.position = ZERO_VECTOR;
	player.rotation = ZERO_VECTOR;
	player.type = game::player;

	return player;
}

/// <summary>
/// プレイヤー情報更新
/// </summary>
/// <param name="node">プレイヤーデータ</param>
void updatePlayer(listNode* node)
{
	inputPlayer(&node->object.position);
	MV1SetPosition(node->object.model, node->object.position);
}
