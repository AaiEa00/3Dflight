#pragma once
#include "gameObject.h"
#include "utility.h"

/// <summary>
/// 範囲
/// </summary>
typedef struct {
	float nearest;		// 最短距離
	float farthest;		// 最長距離
}range;

/// <summary>
/// カメラデータの構造体
/// </summary>
typedef struct {
	range distance;		// カメラで描画可能な範囲
	VECTOR position;	// カメラ位置
}camera;

// カメラデータの初期化
camera* initializeCamera(void);

// カメラデータの更新
void updateCamera(camera* cam, gameObject player);