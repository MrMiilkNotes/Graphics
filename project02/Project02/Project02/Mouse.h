#pragma once
#include<utility>
#include<vector>
#include<map>
#include<string>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include"BasicSettings.h"
#include"Recorder.h"
#include"Drawer.h"

class Mouse
{
public:
	typedef std::pair<float, float> point_t;
	typedef std::vector<point_t> shape;
	typedef typename std::map<std::string, std::vector<shape>> record_t;
public:
	static void resetPoints();
	static void clear();
	static void debugClear();
	static void recover();
	static void mouse_rectangle();
	static void mouse_circle();
	static void mouse_line();
	static void mouse_moreTriangle();
private:
	Mouse();

	static void redraw();
	static void rectangle(int button, int state, int x, int y);
	static void rectangle_move(int x, int y);
	static void circle(int button, int state, int x, int y);
	static void circle_move(int x, int y);
	static void line(int button, int state, int x, int y);
	static void line_move(int x, int y);
	static void moreTriangle(int button, int state, int x, int y);
	static void moreTriangle_move(int x, int y);

public:
	/*static Recorder recoder;
	static Drawer drawer;*/
};