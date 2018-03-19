#include"resourse.h"
int Resourse::_K = 1;
Book::Book(const string& bookname, const string& authorname, const string& publishername,const string& _content) :Resourse::Resourse() {
	name = bookname;
	AuthorName = authorname;
	PublisherName = publishername;
	content = _content;
}

Book::Book(int id,int _isIN,const string& bookname, const string& authorname, const string& publishername, const string& _content) :Resourse::Resourse() {
	ID = id;
	isIN = _isIN;
	name = bookname;
	AuthorName = authorname;
	PublisherName = publishername;
	content = _content;
}

Eassy::Eassy(const string& eassyname, const string& authorname,const string& _content) :Resourse::Resourse() {
	name = eassyname;
	AuthorName = authorname;
	content = _content;

}

Eassy::Eassy(int id,int _isIN, const string& eassyname, const string& authorname, const string& _content) {
	ID = id;
	isIN = _isIN;
	name = eassyname;
	AuthorName = authorname;
	content = _content;
}

bool Resourse::isInStorage() {
	return isIN;
}

Resourse::Resourse() {
	isIN = true;
	ID = _K++;
	name = "None";
}

string Resourse::getContent() {
	return content;
}

int Resourse::getID() {
	return ID;
}

string Resourse::getName() {
	return name;
}

void Resourse::checkIN() {
	isIN = true;
}

void Resourse::checkOUT() {
	isIN = false;
}

string Book::getAuthorName()
{
	return AuthorName;
}

string Book::getPublisherName()
{
	return PublisherName;
}


string Eassy::getAuthorName() {
	return AuthorName;
}