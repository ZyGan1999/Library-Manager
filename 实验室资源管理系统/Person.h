#pragma once
#include<string>
using namespace std;


class User  {
public:
	User(const string&);
	User(int, const string&);
	int getID();
	string getName();

	bool operator == (const User& rhs) const {
		return ID == rhs.ID;
	}
private:
	string name; int ID;
	static int k;
};


