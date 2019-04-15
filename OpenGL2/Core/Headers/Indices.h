#pragma once
#include <vector>
typedef unsigned int uint;
using namespace std;

class Indice
{
private:
	
	vector<unsigned int>* data;
public:
	Indice();
	Indice* addElement(unsigned int element);
	Indice* addRange(unsigned int from, unsigned int to);
	unsigned int* getPointer();
	int getLength();
};