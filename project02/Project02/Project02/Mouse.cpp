#include "Mouse.h"

float Mouse::x1 = 0.0f; 
float Mouse::x2 = 0.0f;
float Mouse::x3 = 0.0f;
float Mouse::y1 = 0.0f;
float Mouse::y2 = 0.0f;
float Mouse::y3 = 0.0f;
int Mouse::rectangle_point_count = 0;

Mouse::Mouse()
{
}

void Mouse::resetPoints()
{
	x1 = x2 = x3 = 0.0f;
	y1 = y2 = y3 = 0.0f;

	rectangle_point_count = 0;
}

void Mouse::rectangle(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		x1 = x;					// record position
		y1 = windowHeight - y;
		glColor3f(0.0f, 0.0f, 1.0f);
		glLogicOp(GL_XOR);
		rectangle_point_count = 1;
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		switch (rectangle_point_count)
		{
		case 2:
			glRectf(x1, y1, x2, y2);
			glFlush();
		case 1:
			x2 = x;
			y2 = windowHeight - y;
			glColor3f(0.0f, 1.0f, 0.0f);
			glLogicOp(GL_COPY);
			glRectf(x1, y1, x2, y2);
			glFlush();
			break;
		}
	}
}

void Mouse::rectangle_move(int x, int y)
{
	switch (rectangle_point_count)
	{
	case 2:
		glRectf(x1, y1, x2, y2);
		glFlush();
	case 1:
		x2 = x;
		y2 = windowHeight - y;
		glRectf(x1, y1, x2, y2);
		glFlush();
		rectangle_point_count = 2;
		break;
	}
}