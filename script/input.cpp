#include "input.h"

/// <summary>
/// �Q�[���p�b�h�̐ڑ������m�F����
/// </summary>
/// <returns>�Q�[���p�b�h��1�ȏ�ڑ�����Ă����true</returns>
bool existsGamepad(void)
{
	// �v�m�F�i���b�Z�[�W�o���H�j
	return ((MINIMUM_NUMBER_OF_PEOPLE <= GetJoypadNum()) ? true : false);
}

/// <summary>
/// �v���C���[�Ɋւ�����͏����󂯕t����
/// </summary>
/// <param name="object">�v���C���[�̏��</param>
void inputPlayer(gameObject* object)
{
	XINPUT_STATE input;
	GetJoypadXInputState(DX_INPUT_PAD1, &input);

	// RT�ŉ���
	// �v�m�F�i�����̎d���j
	object->position.z += input.RightTrigger * PLAYER_ACCELERATION;
	
	// L�X�e�B�b�N�c���ŋ@����グ����
	object->rotation.x += input.ThumbLY * PLAYER_ROTATE_SPEED;
	printf("%d\n", input.ThumbLY);

	//printf("player[x: %.1f, y: %.1f, z: %.1f]\n", 
		//object->position.x, object->position.y, object->position.z);

}