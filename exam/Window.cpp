#include "Window.h"
#include <qmessagebox.h>


//Window::Window(QWidget *parent)
//	: QWidget(parent)
//{
//	gui = new GUI();
//	gui->setupUi(this);
//}

Window::Window(Chat& ctr, QWidget *parent)
	: QWidget(parent) {
	this->ctr = ctr;
	clearRow = 0;
	windows = new std::vector < Window* > ;
	gui = new GUI();
	gui->setupUi(this);
	connectSignalsToSlots();
	//loadModelTabel();
}

Window::Window(QWidget* parent) {

}

Window::~Window()
{
}

void Window::connectSignalsToSlots() {
	QObject::connect(gui->sendButton, SIGNAL(clicked()), this, SLOT(slot()));
	QObject::connect(gui->clearButton, SIGNAL(clicked()), this, SLOT(clear()));

}

void Window::slot() {
	QString qmessage = gui->textLine->text();
	std::string text = qmessage.toStdString();
	std::string userName = this->windowTitle().toStdString();
	Message m;
	m.setText(text);
	m.setUserID(ctr.getRepo()->findByName(userName).getID());
	try {
		ctr.addMessage(m);
		//loadModelTabel();
		loadAll();
	}
	catch (MyException& e) {
		QMessageBox::information(this, "Atentie", QString::fromStdString(e.what()));
	}
}

void Window::loadAll() {
	std::vector<User> users = ctr.getRepo()->getUsers();
	int size = users.size();
	std::for_each(windows->begin(), windows->end(), [&](Window* w){
		w->loadModelTabel();
	});
}

void Window::loadModelTabel() {
	std::vector<Message> elements = ctr.getRepo()->getMessages();
	QStandardItemModel* model = new QStandardItemModel(elements.size()-clearRow, 2);
	User u;// = ctr.getRepo()->findByID(elements.back().getUserID()); // ???

	int k = 0;
	//std::for_each(clearRow, int(elements.size()), [&](int index) {
	for (int index = clearRow; index < elements.size(); index ++) {
		int id = elements[index].getUserID();
		std::string text = elements[index].getText();
		u = ctr.getRepo()->findByID(elements[index].getUserID());
		std::string name = u.getName();

		//QString qid = QString::number(id);
		QString qtext = QString::fromStdString(text);
		QString qname = QString::fromStdString(name);

		//QStandardItem* idItem = new QStandardItem(qid);
		QStandardItem* textItem = new QStandardItem(qtext);
		QStandardItem* nameItem = new QStandardItem(qname);


		model->setItem(k, 0, nameItem);
		model->setItem(k, 1, textItem);
		k++;
	}
	gui->chatTable->setModel(model);
	gui->chatTable->model()->setHeaderData(1, Qt::Horizontal, "Message");
	gui->chatTable->model()->setHeaderData(0, Qt::Horizontal, "Name");
}

void Window::clear() {
	std::vector<Message> elements = ctr.getRepo()->getMessages();
	clearRow = elements.size();
	QStandardItemModel* model = new QStandardItemModel(0, 2);
	gui->chatTable->setModel(model);
	gui->chatTable->model()->setHeaderData(1, Qt::Horizontal, "Message");
	gui->chatTable->model()->setHeaderData(0, Qt::Horizontal, "Name");
}