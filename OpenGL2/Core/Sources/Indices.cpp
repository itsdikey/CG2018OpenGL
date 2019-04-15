#include "../Headers/Indices.h"

Indice::Indice()
{
	data = new vector<unsigned int>();
}

Indice* Indice::addElement(unsigned int element)
{
	data->push_back(element);
	return this;
}

Indice* Indice::addRange(unsigned int from, unsigned int to)
{
	for (unsigned int i = from; i <= to; i++)
	{
		data->push_back(i);
	}
	return this;
}

unsigned int* Indice::getPointer()
{
	return data->data();
}


int Indice::getLength()
{
	return data->size();
}

