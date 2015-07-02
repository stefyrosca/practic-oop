#include "User.h"


User::User()
{
}


User::~User()
{
}

std::istream& operator >> (std::istream& in, User& e) {
	int id;
	std::string name;
	in >> id >> name;
	e.setID(id);
	e.setName(name);
	return in;
}