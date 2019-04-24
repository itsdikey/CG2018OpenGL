#pragma once
class Mouse
{
private:
	int deltaX, deltaY, posX, posY;
public:
	Mouse();
	int getPosX();
	int getPosY();
	int getDeltaX();
	int getDeltaY();
	void setPos(int x, int y);
	void resetDelta();
};