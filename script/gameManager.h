#pragma once
#include "DxLib.h"

/// <summary>
/// 利用可否
/// </summary>
enum class isValid
{
	invalid = false,	// 利用不可
	valid = true		// 利用可
};

/// <summary>
/// ゲーム画面のオブジェクト
/// </summary>
enum class game
{
	player = 0,		// プレイヤー
	missile = 1,	// ミサイル
	gameNum	= 2		// オブジェクトの種類数
};