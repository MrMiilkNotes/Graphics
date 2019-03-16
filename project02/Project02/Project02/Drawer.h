#pragma once
#include<iostream>
#include<math.h>
#include<string>
#include<vector>
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
	typedef std::vector<float> points_t;
public:
	Drawer();
	~Drawer();

	static void resetPoints();
	static void clear();

	static void two_point_shape(const std::string& shape, int button, int state, int x, int y);
	static void two_point_shape_d(const std::string& shape, int x, int y);	//dynamic
	static void more_point_shape(const std::string& shape, int button, int state, int x, int y);
	static void more_point_shape_d(const std::string& shape, int x, int y);
	static bool is_two_point_shape(const std::string& shape_);
	static bool is_more_point_shape(const std::string& shape_);
	static void ploygon_end(unsigned char, int, int);

	static void draw_shape(const std::string& shape);
	static void draw_shape(const std::string& shape, const points_t& x_, const points_t& y_);
	static void draw_shape(const std::string& shape, float x1_, float x2_, float y1_, float y2_);
private:
	static void draw_circle();
	static void draw_line();
	static void draw_triangle();
public:
	static float x1, x2, x3;
	static float y1, y2, y3;
	static points_t x_p;
	static points_t y_p;

	static int two_point_count;
	static int more_point_count;
	static color_t draw_color;
	static color_t drawing_color;
};

