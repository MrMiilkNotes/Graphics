#include "Menu.h"



void Menu::main_menu(int id)
{
	switch (id)
	{
	case DrawMode:
		break;
	case Shapes:
		break;
	case Colors:
		break;
	case Clear:
		break;
	default:
		break;
	}
	glutPostRedisplay();
}


void Menu::mode_menu(int id)
{
	switch (id)
	{
	case Pen:
		break;
	case Shape:
		break;
	case Rubber:
		break;
	default:
		break;
	}
}

void Menu::colors_menu(int id)
{
	switch (id)
	{
	case Red:
		break;
	case Blue:
		break;
	case Green:
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

void Menu::shapes_menu(int id)
{
	switch (id)
	{
	case Line_:
		break;
	case Rectangle_:
		handler.mouse_rectangle();
		break;
	case Circle_:
		break;
	case Triangle_:
		break;
	case Ellipse_:
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

void Menu::set()
{
	int co_menu = glutCreateMenu(this->colors_menu);
	glutAddMenuEntry("Red", 0);
	glutAddMenuEntry("Blue", 1);
	glutAddMenuEntry("Green", 2);

	int sh_menu = glutCreateMenu(this->shapes_menu);
	glutAddMenuEntry("Line", 0);
	glutAddMenuEntry("Rectangle", 1);
	glutAddMenuEntry("Circle", 2);
	glutAddMenuEntry("Triangle", 3);
	glutAddMenuEntry("Ellipse", 4);

	int mo_menu = glutCreateMenu(this->mode_menu);
	glutAddMenuEntry("Pen", 0);
	glutAddMenuEntry("Shape", 1);
	glutAddMenuEntry("Rubber", 2);
	int ma_menu = glutCreateMenu(this->main_menu);
	glutAddSubMenu("DrawMode", mo_menu);
	glutAddSubMenu("Shapes", sh_menu);
	glutAddSubMenu("Colors", co_menu);
	glutAddMenuEntry("Clear", 3);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

Menu::Menu()
{
	handler = Handler::getHandler();
	this->set();
}
