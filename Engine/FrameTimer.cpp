#include "FrameTimer.h"
#include<chrono>

using std::chrono::steady_clock;

float FrameTimer::Mark()
{
	const auto old = mLast;
	mLast = steady_clock::now();
	const std::chrono::duration<float>frameTime = mLast - old;
	return frameTime.count();
}
