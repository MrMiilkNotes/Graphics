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
#include"Drawer.h"

class Recorder
{
public:
	typedef std::pair<float, float> point_t;
	typedef std::vector<point_t> shape;
	typedef typename std::map<std::string, std::vector<shape>> record_t;
	typedef typename std::vector<float> p_t;
public:
	Recorder();

	static void record(std::string shape, int idx, float x, float y);
	static void record(std::string shape, p_t x_p, p_t y_p);
	static record_t get_records();
	static void clear();
public:
	static record_t records;
};

