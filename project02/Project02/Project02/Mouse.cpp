#include "Mouse.h"


Mouse::Mouse()
{
}

void Mouse::redraw()
{
	typename Recorder::record_t tmp = Recorder::get_records();
	for (auto iter = tmp.begin(); iter != tmp.end(); ++iter) {
		if (Drawer::is_two_point_shape(iter->first)) {
			for (auto obj : (iter->second)) {
				if (obj.size() >= 2) {
					Drawer::draw_shape((iter->first), obj[0].first, obj[0].second, obj[1].first, obj[1].second);
				}
			}
		}
	}
	glFlush();
}

void Mouse::resetPoints()
{
	Drawer::resetPoints();
}

void Mouse::clear()
{
	//通过使用画入背景色来清除
	Drawer::clear();
	Recorder::clear();
}

void Mouse::debugClear()
{
	Drawer::clear();
	Mouse::redraw();
}

void Mouse::recover()
{
	Mouse::redraw();
}

void Mouse::mouse_rectangle()
{
	Mouse::resetPoints();
	glutMouseFunc(Mouse::rectangle);
	glutMotionFunc(Mouse::rectangle_move);
}

void Mouse::mouse_circle()
{
	Mouse::resetPoints();
	glutMouseFunc(Mouse::circle);
	glutMotionFunc(Mouse::circle_move);
}

void Mouse::mouse_line()
{
	Mouse::resetPoints();
	glutMouseFunc(Mouse::line);
	glutMotionFunc(Mouse::line_move);
}

void Mouse::mouse_triangle()
{
	Mouse::resetPoints();
	glutMouseFunc(Mouse::triangle);
	glutMotionFunc(Mouse::triangle_move);
}

void Mouse::rectangle(int button, int state, int x, int y)
{
	Drawer::two_point_shape("rectangle", button, state, x, y);
}

void Mouse::rectangle_move(int x, int y)
{
	Drawer::two_point_shape_d("rectangle", x, y);
}

void Mouse::circle(int button, int state, int x, int y)
{
	Drawer::two_point_shape("circle", button, state, x, y);
}

void Mouse::circle_move(int x, int y)
{
	Drawer::two_point_shape_d("circle", x, y);
}

void Mouse::line(int button, int state, int x, int y)
{
	Drawer::two_point_shape("line", button, state, x, y);
}

void Mouse::line_move(int x, int y)
{
	Drawer::two_point_shape_d("line", x, y);
}

void Mouse::triangle(int button, int state, int x, int y)
{
	Drawer::three_point_shape("triangle", button, state, x, y);
}

void Mouse::triangle_move(int x, int y)
{
	Drawer::three_point_shape_d("triangle", x, y);
}
