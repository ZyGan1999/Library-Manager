#pragma once
#include<iostream>
#include<string>

using namespace std;
class Resourse {
public:
	Resourse();
	int getID();
	string getName();
	string getContent();
	void checkIN();
	void checkOUT();
	bool isInStorage();
protected:
	int ID; string name; bool isIN; static int _K;
	string content;
};


class Book :public Resourse {
public:
	Book(int id,int isIN ,const string& bookname, const string& authorname, const string& publishername, const string& _content);
	Book(const string&,const string&,const string&,const string&);
	string getAuthorName();
	string getPublisherName();
	bool operator == (const Book& rhs) const {
		return ID == rhs.ID;
	}
	friend ofstream;
private:
	string AuthorName; string PublisherName;
};

class Eassy :public Resourse {
public:
	Eassy(int id,int isIN,const string&,const string&,const string&);
	Eassy(const string&,const string&,const string&);
	string getAuthorName();
	bool operator == (const Eassy& rhs) const
	{
		return ID == rhs.ID;
	}
private:
	string AuthorName; 
};