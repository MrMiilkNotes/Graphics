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
	static void mouse_rectangle();
};