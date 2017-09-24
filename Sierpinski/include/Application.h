#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include <iostream>
#include "Object3D.h"
#include "Plane.h"
#include <vector>
#include <stack>
#include "GLFW\glfw3.h"

class Vec3 {
public: 
	float v[3];
	
};

class Application {
public:

	static const int WIDTH = 512;
	static const int HEIGHT = 512;
	static const int RGB = 3;
	static const int RGBA = 4;

	Application();
	~Application();

	void init();
	void display();
	void reshape(int w, int h);
	void keyboard(int key, int scancode, int action, int mods);
	void update();
	void swapbuffers();
	void cursor_position(double xpos, double ypos);
	void putPixel(GLubyte *buffer, int x, int y, unsigned char R, unsigned char G, unsigned char B, unsigned char A);
	void putPixel(int x, int y, unsigned char R, unsigned char G, unsigned char B, unsigned char A);
	void draw();
	void linea(int x0, int y0, int x1, int y1);
	void setColor(int r, int g, int b, int a);
	void MidPoint(int xc, int yc, int r);
	void PutPixel(int x, int y);
	void moveTo(int x, int y);
	void lineTo(int x, int y);
	void clearScreen();
	std::vector<Vec3> poligonitos(int lados, int r);
	void setUp();
	std::vector<std::vector<Vec3>> sierpinsky(int rad, int subdi);
	void sierpinskyHelper(std::vector<std::vector<Vec3>>& vertex);
	Vec3 middlePoint(Vec3 a, Vec3 b);
	//void puntoMedio(int x1, int x2, int y1, int y2); explotó, ex, explotó :(
	std::stack<glm::mat4> mStack;
	glm::mat4 mProjectionMatrix, mTransform;
	glm::vec3 vEye;
	GLFWwindow* window;
	unsigned char Buffers[2][WIDTH*HEIGHT*RGBA];

private:	
	GLuint texturesID[2], pboID[2];
	GLuint shaderID;
	GLuint VAO, VBO;
	GLuint sampler;
	GLuint uTransform;
	GLubyte* _screenBuffer;
	int _currentBuffer, 
		_nextBuffer;

	std::vector<std::vector<Vec3>> vertex;
	glm::vec3 myLightPosition;
	GLuint uMyLightPosition[2];	

	Plane oPlane;
	float fTime;
	void initTextures();
	void processPBO();
	void initPBOs();
	void updatePixels(GLubyte *buffer);
	int _drawMode,
		shader;
	bool moveLight;

	void fakeBuffers();
	int R, G, B, A;
	int X1, Y1;
};

#endif //__APPLICATION_H__