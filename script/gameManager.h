#pragma once
#include "DxLib.h"

/// <summary>
/// ���p��
/// </summary>
enum class isValid
{
	invalid = false,	// ���p�s��
	valid = true		// ���p��
};

/// <summary>
/// �Q�[����ʂ̃I�u�W�F�N�g
/// </summary>
enum class game
{
	player = 0,		// �v���C���[
	missile = 1,	// �~�T�C��
	gameNum	= 2		// �I�u�W�F�N�g�̎�ސ�
};