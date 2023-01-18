#pragma once

// ���
#ifdef _DEBUG
#define	SCREEN_SIZE_WIDTH			1024							// �f�o�b�O���̃X�N���[����
#define	SCREEN_SIZE_HEIGHT			768								// �f�o�b�O���̃X�N���[����
#else
#define	SCREEN_SIZE_WIDTH			1920							// �����[�X���̃X�N���[����
#define	SCREEN_SIZE_HEIGHT			1080							// �����[�X���̃X�N���[����
#endif // _DEBUG
#define	COLOR_BIT_DEPTH				32								// �r�b�g�̐[��

// �I���R�[�h
#define	NORMAL_END					0								// ����I��
#define	ERROR_END					-1								// �ُ�I��
#define	MEMORY_ERROR				1								// �������̊m�ۂɎ��s
#define	NO_GAMEPAD_CONNECTION		-2								// �Q�[���p�b�h���ڑ�����Ă��Ȃ�

// ����
#define	MINIMUM_NUMBER_OF_PEOPLE	1								// �Q�[���v���C�ŏ��l��
#define	PUSHED_KEY					1								// ������Ă���

// �Q�[���I�u�W�F�N�g
#define	ZERO_VECTOR					(VGet(0.0f, 0.0f, 0.0f))		// �[���x�N�g��

// �v���C���[
#define	PLAYER_MODEL_PATH			"resource/Stealth_Bomber.mv1"		// �v���C���[�̃��f���ւ̃p�X
#define	PLAYER_MOVE_SPEED			0.001f							// �v���C���[�̈ړ����x

// ���f��
#define	MISSILE_MODEL_PATH			"resource/CruiseMissile.mv1"		// �~�T�C���̃��f���ւ̃p�X

// �J����
#define DRAWABLE_RANGE_NEAREST		1.0f							// �J�����ŕ`��\�ȍŒZ����
#define DRAWABLE_RANGE_FARTHEST		1000.0f							// �J�����ŕ`��\�ȍŒ�����
#define	CAMERA_INITIAL_POSITION		(VGet(0.0f, 25.0f, 45.0f))		// �J�����̏����ʒu