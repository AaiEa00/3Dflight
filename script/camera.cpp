#include "camera.h"

/// <summary>
/// カメラデータの初期化
/// </summary>
/// <returns>生成したカメラのデータ</returns>
camera* initializeCamera(void)
{
	camera* cam = (camera*)malloc(sizeof(camera));
	if (cam == NULL)
		exit(MEMORY_ERROR);

	// カメラが描画できる範囲を設定
	cam->distance.farthest = DRAWABLE_RANGE_FARTHEST;
	cam->distance.nearest = DRAWABLE_RANGE_NEAREST;
	SetCameraNearFar(cam->distance.nearest, cam->distance.farthest);

	// 要確認：不要？
	cam->position = CAMERA_INITIAL_POSITION;

	return cam;
}

/// <summary>
/// カメラの状態更新
/// </summary>
/// <param name="cam">カメラのデータ</param>
/// <param name="player">プレイヤーのデータ</param>
void updateCamera(camera* cam, gameObject player)
{
	// カメラの位置を更新
	cam->position = VAdd(CAMERA_INITIAL_POSITION, player.position);
	//printf("cam[x: %.1f, y: %.1f, z: %.1f]\n", cam->position.x, cam->position.y, cam->position.z);
	// カメラの注視点と位置を更新
	SetCameraPositionAndTarget_UpVecY(cam->position, player.position);
}
