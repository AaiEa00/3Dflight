#pragma once
#include "gameManager.h"

/// <summary>
/// ゲームオブジェクトのデータ
/// </summary>
typedef struct {
	int model;			// モデルハンドル
	VECTOR position;	// 座標
	VECTOR rotation;	// 回転
	game type;			// ゲーム画面のオブジェクトの種類
}gameObject;