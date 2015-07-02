#include "Chat.h"
#include <sstream>

Chat::Chat()
{
}


Chat::~Chat()
{
}

void Chat::addMessage(Message m) {
	//Message m = fromStringToMessage(expression);
	if (m.getText() == "")
		throw MyException("Textul nu poate fi vid.");
	repo->addMessage(m);
}

Message Chat::fromStringToMessage(std::string exp) {
	std::stringstream stream(exp);
	int id;
	std::string item;
	std::getline(stream, item, ' ');
	id = std::stoi(item);
	std::getline(stream, item, '\n');
	Message m;
	m.setText(item);
	m.setUserID(id);
	return m;
}
