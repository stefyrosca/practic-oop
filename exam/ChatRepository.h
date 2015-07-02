#pragma once
#include <string>
#include <vector>
#include "User.h"
#include "Message.h"

class ChatRepository
{
public:
	ChatRepository();
	ChatRepository(std::string users, std::string messages) : userFile(users), messageFile(messages) {
		_loadFromFile();
	}
	~ChatRepository();
	User ChatRepository::findByID(int id);
	User ChatRepository::findByName(std::string name);
	std::vector<User> getUsers(){ return users; }
	std::vector<Message> getMessages(){ return messages; }
	void addMessage(Message m) { 
		messages.push_back(m);
		_addToFile(m);
	}

private:
	std::string userFile, messageFile;
	void _loadFromFile();
	void _writeAllInFile();
	std::vector<User> users;
	std::vector<Message> messages;
	void _addToFile(Message e);
};

