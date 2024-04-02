#include <Dxlib.h>
#include "palette.h"

PALETTE ColorTB[] = {
	{255, 0, 0, {150, 30}},
	{0, 255, 0, {200, 30}},
	{0, 0, 255, {250, 30}},
};

const int COLOR_NUM = sizeof(ColorTB) / sizeof(ColorTB[0]);
const int RADIUS = 20;

void DrawPalette(int index)
{
	DrawCircle(50, 30, RADIUS + 1, GetColor(255, 255, 255), TRUE);
	DrawCircle(50, 30, RADIUS,
		GetColor(ColorTB[index].R, ColorTB[index].G, ColorTB[index].B), TRUE);

	for (size_t i = 0; i < COLOR_NUM; i++)
	{
		DrawCircle(ColorTB[i].POS.X, ColorTB[i].POS.Y, RADIUS + 1,
			GetColor(ColorTB[i].R, ColorTB[i].G, ColorTB[i].B), TRUE);
	}
}