#include "Application.h"
#include <iostream>
#include <vector>
#define PI  3.1516
std::vector<Vec3> SuperVectour;

Matrix3 translacion, rotacion, fuleichdi;
float angulo = 0;
void Application::update()
{
	fuleichdi = multiplicacionTres(Matrix3::Rotation(angulo), Matrix3::Translation(250, 250));
	for (int i = vertex.size(); i--;)
	{
		for (int j = vertex.at(i).size(); j--;)
		{
			vertex.at(i).at(j) = multiplicaciónM3Vector(Matrix3::Rotation(angulo),vertex.at(i).at(j));
		}
	}
	
	angulo += .1f;
}

void Application::draw()
{
	clearScreen();
	for (int i = vertex.size(); i--;)
	{
		for (int j = vertex.at(i).size(); j--;)
		{
			moveTo(vertex.at(i).at(j).v[0]+ 250, vertex.at(i).at(j).v[1] +250);
			lineTo(vertex.at(i).at((j + 1) % vertex.at(i).size()).v[0] + 250,
				vertex.at(i).at((j + 1) % vertex.at(i).size()).v[1] +250);
		}
	}
}

void Application::setUp()
{
	
	float tx = 0, ty = 0;
	Vec3 vectorcin;
	vectorcin.v[0] = X1;
	vectorcin.v[1] = Y1;
	vectorcin.v[2] = 1;
	moveTo(0, 0);
	setColor(255, 0, 0, 255);
	vertex = sierpinsky(100, 5);

	


	
}

Matrix3 Application::multiplicacionTres(Matrix3 right, Matrix3 left) {
	Matrix3 nuevaMatriz;
	//left horizontal  
   //right vertical
	// 0 = 1  //1 = 2 //2 = 3
   //Posicion 1,1
	nuevaMatriz.matx[0].v[0] = (left.matx[0].v[0] * right.matx[0].v[0]) + (left.matx[0].v[1] * right.matx[1].v[0]) + (left.matx[0].v[2] * right.matx[2].v[0]);
	//Posicion 2 ,1
	nuevaMatriz.matx[1].v[0] = (left.matx[1].v[0] * right.matx[0].v[0]) + (left.matx[1].v[1] * right.matx[1].v[0]) + (left.matx[1].v[2] * right.matx[2].v[0]);
	//Posición 3,1
	nuevaMatriz.matx[2].v[0] = (left.matx[2].v[0] * right.matx[0].v[0]) + (left.matx[2].v[1] * right.matx[1].v[0]) + (left.matx[2].v[2] * right.matx[2].v[0]);
	//Posición 1,2
	nuevaMatriz.matx[0].v[1] = (left.matx[0].v[0] * right.matx[0].v[1]) + (left.matx[0].v[1] * right.matx[1].v[1]) + (left.matx[0].v[2] * right.matx[2].v[1]);
	//Posición 2,2
	nuevaMatriz.matx[1].v[1] = (left.matx[1].v[0] * right.matx[1].v[1]) + (left.matx[1].v[1] * right.matx[1].v[1]) + (left.matx[1].v[2] * right.matx[2].v[1]);
	//Posición 3,3
	nuevaMatriz.matx[2].v[1] = (left.matx[2].v[0] * right.matx[0].v[1]) + (left.matx[2].v[1] * right.matx[1].v[1]) + (left.matx[2].v[2] * right.matx[2].v[1]);
	//Posición 3,1
	nuevaMatriz.matx[0].v[2] = (left.matx[0].v[0] * right.matx[0].v[2]) + (left.matx[0].v[1] * right.matx[1].v[2]) + (left.matx[0].v[2] * right.matx[2].v[2]);
	//Posición 3,2
	nuevaMatriz.matx[1].v[2] = (left.matx[1].v[0] * right.matx[0].v[2]) + (left.matx[1].v[1] * right.matx[1].v[2]) + (left.matx[1].v[2] * right.matx[2].v[2]);
	//Posición 3,3
	nuevaMatriz.matx[2].v[2] = (left.matx[2].v[0] * right.matx[0].v[2]) + (left.matx[2].v[1] * right.matx[1].v[2]) + (left.matx[2].v[2] * right.matx[2].v[2]);
	return nuevaMatriz;
}

Vec3 Application::multiplicaciónM3Vector(Matrix3 left, Vec3 right) {
	Vec3 nuevoVector;
	nuevoVector.v[0] = (left.matx[0].v[0] * right.v[0]) + (left.matx[0].v[1] * right.v[1]) + (left.matx[0].v[2] * right.v[2]);
	nuevoVector.v[1] = (left.matx[1].v[0] * right.v[0]) + (left.matx[1].v[1] * right.v[1]) + (left.matx[1].v[2] * right.v[2]);
	nuevoVector.v[2] = (left.matx[2].v[0] * right.v[0]) + (left.matx[2].v[1] * right.v[1]) + (left.matx[2].v[2] * right.v[2]);
	return nuevoVector;
}
