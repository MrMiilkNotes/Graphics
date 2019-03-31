/* Rotating cube with viewer movement from Chapter 5 */
/* Cube definition and display similar to rotating--cube program */

/* We use the Lookat function in the display callback to point
the viewer, whose position can be altered by the x,X,y,Y,z, and Z keys.
The perspective view is set in the reshape callback */

#include <stdlib.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<iostream>
#include"continer.h"

positions_t vertices;
surfaces_t surfaces;
//ģ�����ĵ���������
point_posi_t model_posi; //{ 0.0, 0.0, 0.0 }
//��������
scalef_t scalf = {1.0, 1.0, 1.0};
//��ת�Ƕ�
static GLfloat theta[] = { 0.0,0.0,0.0 };
static GLint axis = 2;
static GLdouble viewer[] = { 0.0, 0.0, 5.0 }; /* initial viewer location */

//������ȡ�ĺ���
void load_off(const char* filename);
//��ɫ��Ϊ�˲�ȫ������һ����ɫ
int n_color = 7;
GLfloat colors[7][3] = { {1.0,0.0,0.0},
{1.0,1.0,0.0}, {0.0,1.0,0.0}, {0.0,0.0,1.0},
{1.0,0.0,1.0}, {1.0,1.0,1.0}, {0.0,1.0,1.0} };
GLfloat color[] = { 1.0, 1.0, 1.0 };

//���ڻ���һ���棬ͼ�δ洢��surface�� -- ��������container.h��
void ployshape(const surface_t& surface)
{
	int i = 0;
	glBegin(GL_POLYGON);
	for (auto point : surface) {
		GLfloat p[] = { vertices[point][0], vertices[point][1], vertices[point][2] };
		glColor3fv(colors[++i % n_color]);
		glVertex3fv(p);
	}
	glEnd();
}

//����һ������ͼ��
void colorSurface()
{
	for (auto surface : surfaces) {
		ployshape(surface);
	}
}

void display(void)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/* Update viewer position in modelview matrix */

	glLoadIdentity();
	gluLookAt(viewer[0], viewer[1], viewer[2], 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	/* �����ţ�����ת�����ƶ� */

	glTranslated(model_posi[0], model_posi[1], model_posi[2]);
	glRotatef(theta[0], 1.0, 0.0, 0.0);
	glRotatef(theta[1], 0.0, 1.0, 0.0);
	glRotatef(theta[2], 0.0, 0.0, 1.0);
	glScaled(scalf[0], scalf[1], scalf[2]);

	colorSurface();

	glFlush();
	glutSwapBuffers();
}

void mouse(int btn, int state, int x, int y)
{
	/*if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) axis = 0;
	if (btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) axis = 1;
	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) axis = 2;
	theta[axis] += 2.0;
	if (theta[axis] > 360.0) theta[axis] -= 360.0;
	display();*/
}

// ����1 ������ͨ�������� x,y,z,s
void processKeys(unsigned char key, int x, int y)
{
	// ����
	double sca_sens = 0.01;
	if (key == 's'){
		scalf[0] *= 1 - sca_sens;
		scalf[1] *= 1 - sca_sens;
		scalf[2] *= 1 - sca_sens;
	}
	if (key == 'S') {
		scalf[0] *= 1 + sca_sens;
		scalf[1] *= 1 + sca_sens;
		scalf[2] *= 1 + sca_sens;
	}

	// ��ת
	if (key == 'x') {
		theta[0] += 2.0;
		if (theta[0] > 360.0) theta[0] -= 360.0;
	}
	if (key == 'X') {
		theta[0] -= 2.0;
		if (theta[0] < 0) theta[0] += 360.0;
	}
	if (key == 'y') {
		theta[1] += 2.0;
		if (theta[1] > 360.0) theta[1] -= 360.0;
	}
	if (key == 'Y') {
		theta[1] -= 2.0;
		if (theta[1] < 0) theta[1] += 360.0;
	}
	if (key == 'z') {
		theta[2] += 2.0;
		if (theta[2] > 360.0) theta[2] -= 360.0;
	}
	if (key == 'Z') {
		theta[2] -= 2.0;
		if (theta[2] < 0) theta[2] += 360.0;
	}

	glutPostRedisplay();
}

// ����2 ����special key �ƶ��ļ�ͷ
void processKeys(int key, int x, int y)
{
	//�ӽ�
	double dx = 0.05;
	double dy = 0.05;
	if (key == GLUT_KEY_LEFT) {
		model_posi[0] -= dx;
	}
	if (key == GLUT_KEY_RIGHT) {
		model_posi[0] += dx;
	}
	if (key == GLUT_KEY_DOWN) {
		model_posi[1] -= dy;
	}
	if (key == GLUT_KEY_UP) {
		model_posi[1] += dy;
	}
	glutPostRedisplay();
}

void myReshape(int w, int h)
{
	glViewport(0, 0, w, h);

	/* Use a perspective view */

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h) glFrustum(-2.0, 2.0, -2.0 * (GLfloat)h / (GLfloat)w,
		2.0* (GLfloat)h / (GLfloat)w, 2.0, 20.0);
	else glFrustum(-2.0, 2.0, -2.0 * (GLfloat)w / (GLfloat)h,
		2.0* (GLfloat)w / (GLfloat)h, 2.0, 20.0);

	/* Or we can use gluPerspective */

	 //gluPerspective(45.0, w/h, -10.0, 50.0); 

	glMatrixMode(GL_MODELVIEW);
}

void
main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Hello window!");
	// load model
	load_off("horse.off");
	// regist functions
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutKeyboardFunc(processKeys);
	glutSpecialFunc(processKeys);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}
