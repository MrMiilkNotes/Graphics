#pragma once

#include <stdlib.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include"Mouse.h"

enum MainMenu_ {
	DrawMode,
	Shapes,
	Colors,
	Clear,
};

enum DrawMode_ {
	Pen,	// 笔画模式
	Shape,	// 由点确定shape的模式
	Rubber	//橡皮条
};

enum Shapes_ {
	Line_ = 0,
	Rectangle_,
	Circle_,
	Polygon_,
	Ellipse_,
};

enum Colors_ {
	Red = 0,
	Blue,
	Green,
};

class Menu
{
public:
	Menu();

	static void main_menu(int id);
	static void mode_menu(int id);
	static void colors_menu(int id);
	static void shapes_menu(int id);

private:
	void set();
	int main_idx;
	int second_idx;
};

