#pragma once
#include "linkedList.h"
#include "input.h"

// プレイヤーデータの初期化
gameObject initializePlayer(void);

// プレイヤーの状態更新
void updatePlayer(listNode* node);