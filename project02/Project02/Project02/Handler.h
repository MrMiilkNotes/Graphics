#pragma once

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include"Mouse.h"


class Handler
{
private:
	Handler();
public:
	static Handler& getHandler();
	static void Clear();
	static void mouse_rectangle();
	static void mouse_circle();
	static void mouse_line();
};