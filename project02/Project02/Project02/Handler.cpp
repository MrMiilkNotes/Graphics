#include "Handler.h"



Handler::Handler()
{
}


Handler & Handler::getHandler()
{
	//Singleton
	static Handler* handler = new Handler;
	return *handler;
}

void Handler::Clear()
{
	Mouse::clear();
}

void Handler::mouse_rectangle()
{
	Mouse::resetPoints();
	glutMouseFunc(Mouse::rectangle);
	glutMotionFunc(Mouse::rectangle_move);
}

void Handler::mouse_circle()
{
	Mouse::resetPoints();
	glutMouseFunc(Mouse::circle);
	glutMotionFunc(Mouse::circle_move);
}

void Handler::mouse_line()
{
	Mouse::resetPoints();
	glutMouseFunc(Mouse::line);
	glutMotionFunc(Mouse::line_move);
}