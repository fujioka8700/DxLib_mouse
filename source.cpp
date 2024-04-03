//************************************************
// DX���C�u���� �}�E�X�ł��G����
// �쐬���F2024/04/03
// �쐬�ҁFfujioka8700
// Copyright (c) fujioka8700 All rights reserved.
//************************************************

#include <Dxlib.h>
#include "source.h"
#include "palette.h"
#include "fps.h"

//================================================
// �T�v�F�又��
// �߂�l�F����^�ُ�
//================================================
int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd)
{
#ifndef _DEBUG
	SetOutApplicationLogValidFlag(FALSE);
#endif // !_DEBUG

	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1) return -1;

	//LONGLONG fpsTimer;
	Size windowSize;
	POS pre = { -1, -1 }, now;
	int select = 0;

	GetWindowSize(&windowSize.width, &windowSize.height);

	SetDrawScreen(DX_SCREEN_BACK);

	while (ProcessMessage() == 0)
	{
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			GetMousePoint(&now.X, &now.Y);

			if (pre.X >= 0 && pre.Y >= 0)
			{
				DrawLineAA((float)pre.X, (float)pre.Y, (float)now.X, (float)now.Y,
					GetColor(ColorTB[select].R, ColorTB[select].G, ColorTB[select].B), 2.0f);
			}
			pre = now;
		}
		else
		{
			pre.X = pre.Y = -1;
		}

		SelectColor(&select);
		DrawPalette(select);		

		//FpsDraw(&fpsTimer, &windowSize);
		ScreenFlip();
	}

	DxLib_End();
	return 0;
}