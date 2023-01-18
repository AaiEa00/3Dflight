#include "player.h"

/// <summary>
/// �v���C���[�̏�����
/// </summary>
/// <returns>�v���C���[�f�[�^</returns>
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
/// �v���C���[���X�V
/// </summary>
/// <param name="node">�v���C���[�f�[�^</param>
void updatePlayer(listNode* node)
{
	inputPlayer(&node->object.position);
	MV1SetPosition(node->object.model, node->object.position);
}
