#pragma once
class Time
{
private:
	static float timeSinceLastFrame;
	static float totalAccumTime;

public :
	static float getTimeSinceLastFrame()
	{
		return totalAccumTime;
	}
	static float getTotalAccumTime()
	{
		return totalAccumTime;
	}
	Time();
	void Pulse();
};