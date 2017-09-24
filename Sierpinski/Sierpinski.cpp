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
	for (int i = vertex.size(); i--;)
	{
		for (int j = vertex.at(i).size(); j--;)
		{
			moveTo(vertex.at(i).at(j).v[0], vertex.at(i).at(j).v[1]);
			lineTo(vertex.at(i).at((j + 1) % vertex.at(i).size()).v[0],
				vertex.at(i).at((j + 1) % vertex.at(i).size()).v[1]);
		}
	}
}

void Application::setUp()
{
	Vec3 vectorcin;
	vectorcin.v[0] = X1;
	vectorcin.v[1] = Y1;
	vectorcin.v[2] = 1;
	moveTo(255, 255);
	setColor(255, 0, 0, 255);
	vertex = sierpinsky(100, 4);
}


std::vector<std::vector<Vec3>> Application::sierpinsky(int rad, int subdi) {
	std::vector<std::vector<Vec3>> vec;
	vec.push_back(poligonitos(3, rad));
	for (subdi; subdi--;)
		sierpinskyHelper(vec);
	return vec;
}

void Application::sierpinskyHelper(std::vector <std::vector<Vec3>>& vertex)
{
	std::vector<std::vector<Vec3>> vec = vertex;
	for (int i = vertex.size(); i--;)
	{
		std::vector<Vec3> mahgod;
		for (int j = vertex.at(i).size(); j--;)
		{
			mahgod.push_back(middlePoint(vec.at(i).at(j), vec.at(i).at((j + 1) % vertex.at(i).size())));
		}
		//descomentar para considerar a los centros como caras alv papu
		//vec.push_back(mahgod);
		vec.push_back(std::vector<Vec3>());
		vec.at(vec.size() - 1).push_back(mahgod.at(0));
		vec.at(vec.size() - 1).push_back(vertex.at(i).at(0));
		vec.at(vec.size() - 1).push_back(mahgod.at(2));
		vec.push_back(std::vector<Vec3>());
		vec.at(vec.size() - 1).push_back(mahgod.at(1));
		vec.at(vec.size() - 1).push_back(vertex.at(i).at(1));
		vec.at(vec.size() - 1).push_back(mahgod.at(2));
		vec.push_back(std::vector<Vec3>());
		vec.at(vec.size() - 1).push_back(mahgod.at(1));
		vec.at(vec.size() - 1).push_back(vertex.at(i).at(2));
		vec.at(vec.size() - 1).push_back(mahgod.at(0));
	}
	vertex = vec;
}

Vec3 Application::middlePoint(Vec3 a, Vec3 b)
{
	Vec3 c;
	c.v[0] = (a.v[0] + b.v[0]) / 2;
	c.v[1] = (a.v[1] + b.v[1]) / 2;
	c.v[2] = (a.v[2] + b.v[2]) / 2;
	return c;
}