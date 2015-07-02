#include <QtWidgets/QApplication>
#include <QtGui\qguiapplication.h>
#include "Window.h"
#include "Chat.h"
#include "ChatRepository.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ChatRepository* repo = new ChatRepository("users.txt", "messages.txt");
	Chat ctr(repo);
	Window* main = new Window;
	std::vector<User> users = ctr.getRepo()->getUsers();
	std::vector<Window*>* guis = new std::vector<Window*>;
	std::for_each(users.begin(), users.end(), [&](User u){
		Window* w = new Window(ctr);
		guis->push_back(w);
		w->connectWindows(guis);
		//ctr.guis.push_back(w);
		w->setMinimumSize(200, 200);
		w->setWindowTitle(QString::fromStdString(u.getName()));
		w->show();
	});
	//Paint drawer;
	//drawer.show();
	return a.exec();
}
