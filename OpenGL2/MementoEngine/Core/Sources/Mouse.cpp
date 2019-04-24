#include "../Headers/Mouse.h"

Mouse::Mouse()
{
	posX = posY = deltaX = deltaY = 0;
}

void Mouse::setPos(int _posX, int _posY)
{
	deltaX = _posX - posX;
	deltaY = _posY - posY;
	posX = _posX;
	posY = _posY;
}

int Mouse::getDeltaX()
{
	return deltaX;
}

int Mouse::getDeltaY()
{
	return deltaY;
}

int Mouse::getPosX()
{
	return posX;
}

int Mouse::getPosY()
{
	return posY;
}

void Mouse::resetDelta()
{
	deltaX = deltaY = 0;
}