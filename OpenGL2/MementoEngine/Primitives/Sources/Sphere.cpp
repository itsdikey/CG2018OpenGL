#include "../Headers/Sphere.h"
#ifndef Utils
#define Utils
#include "../../Headers/Utils.h"
#endif
constexpr auto PI = 3.14159265f;
Sphere::Sphere(float radius, int stackCount, int sectorCount)
{
	std::vector<float> vertices;
	std::vector<float>().swap(vertices);

	float x, y, z, xy;                              // vertex position
	float nx, ny, nz, lengthInv = 1.0f / radius;    // vertex normal
	float s, t;                                     // vertex texCoord

	float sectorStepAngle = 2 * PI / sectorCount;
	float stackStepAngle = PI / stackCount;
	float sectorAngle, stackAngle;

	int num = 0;




	//upper point
	for (int i = 0; i <= stackCount; i++)
	{
		stackAngle = i * stackStepAngle;
		if (i == 0 || i == stackCount)
		{
			glm::vec3 cartesian = Utils::toCartesianFromSphere(radius, stackAngle, PI);
			vertices.push_back(cartesian.x);
			vertices.push_back(cartesian.y);
			vertices.push_back(cartesian.z);
#if DEBUG
			cout << num++ << ": x: " << cartesian.x << " y: " << cartesian.y << " z: " << cartesian.z << endl;
#endif
			vertices.push_back(cartesian.x*lengthInv);
			vertices.push_back(cartesian.y*lengthInv);
			vertices.push_back(cartesian.z*lengthInv);
			continue;
		}
		else
		{
			for (int j = 0; j <= sectorCount; j++)
			{
				sectorAngle = j * sectorStepAngle;
				glm::vec3 cartesian = Utils::toCartesianFromSphere(radius, stackAngle, sectorAngle);


				vertices.push_back(cartesian.x);
				vertices.push_back(cartesian.y);
				vertices.push_back(cartesian.z);
#if DEBUG
				cout << num++ << ": x: " << cartesian.x << " y: " << cartesian.y << " z: " << cartesian.z << " phi: " << sectorAngle << endl;
#endif
				vertices.push_back(cartesian.x*lengthInv);
				vertices.push_back(cartesian.y*lengthInv);
				vertices.push_back(cartesian.z*lengthInv);
			}
		}
	}
#if DEBUG
	cout << "Indices";
#endif
	std::vector<unsigned int> fanIndices;
	Indice* fanIndice = new Indice();

	Indice* lowerFanIndice = new Indice();
	Indice* stripIndice = new Indice();

	
	for (unsigned int i = 0; i <= stackCount + 1; i++)
	{
#if DEBUG
		cout << "Index added: " << i << endl;

#endif
		fanIndice->addElement(i);
	}

	lowerFanIndice->addElement(stackCount*sectorCount);

	for (unsigned int i = (stackCount - 1)*sectorCount - 1; i < stackCount*sectorCount; i++)
	{
#if DEBUG
		cout << "Index added: " << i << endl;

#endif
		lowerFanIndice->addElement(i);
	}

	for (int i = 0; i < stackCount - 2; i++)
	{
		int startIndex = i * (sectorCount + 1) + 1;
		int nextRowIndex = (i + 1) * (sectorCount + 1) + 1;
		stripIndice->addElement((unsigned int)startIndex);
		stripIndice->addElement((unsigned int)nextRowIndex);

		stripIndice->addElement((unsigned int)startIndex + 1);
#if DEBUG
		cout << "Added #1 " << startIndex << " -> " << nextRowIndex << " -> " << startIndex + 1 << endl;

#endif

		startIndex += 2;
		nextRowIndex++;
		for (int j = 0; j < sectorCount; j++)
		{
			stripIndice->addElement((unsigned int)nextRowIndex);
#if DEBUG
			cout << " -> " << nextRowIndex;
#endif
			if (startIndex == (i + 1) * (sectorCount + 1) + 1)
			{
				stripIndice->addElement((unsigned int)nextRowIndex);
#if DEBUG
				cout << " -> " << nextRowIndex;

#endif
			}
			stripIndice->addElement((unsigned int)startIndex);
#if DEBUG
			cout << " -> " << startIndex
#endif
				startIndex++;
			nextRowIndex++;

		}

		cout << endl;
	}

	VAOWrapper* vao = new VAOWrapper();
	VBO* vbo = new VBO(GL_ARRAY_BUFFER);
	vao->bindBuffer();
	vbo->bindBuffer();
	vbo->setData(GL_STATIC_DRAW, vertices.size() * sizeof(float), vertices.data());

	RenderComb* upperRenderComb = new RenderComb(GL_TRIANGLE_FAN);
	upperRenderComb->setIndices(fanIndice);

	RenderComb* lowerRenderComb = new RenderComb(GL_TRIANGLE_FAN);
	lowerRenderComb->setIndices(lowerFanIndice);

	RenderComb* restRenderComb = new RenderComb(GL_TRIANGLE_STRIP);
	restRenderComb->setIndices(stripIndice);

	Layout* layout = new Layout();

	layout->
		addItem<float>(0, GL_FLOAT, 3)->
		addItem<float>(1, GL_FLOAT, 3);

	vao->setLayout(layout);


	
	this->addVao(*vao)
		->addRenderComb(*upperRenderComb, 0)
		->addRenderComb(*lowerRenderComb, 0)
		->addRenderComb(*restRenderComb, 0);
}
