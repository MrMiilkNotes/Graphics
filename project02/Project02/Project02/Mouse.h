#pragma once
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include"BasicSettings.h"

class Mouse
{
public:
	Mouse();

	static void resetPoints();
	static void rectangle(int button, int state, int x, int y);
	static void rectangle_move(int x, int y);
public:
	static float x1, x2, x3;
	static float y1, y2, y3;

	static int rectangle_point_count;
};