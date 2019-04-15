#ifndef LayoutCore
#define LayoutCore
#endif
#pragma once
#include <vector>
#include <GL\glew.h>
using namespace std;
class Layout
{
private:
	int stride=0, length = 0;
	vector<int>* offsets;
	vector<int>* sizes;
	vector<int>* rawSizes;
	vector<int>* types;
	vector<int>* indices;
public:
	template <class T>
	Layout* addItem(int index,int type, int count)
	{
		indices->push_back(index);
		int currentSize = sizeof(T) * count;
		sizes->push_back(count);
		rawSizes->push_back(sizeof(T));
		types->push_back(type);
		if (length == 0)
			offsets->push_back(0);
		else
		{
			offsets->push_back(sizes->at(length - 1)*rawSizes->at(length - 1));
		}
		stride += currentSize;
		length++;
		return this;
	};
	GLenum getType(int index);
	int getSize(int index);
	int getOffset(int index); 
	int getIndex(int index);
	int getElementCount();
	int getStride();
	void* getOffsetVPtr(int index);
	static Layout create();
	Layout();
};