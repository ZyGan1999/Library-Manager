#pragma once
#include"Person.h"
#include "resourse.h"
#include <list>

class operation {
public:
	operation();
	~operation();

	void AddResourse(Book&);
	bool DeleteResourse_B(int);
	void AddResourse(Eassy&);
	bool DeleteResourse_E(int);

	void AddPerson(User&);
	bool DeletePerson(const std::string&);

	bool QueryBook(const std::string&);//¹Ø¼ü×Ö²éÑ¯
	bool QueryEassy(const std::string&);

	bool RentBook(int);
	bool RentEassy(int);

	bool BackBook(int);
	bool BackEassy(int);

	void MENU();
private:
	std::list<User> uList;
	std::list<Book> bList;
	std::list<Eassy> eList;
};