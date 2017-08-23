#include "Application.h"
#include <iostream>
#define PI 3.1516

void Application::draw() {

	int x0 = 256, y0 = 256;
	int x = 0, y = 0;
	for (int angulo = 0; angulo < 360; ++angulo) {
		x = 100 * cos((float)angulo * PI / 180.0);
		y = 100 * sin((float)angulo * PI / 180.0);
		setColor(255, 0, 0, 255);
		linea(x0, y0, x + 256, y + 256);
	}
}