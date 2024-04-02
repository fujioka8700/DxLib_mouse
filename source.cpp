//************************************************
// DXライブラリ マウスでお絵かき
// 作成日：2024/04/03
// 作成者：fujioka8700
// Copyright (c) fujioka8700 All rights reserved.
//************************************************

#include <Dxlib.h>
#include "source.h"
#include "palette.h"

//================================================
// 概要：FPSの計測と描画
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
// 概要：主処理
// 戻り値：正常／異常
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