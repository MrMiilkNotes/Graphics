#include <stdlib.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include"BasicSettings.h"
#include"Menu.h"
#pragma region XXX
extern int windowHeight = 500;
extern int windowWidth = 500;
#pragma endregion

void init();
void reshape(GLsizei w, GLsizei h);
void display(){}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(windowWidth, windowHeight);

	glutCreateWindow("Draw board");

	init();
	glutReshapeFunc(reshape);

	#pragma region Menu Class
	Menu* menu = new Menu;
	#pragma endregion

	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}