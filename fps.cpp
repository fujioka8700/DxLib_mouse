#include <DxLib.h>
#include "fps.h"
#include "source.h"

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