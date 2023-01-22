#pragma once
#include "missile.h"
#include "player.h"

/// <summary>
/// ‰Šú‰»ŠÖ”
/// </summary>
typedef gameObject(*initializingFunction)(void);
initializingFunction initialize[(int)game::gameNum] = {
	initializePlayer,
	initializeMissile
};

/// <summary>
/// ó‘ÔXVŠÖ”
/// </summary>
typedef void(*updatingFunction)(listNode*);
updatingFunction update[(int)game::gameNum] = {
	updatePlayer,
	updateMissile
};