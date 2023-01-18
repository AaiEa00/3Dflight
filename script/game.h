#pragma once
#include "missile.h"
#include "player.h"

/// <summary>
/// 初期化関数
/// </summary>
typedef gameObject(*initializingFunction)(void);
initializingFunction initialize[(int)game::gameNum] = {
	initializePlayer,
	initializeMissile
};

/// <summary>
/// 状態更新関数
/// </summary>
typedef gameObject(*updatingFunction)(listNode*);
updatingFunction update[(int)game::gameNum] = {
	updatePlayer,
	updateMissile
};