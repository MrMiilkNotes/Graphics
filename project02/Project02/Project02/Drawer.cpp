#include "Drawer.h"

float Drawer::x1 = 0.0f;
float Drawer::x2 = 0.0f;
float Drawer::x3 = 0.0f;
float Drawer::y1 = 0.0f;
float Drawer::y2 = 0.0f;
float Drawer::y3 = 0.0f;
int Drawer::two_point_count = 0;
int Drawer::three_point_count = 0;
Drawer::color_t Drawer::draw_color = { 0.0f, 1.0f, 0.0f };
Drawer::color_t Drawer::drawing_color = { 0.4f, 1.0f, 0.3f };

Drawer::Drawer()
{
}

Drawer::~Drawer()
{
}

void Drawer::resetPoints()
{
	x1 = x2 = x3 = 0.0f;
	y1 = y2 = y3 = 0.0f;

	two_point_count = 0;
	three_point_count = 0;
}

void Drawer::clear()
{
	glLogicOp(GL_COPY);
	glColor3f(1.0f, 1.0f, 1.0f);
	glRectf(0, 0, windowWidth, windowHeight);
	glColor3f(draw_color[0], draw_color[1], draw_color[2]);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void Drawer::two_point_shape(const std::string& shape, int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		x1 = x;					// record position
		y1 = windowHeight - y;

		Recorder::record(shape, 1, x1, y1);
		glColor3f(drawing_color[0], drawing_color[1], drawing_color[2]);
		glLogicOp(GL_XOR);
		two_point_count = 1;
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		switch (two_point_count)
		{
		case 2:
			draw_shape(shape);
			glFlush();
		case 1:
			x2 = x;
			y2 = windowHeight - y;
			glColor3f(draw_color[0], draw_color[1], draw_color[2]);
			glLogicOp(GL_COPY);
			draw_shape(shape);
			Recorder::record(shape, 2, x2, y2);
			glFlush();
			break;
		}
	}
}

void Drawer::two_point_shape_d(const std::string& shape, int x, int y)
{
	switch (two_point_count)
	{
	case 2:
		draw_shape(shape);
		glFlush();
	case 1:
		x2 = x;
		y2 = windowHeight - y;
		draw_shape(shape);
		glFlush();
		two_point_count = 2;
		break;
	}
}

bool Drawer::is_two_point_shape(const std::string& shape_)
{
	return shape_.compare("rectangle") == 0 || shape_.compare("circle") == 0 || shape_.compare("line") == 0;
}

void Drawer::three_point_shape(const std::string & shape, int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN ) {
		if (three_point_count == 0) {
			x1 = x;					// record position
			y1 = windowHeight - y;
			three_point_count = 1;
			Recorder::record(shape, 1, x1, y1);
			glColor3f(drawing_color[0], drawing_color[1], drawing_color[2]);
			glLogicOp(GL_XOR);
		}
		else if (three_point_count == 1) {
			x2 = x;					// record position
			y2 = windowHeight - y;
			three_point_count = 2;
			Recorder::record(shape, 1, x2, y2);
			draw_shape("line");
			glFlush();
		}
		else if (three_point_count == 2) {
			x3 = x;					// record position
			y3 = windowHeight - y;
			three_point_count = 0;
			Recorder::record(shape, 1, x3, y3);
			glColor3f(draw_color[0], draw_color[1], draw_color[2]);
			glLogicOp(GL_COPY);
			draw_shape("line");
			draw_shape(shape);
			glFlush();
		}
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		switch (three_point_count)
		{
		/*case 2:
			draw_shape(shape);
			glFlush();
		case 1:
			x2 = x;
			y2 = windowHeight - y;
			glColor3f(draw_color[0], draw_color[1], draw_color[2]);
			glLogicOp(GL_COPY);
			draw_shape(shape);
			Recorder::record(shape, 2, x2, y2);
			glFlush();
			break;*/
		}
	}
}

void Drawer::three_point_shape_d(const std::string & shape, int x, int y)
{
	/*switch (three_point_count)
	{
	case 3:
		draw_shape(shape);
		glFlush();
		x2 = x;
		y2 = windowHeight - y;
		draw_shape(shape);
		glFlush();
		three_point_count = 2;
		break;
	}*/
}

void Drawer::draw_shape(const std::string& shape)
{
	if (shape.compare("rectangle") == 0) {
		glRectf(x1, y1, x2, y2);
	}
	if (shape.compare("circle") == 0) {
		draw_circle();
	}
	if (shape.compare("line") == 0) {
		draw_line();
	}
	if (shape.compare("triangle") == 0) {
		draw_triangle();
	}
}

void Drawer::draw_shape(const std::string & shape, float x1_, float y1_, float x2_, float y2_)
{
	x1 = x1_;
	x2 = x2_;
	y1 = y1_;
	y2 = y2_;
	Drawer::draw_shape(shape);
}

void Drawer::draw_circle()
{
	float r = pow(pow(x1 - x2, 2) + pow(y1 - y2, 2), 1.0 / 2);
	int max_num = 100;
	float pi = 3.1415;
	glBegin(GL_POLYGON);//绘画模式，填充模式
	for (int i = 0; i < max_num; ++i) {
		glVertex2f(r * cos(2 * pi / max_num * i) + x1, r * sin(2 * pi / max_num * i) + y1);
	}
	glEnd();//完成一个序列的绘制
}

void Drawer::draw_line()
{
	glBegin(GL_LINES);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();
}

void Drawer::draw_triangle()
{
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glEnd();
}
