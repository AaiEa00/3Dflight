#pragma once
#include "gameObject.h"
#include "utility.h"

/// <summary>
/// �͈�
/// </summary>
typedef struct {
	float nearest;		// �ŒZ����
	float farthest;		// �Œ�����
}range;

/// <summary>
/// �J�����f�[�^�̍\����
/// </summary>
typedef struct {
	range distance;		// �J�����ŕ`��\�Ȕ͈�
	VECTOR position;	// �J�����ʒu
}camera;

// �J�����f�[�^�̏�����
camera* initializeCamera(void);

// �J�����f�[�^�̍X�V
void updateCamera(camera* cam, gameObject player);