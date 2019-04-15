#include "../Headers/Layout.h"
Layout::Layout()
{
	offsets = new vector<int>();
	sizes = new vector<int>();
	rawSizes = new vector<int>();
	types = new vector<int>();
	indices = new vector<int>();
	stride = 0;
}



Layout Layout::create() {
	return *(new Layout());
}

GLenum Layout::getType(int index)
{
	return types->at(index);
}

int Layout::getSize(int index)
{
	return sizes->at(index);
}

int Layout::getOffset(int index)
{
	return offsets->at(index);
}

int Layout::getIndex(int index)
{
	return indices->at(index);
}

int Layout::getElementCount()
{
	return length;
}

int Layout::getStride()
{
	return stride;
}

void * Layout::getOffsetVPtr(int index)
{
	return (void*)getOffset(index);
}




