#pragma once
#ifndef PALETTE_H_
#define PALETTE_H_

#include "source.h"

//================================================
// 概要：カラーパレットの色と場所
//================================================
typedef struct {
	int R, G, B;
	POS POS;
} PALETTE;

//================================================
// 概要：カラーパレットの表示
// 引数：index 現在の色
//================================================
void DrawPalette(int index);

#endif // PALETTE_H_