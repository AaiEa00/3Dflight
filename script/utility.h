#pragma once

// 画面
#ifdef _DEBUG
#define	SCREEN_SIZE_WIDTH			1024							// デバッグ時のスクリーン幅
#define	SCREEN_SIZE_HEIGHT			768								// デバッグ時のスクリーン高
#else
#define	SCREEN_SIZE_WIDTH			1920							// リリース時のスクリーン幅
#define	SCREEN_SIZE_HEIGHT			1080							// リリース時のスクリーン高
#endif // _DEBUG
#define	COLOR_BIT_DEPTH				32								// ビットの深さ

// 終了コード
#define	NORMAL_END					0								// 正常終了
#define	ERROR_END					-1								// 異常終了
#define	MEMORY_ERROR				1								// メモリの確保に失敗
#define	NO_GAMEPAD_CONNECTION		-2								// ゲームパッドが接続されていない

// 入力
#define	MINIMUM_NUMBER_OF_PEOPLE	1								// ゲームプレイ最少人数
#define	PUSHED_KEY					1								// 押されている

// ゲームオブジェクト
#define	ZERO_VECTOR					(VGet(0.0f, 0.0f, 0.0f))		// ゼロベクトル

// プレイヤー
#define	PLAYER_MODEL_PATH			"resource/Stealth_Bomber.mv1"		// プレイヤーのモデルへのパス
#define	PLAYER_MOVE_SPEED			0.001f							// プレイヤーの移動速度

// モデル
#define	MISSILE_MODEL_PATH			"resource/CruiseMissile.mv1"		// ミサイルのモデルへのパス

// カメラ
#define DRAWABLE_RANGE_NEAREST		1.0f							// カメラで描画可能な最短距離
#define DRAWABLE_RANGE_FARTHEST		1000.0f							// カメラで描画可能な最長距離
#define	CAMERA_INITIAL_POSITION		(VGet(0.0f, 25.0f, 45.0f))		// カメラの初期位置