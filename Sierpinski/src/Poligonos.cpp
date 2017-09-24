#include "Application.h"
#include <iostream>
#include <vector>
#define PI  3.1516

std::vector<Vec3> SuperVectour;

void Application::update()
{

}

void Application::draw()
{
	int size = SuperVectour.size();
	setColor(255, 255, 0, 255);
	
	
	for (int i = 0; i < SuperVectour.size(); ++i) {
		moveTo(SuperVectour.at(i).v[0], SuperVectour.at(i).v[1]);
		lineTo(SuperVectour.at((i + 1)%SuperVectour.size()).v[0], SuperVectour.at((i + 1) % SuperVectour.size()).v[1]);
	}
	//lineTo(255,255);
}

void Application::poligonitos(int lados, int r) 
{

	Vec3 vec;
	int angulo = 0, incremento = 360 / lados;
	moveTo(256, 256);
	vec.v[0] = X1;
	vec.v[1] = Y1;
	for (int i = lados ; i--;) {
		vec.v[0] += r * cos((angulo *PI) / 180);
		vec.v[1] += r * sin((angulo * PI) / 180);
		vec.v[2] = 1;
		
		angulo += incremento;
		SuperVectour.push_back(vec);
	}
}

void Application::setUp()
{
	poligonitos(3, 100);
}
