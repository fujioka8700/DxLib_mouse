#pragma once
#ifndef PALETTE_H_
#define PALETTE_H_

#include "source.h"

//================================================
// �T�v�F�J���[�p���b�g�̐F�Əꏊ
//================================================
typedef struct {
	int R, G, B;
	POS POS;
} PALETTE;

//================================================
// �T�v�F�J���[�p���b�g�̕\��
// �����Findex ���݂̐F
//================================================
void DrawPalette(int index);

#endif // PALETTE_H_