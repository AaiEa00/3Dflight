#pragma once
#include "linkedList.h"

// ミサイルデータの初期化
gameObject initializeMissile(void);

// ミサイルの状態更新
void updateMissile(listNode* node);