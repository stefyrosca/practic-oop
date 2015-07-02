#pragma once
#include <string>
#include <iostream>


class User
{
public:
	User();
	User(int id, std::string name) : id(id), name(name) {}
	int getID() { return id; }
	std::string getName() { return name; }
	void setID(int id) { this->id = id; }
	void setName(std::string name) { this->name = name; }
	~User();
private:
	int id;
	std::string name;
};

typedef User TElement;

std::istream& operator >> (std::istream& in, User& e);
