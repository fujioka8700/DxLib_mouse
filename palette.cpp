#include <Dxlib.h>
#include <math.h>
#include "palette.h"

PALETTE ColorTB[] = {
	{255,   0,   0, {150, 30}},
	{  0, 255,   0, {200, 30}},
	{  0,   0, 255, {250, 30}},
	{255,   0, 255, {300, 30}},
	{255, 255,   0, {350, 30}},
	{0  , 255, 255, {400, 30}},
};

const int COLOR_NUM = sizeof(ColorTB) / sizeof(ColorTB[0]);
const int RADIUS = 20;
static bool MouseLeftClick = false;

void DrawPalette(int index)
{
	DrawCircle(50, 30, RADIUS + 1, GetColor(255, 255, 255), TRUE);
	DrawCircle(50, 30, RADIUS,
		GetColor(ColorTB[index].R, ColorTB[index].G, ColorTB[index].B), TRUE);

	for (int i = 0; i < COLOR_NUM; i++)
	{
		DrawCircle(ColorTB[i].POS.X, ColorTB[i].POS.Y, RADIUS + 1,
			GetColor(ColorTB[i].R, ColorTB[i].G, ColorTB[i].B), TRUE);
	}
}

void SelectColor(int* index)
{
	int button, clickX, clickY, logType;

	MouseLeftClick = false;

	if (GetMouseInputLog2(&button, &clickX, &clickY, &logType, TRUE) == 0)
	{
		if ((button & MOUSE_INPUT_LEFT) != 0 && logType == MOUSE_INPUT_LOG_UP)
		{
			MouseLeftClick = true;

			for (int i = 0; i < COLOR_NUM; i++)
			{
				double d = pow((clickX - ColorTB[i].POS.X), 2) + pow((clickY - ColorTB[i].POS.Y), 2);
				if (d <= pow(RADIUS, 2))
				{
					*index = i;
					break;
				}
			}
		}
	}
}

void CheckDoubleClick(void)
{
	const int DOUBLE_CLICK_INTERVAL = 300;
	static int lastClickTime = 0;
	int now = GetNowCount();

	if (MouseLeftClick && lastClickTime == 0)
	{
		lastClickTime = now;
	}
	else if (MouseLeftClick && now - lastClickTime <= DOUBLE_CLICK_INTERVAL) {
		ClearDrawScreen();
		lastClickTime = 0;
	}
	else if (now - lastClickTime > DOUBLE_CLICK_INTERVAL) {
		lastClickTime = 0;
	}
}