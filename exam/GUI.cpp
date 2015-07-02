#include "GUI.h"
#include <qvboxlayout>

GUI::GUI()
{
}


GUI::~GUI()
{
}

void GUI::setupUi(QWidget* parent) {
	QHBoxLayout* mainLayout = new QHBoxLayout();
	QVBoxLayout* chatLayout = new QVBoxLayout();
	parent->setLayout(chatLayout);
	chatLayout->addLayout(mainLayout);
	textLine = new QLineEdit();
	sendButton = new QPushButton("send");
	chatTable = new QTableView();
	clearButton = new QPushButton("clear");
	mainLayout->addWidget(textLine);
	mainLayout->addWidget(sendButton);
	chatLayout->addWidget(chatTable);
	chatLayout->addWidget(clearButton);
}