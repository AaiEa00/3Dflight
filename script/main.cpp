#include "game.h"
#include "input.h"

#ifdef _DEBUG
int main(void)
{
	// �E�B���h�E���[�h
	ChangeWindowMode(TRUE);
	// HD�掿
	SetGraphMode(SCREEN_SIZE_WIDTH, SCREEN_SIZE_HEIGHT, COLOR_BIT_DEPTH);

#else
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	// �t���X�N���[�����[�h
	ChangeWindowMode(FALSE);
	// FHD�掿
	SetGraphMode(SCREEN_SIZE_WIDTH, SCREEN_SIZE_HEIGHT, COLOR_BIT_DEPTH);
	// ���j�^�[�̉𑜓x��SetGraphMode�Ŏw�肵�����̂ɕύX
	SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_NATIVE);

#endif // _DEBUG

	if (DxLib_Init() == ERROR_END)
		return ERROR_END;

	// ����ʂɕ`��
	SetDrawScreen(DX_SCREEN_BACK);

	if (existsGamepad() == false)
		return NO_GAMEPAD_CONNECTION;

	// �A�����X�g����
	linkedList* list = createLinkedList();

	// �J�����f�[�^�̏�����
	camera* cam = initializeCamera();

	// ���C�����[�v
	while (ProcessMessage() == NORMAL_END && ClearDrawScreen() == NORMAL_END)
	{
		// �������֐������p�Ȃ�
		// �������֐��Ăяo��
		if (list->initializeFlug == isValid::valid)
		{
			// ���X�g�̍Ō���Ƀf�[�^��ǉ�
			for (int i = 0; i < (int)game::gameNum; i++)
			{
				insertAtTail(list, initialize[i]());
				
			}
			// �ǉ����I������珉�����֐��𗘗p�s�ɕύX
			list->initializeFlug = isValid::invalid;
		}

		// ���X�g�E�J�����X�V
		for (int i = 0; i < (int)game::gameNum; i++)
			update[i](searchNode(list, (game)i));

		updateCamera(cam, searchNode(list, game::player));
		// ���X�g�̒��g��`��
		draw(list);

		ScreenFlip();
	}

	releaseLinkedList(list);
	list = NULL;

	DxLib_End();

	return 0;
}