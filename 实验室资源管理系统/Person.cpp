
#include "Person.h"

User::User(const string & _name) {
	name = _name;
	ID = k++;
}
User::User(int id, const string& _name) {
	ID = id;
	name = _name;
}

int User::k = 1;

string User::getName() {
	return name;
}

int User::getID() {
	return ID;
}