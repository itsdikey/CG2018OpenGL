#include <chrono>
using namespace std::chrono;
#pragma once
class Time
{
private:
	static float timeSinceLastFrame;
	static float totalAccumTime;
	static milliseconds ms;
public :
	static float getTimeSinceLastFrame()
	{
		return timeSinceLastFrame;
	}
	static float getTotalAccumTime()
	{
		return totalAccumTime;
	}
	static void init()
	{
		ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
		totalAccumTime = timeSinceLastFrame = 0;
	}
	static void Pulse()
	{
		milliseconds newMs = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
		timeSinceLastFrame = (newMs.count() - ms.count()) / 1000.0f;
		totalAccumTime += timeSinceLastFrame;
		ms = newMs;
	}
};

