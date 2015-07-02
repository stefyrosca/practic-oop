#pragma once
#include <string>
#include <iostream>

class Message
{
public:
	Message();
	~Message();
	int getUserID() { return userID; }
	std::string getText() { return text; }
	void setUserID(int id) { this->userID = id; }
	void setText(std::string text) { this->text = text; }
private:
	int userID;
	std::string text;
};


std::ostream& operator << (std::ostream& out, Message& e);