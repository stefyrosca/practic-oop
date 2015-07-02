#pragma once
#include <qwidget.h>
#include <qobject.h>
#include <QtWidgets/QWidget>
#include <qpainter.h>
#include <qpaintevent>
#include "Chat.h"
#include "GUI.h"

class Window : public QWidget
{
	Q_OBJECT

public:
	//Window(QWidget *parent = 0);
	Window(Chat& ctr, QWidget *parent = 0);
	Window(QWidget* parent = 0);
	~Window();

	void loadModelTabel();
	void connectSignalsToSlots();
	void loadAll();
	void connectWindows(std::vector<Window*>* w) { windows = w; } //loadAll();


	Chat ctr;
	GUI* gui;
	int clearRow;

	std::vector<Window*>* windows;

private slots:
void slot();
void clear();
};

class Paint : public QWidget {
	Q_OBJECT

		QPainter p;
		int i;
public:
	Paint(QWidget* obj = 0) : QWidget(obj), i(0) {}
	virtual void paintEvent(QPaintEvent*) {
		
		p.setPen(QPen(Qt::black, 3));
		QPainter p(this);
		int n = 8;
		while (i<n) {
			qreal fAngle = 2 * 3.14 * i / n;
			qreal x = 50 + cos(fAngle) * 40;
			qreal y = 50 + sin(fAngle) * 40;
			p.drawPoint(QPointF(x, y));
			i++;
		}
	}
}; 