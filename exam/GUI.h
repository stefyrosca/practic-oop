#pragma once
#include <qobject.h>
#include <qhboxlayout>
#include <qvboxlayout>
#include <qwidget.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qtableview.h>
#include <QStandardItemModel>

class GUI
{
public:
	GUI();
	~GUI();
	void setupUi(QWidget* parent);
	
	QPushButton *sendButton;
	QLineEdit *textLine;
	QTableView *chatTable;
	QPushButton *clearButton;

};

