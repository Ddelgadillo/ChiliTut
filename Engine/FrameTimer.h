#pragma once
#include<chrono>

class FrameTimer
{
public:
	float Mark();
private:
	std::chrono::steady_clock::time_point mLast;
};