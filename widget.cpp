#include "widget.hpp"

#include <QWidget>
#include <QGLWidget>
#include <QFont>
#include <QKeyEvent>

Widget::Widget(QWidget *parent) : QGLWidget(parent)
{
	qfont = new QFont("Verdana", 16);
}

QSize Widget::sizeHint() const
{
	return QSize(450, 450);
}

QSize Widget::minimumSizeHint() const
{
	return QSize(200, 200);
}

void Widget::initializeGL()
{
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void Widget::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -12.0);

	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f( 0.0f, 3.0f,0.0f);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f( 3.0f,-3.0f,0.0f);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-3.0f,-3.0f,0.0f);
	glEnd();

	renderText(5, 20, "Kurs Qt - OpenGL @ blog.matthew.org.pl", *qfont);
}

void Widget::resizeGL(int width, int height)
{
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Widget::keyPressEvent(QKeyEvent *event)
{
	if (event->key() == Qt::Key_S)
	{
		renderPixmap().save("render", "PNG", 100);
	}
}
