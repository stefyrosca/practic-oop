#include "Message.h"


Message::Message()
{
}


Message::~Message()
{
}


std::ostream& operator << (std::ostream& out, Message& e) {
	out << e.getUserID() << " " << e.getText() << std::endl;
	return out;
}
