#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <QGLWidget>

class Widget : public QGLWidget
{
	Q_OBJECT

	QFont *qfont;

public:
	Widget(QWidget *parent = 0);

	QSize minimumSizeHint() const;
	QSize sizeHint() const;

protected:
	void initializeGL();
	void paintGL();
	void resizeGL(int width, int height);
	void keyPressEvent(QKeyEvent *);
};

#endif // WIDGET_HPP
