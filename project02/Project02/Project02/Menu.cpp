#include "Menu.h"



void Menu::main_menu(int id)
{
	Mouse::resetPoints();
	switch (id)
	{
	case DrawMode:
		break;
	case Shapes:
		break;
	case Colors:
		break;
	case Clear:
		Mouse::clear();
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

void Menu::mode_menu(int id)
{
	Mouse::resetPoints();
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
	Mouse::resetPoints();
	switch (id)
	{
	case Red:
		Drawer::draw_color[0] = 1.0f;
		Drawer::draw_color[1] = 0.0f;
		Drawer::draw_color[2] = 0.0f;
 		break;
	case Blue:
		Drawer::draw_color[0] = 0.0f;
		Drawer::draw_color[1] = 0.0f;
		Drawer::draw_color[2] = 0.0f;
		break;
	case Green:
		Drawer::draw_color[0] = 0.0f;
		Drawer::draw_color[1] = 0.0f;
		Drawer::draw_color[2] = 1.0f;
		break;
	default:
		break;
	}
	//Mouse::debugClear();
	glutPostRedisplay();
}

void Menu::shapes_menu(int id)
{
	Mouse::resetPoints();
	switch (id)
	{
	case Line_:
		Mouse::mouse_line();
		break;
	case Rectangle_:
		Mouse::mouse_rectangle();
		break;
	case Circle_:
		Mouse::mouse_circle();
		break;
	case Polygon_:
		Mouse::mouse_moreTriangle();
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
	glutAddMenuEntry("Polygon", 3);
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
	this->set();
}
