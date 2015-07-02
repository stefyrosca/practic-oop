#include "ChatRepository.h"
#include <fstream>
#include <algorithm>


ChatRepository::ChatRepository()
{
}


ChatRepository::~ChatRepository()
{
}
void ChatRepository::_writeAllInFile() {
	std::fstream out(messageFile, std::ios::out | std::ios::trunc);
	for (int i = 0; i < messages.size(); i++) {
		out << messages[i];
	}
	out.close();
}

void ChatRepository::_loadFromFile() {
	users.clear();
	std::ifstream in(userFile);
	while (!in.eof()) {
		User e;
		in >> e;
		users.push_back(e);
	}
	in.close();
}

void ChatRepository::_addToFile(Message e) {
	std::ofstream out(messageFile, std::ios::app);
	out << e;
	out.close();
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