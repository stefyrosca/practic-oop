#include "ChatRepository.h"
#include <fstream>
#include <algorithm>
#include <thread>

ChatRepository::ChatRepository()
{
}


ChatRepository::~ChatRepository()
{
}
void ChatRepository::_writeAllInFile() {
	write_mtx.lock();
	std::fstream out(messageFile, std::ios::out | std::ios::trunc);
	for (int i = 0; i < messages.size(); i++) {
		out << messages[i];
	}
	out.close();
	write_mtx.unlock();
}

void ChatRepository::_loadFromFile() {
	load_mtx.lock();
	users.clear();
	std::ifstream in(userFile);
	while (!in.eof()) {
		User e;
		in >> e;
		users.push_back(e);
	}
	in.close();
	load_mtx.unlock();
}

void ChatRepository::_addToFile(Message e) {
	write_mtx.lock();
	std::ofstream out(messageFile, std::ios::app);
	out << e;
	out.close();
	write_mtx.unlock();
}

User ChatRepository::findByID(int id) {
	User u(0,"");
	std::for_each(users.begin(), users.end(), [&](User& e) {if (e.getID() == id)  { u.setID(e.getID()); u.setName((e.getName())); }});
	return u;
}

User ChatRepository::findByName(std::string name) {
	User u(0, "");
	std::for_each(users.begin(), users.end(), [&](User& e) {if (e.getName() == name)  { u.setID(e.getID()); u.setName((e.getName())); } });
	return u;
}