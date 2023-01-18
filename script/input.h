#pragma once
#include "camera.h"

// ゲームパッドが接続されているか
bool existsGamepad(void);

// プレイヤーへの入力
void inputPlayer(VECTOR* position);