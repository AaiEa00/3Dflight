#include "missile.h"

/// <summary>
/// �~�T�C���f�[�^�̏�����
/// </summary>
/// <returns>�v���C���[�f�[�^</returns>
gameObject initializeMissile(void)
{
	gameObject missile;

	missile.model = MV1LoadModel(MISSILE_MODEL_PATH);
	missile.position = ZERO_VECTOR;
	missile.rotation = ZERO_VECTOR;
	missile.type = game::missile;

	return missile;
}

void updateMissile(listNode* node)
{
}
