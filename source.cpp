//************************************************
// DX���C�u���� �}�E�X�ł��G����
// �쐬���F2024/04/02
// �쐬�ҁFfujioka8700
// Copyright (c) fujioka8700 All rights reserved.
//************************************************

#include <Dxlib.h>
#include "source.hpp"

//================================================
// FPS�̌v���ƕ`��
//================================================
void FpsDraw(LONGLONG* p1, Size* p2)
{
#ifdef _DEBUG
	static int Fps = 0, FpsCnt = 0;

	LONGLONG now = GetNowHiPerformanceCount();
	
	FpsCnt++;
	if (now - *p1 > 1000000)
	{
		Fps = FpsCnt;
		FpsCnt = 0;
		*p1 = now;
	}
	
	DrawFormatString(0, p2->height - 15, GetColor(255, 255, 255), "FPS: %d", Fps);
#endif // !_DEBUG
}

//================================================
// �又��
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

	LONGLONG fpsTimer;
	Size windowSize;
	int x, y;

	GetWindowSize(&windowSize.width, &windowSize.height);

	SetDrawScreen(DX_SCREEN_BACK);

	while (ProcessMessage() == 0)
	{
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			GetMousePoint(&x, &y);
			DrawCircle(x, y, 2, GetColor(255, 0, 0), TRUE);
		}

		FpsDraw(&fpsTimer, &windowSize);
		ScreenFlip();
	}

	DxLib_End();
	return 0;
}