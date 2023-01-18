#include "camera.h"

/// <summary>
/// �J�����f�[�^�̏�����
/// </summary>
/// <returns>���������J�����̃f�[�^</returns>
camera* initializeCamera(void)
{
	camera* cam = (camera*)malloc(sizeof(camera));
	if (cam == NULL)
		exit(MEMORY_ERROR);

	// �J�������`��ł���͈͂�ݒ�
	cam->distance.farthest = DRAWABLE_RANGE_FARTHEST;
	cam->distance.nearest = DRAWABLE_RANGE_NEAREST;
	SetCameraNearFar(cam->distance.nearest, cam->distance.farthest);

	// �v�m�F�F�s�v�H
	cam->position = CAMERA_INITIAL_POSITION;

	return cam;
}

/// <summary>
/// �J�����̏�ԍX�V
/// </summary>
/// <param name="cam">�J�����̃f�[�^</param>
/// <param name="player">�v���C���[�̃f�[�^</param>
void updateCamera(camera* cam, gameObject player)
{
	// �J�����̈ʒu���X�V
	cam->position = VAdd(CAMERA_INITIAL_POSITION, player.position);
	//printf("cam[x: %.1f, y: %.1f, z: %.1f]\n", cam->position.x, cam->position.y, cam->position.z);
	// �J�����̒����_�ƈʒu���X�V
	SetCameraPositionAndTarget_UpVecY(cam->position, player.position);
}
