#include "Handler.h"



Handler::Handler()
{
}


Handler & Handler::getHandler()
{
	//Singleton
	static Handler handler;
	return handler;
}

void Handler::mouse_rectangle()
{
	Mouse::resetPoints();
	glutMouseFunc(Mouse::rectangle);
	glutMotionFunc(Mouse::rectangle_move);
}
