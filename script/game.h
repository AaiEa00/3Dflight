#pragma once
#include "missile.h"
#include "player.h"

/// <summary>
/// �������֐�
/// </summary>
typedef gameObject(*initializingFunction)(void);
initializingFunction initialize[(int)game::gameNum] = {
	initializePlayer,
	initializeMissile
};

/// <summary>
/// ��ԍX�V�֐�
/// </summary>
typedef void(*updatingFunction)(listNode*);
updatingFunction update[(int)game::gameNum] = {
	updatePlayer,
	updateMissile
};