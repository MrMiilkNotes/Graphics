#pragma once
#include<iostream>
#include<math.h>
#include<string>
#include<array>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include"BasicSettings.h"
#include"Recorder.h"

class Drawer
{
public:
	typedef std::array<float, 3> color_t;
public:
	Drawer();
	~Drawer();

	static void resetPoints();
	static void clear();

	static void two_point_shape(const std::string& shape, int button, int state, int x, int y);
	static void two_point_shape_d(const std::string& shape, int x, int y);	//dynamic
	static bool is_two_point_shape(const std::string& shape_);
	static void three_point_shape(const std::string& shape, int button, int state, int x, int y);
	static void three_point_shape_d(const std::string& shape, int x, int y);

	static void draw_shape(const std::string& shape);
	static void draw_shape(const std::string& shape, float x1_, float x2_, float y1_, float y2_);
private:
	static void draw_circle();
	static void draw_line();
	static void draw_triangle();
public:
	static float x1, x2, x3;
	static float y1, y2, y3;

	static int two_point_count;
	static int three_point_count;
	static color_t draw_color;
	static color_t drawing_color;
};

