#include "game.h"
#include "input.h"

#ifdef _DEBUG
int main(void)
{
	// ウィンドウモード
	ChangeWindowMode(TRUE);
	// HD画質
	SetGraphMode(SCREEN_SIZE_WIDTH, SCREEN_SIZE_HEIGHT, COLOR_BIT_DEPTH);

#else
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	// フルスクリーンモード
	ChangeWindowMode(FALSE);
	// FHD画質
	SetGraphMode(SCREEN_SIZE_WIDTH, SCREEN_SIZE_HEIGHT, COLOR_BIT_DEPTH);
	// モニターの解像度をSetGraphModeで指定したものに変更
	SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_NATIVE);

#endif // _DEBUG

	if (DxLib_Init() == ERROR_END)
		return ERROR_END;

	// 裏画面に描画
	SetDrawScreen(DX_SCREEN_BACK);

	if (existsGamepad() == false)
		return NO_GAMEPAD_CONNECTION;

	// 連結リスト生成
	linkedList* list = createLinkedList();

	// カメラデータの初期化
	camera* cam = initializeCamera();

	// メインループ
	while (ProcessMessage() == NORMAL_END && ClearDrawScreen() == NORMAL_END)
	{
		// 初期化関数が利用可なら
		// 初期化関数呼び出し
		if (list->initializeFlug == isValid::valid)
		{
			// リストの最後尾にデータを追加
			for (int i = 0; i < (int)game::gameNum; i++)
			{
				insertAtTail(list, initialize[i]());
				
			}
			// 追加し終わったら初期化関数を利用不可に変更
			list->initializeFlug = isValid::invalid;
		}

		// リスト・カメラ更新
		for (int i = 0; i < (int)game::gameNum; i++)
			update[i](searchNode(list, (game)i));

		updateCamera(cam, searchNode(list, game::player));
		// リストの中身を描画
		draw(list);

		ScreenFlip();
	}

	releaseLinkedList(list);
	list = NULL;

	DxLib_End();

	return 0;
}