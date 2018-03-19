#include "operation.h"
#include<fstream>
operation::operation() {
	/*���¹���bList����*/
	ifstream inputBName("c:\\\\Resource\\\\BOOKS\\\\booklist.txt");
	string curBName;
	while (!inputBName.eof()) {
		getline(inputBName, curBName);
		ifstream inputBook("c:\\\\Resource\\\\BOOKS\\\\" + curBName + ".txt");
		string id; string isIN; string AuthorName; string PublisherName; string content;
		getline(inputBook, id); getline(inputBook, isIN); getline(inputBook, AuthorName); getline(inputBook, PublisherName); getline(inputBook, content);
		int _id = atoi(id.c_str());
		int _isIN = atoi(isIN.c_str());
		Book curBook(_id,_isIN,curBName, AuthorName, PublisherName, content);
		bList.push_front(curBook);
	}

	/*���¹���eList����*/
	ifstream inputEName("c:\\\\Resource\\\\EASSYS\\\\eassylist.txt");
	string curEName;
	while (!inputEName.eof()) {
		getline(inputEName, curEName);
		ifstream inputEassy("c:\\\\Resource\\\\EASSYS\\\\" + curEName + ".txt");
		string id; string isIN; string AuthorName; string content;
		getline(inputEassy, id); getline(inputEassy, isIN); getline(inputEassy, AuthorName);  getline(inputEassy, content);
		int _id = atoi(id.c_str());
		int _isIN = atoi(isIN.c_str());
		Eassy curEassy(_id,_isIN, curEName, AuthorName, content);
		eList.push_front(curEassy);
	}

	/*���¹���uList����*/
	ifstream inputUName("c:\\\\Resource\\\\USERS\\\\userlist.txt");
	string curUName;
	while (!inputUName.eof()) {
		getline(inputUName, curUName);
		ifstream inputUser("c:\\\\Resource\\\\USERS\\\\" + curUName + ".txt");
		string id;	
		getline(inputUser, id);
		int _id = atoi(id.c_str());
		User curUser(_id, curUName);
		uList.push_front(curUser);
	}
}

void operation::AddResourse(Book & book)
{
	bList.push_front(book);

	string bookname = book.getName();
	ofstream SaveName("c:\\\\Resource\\\\BOOKS\\\\booklist.txt", ios::app);
	SaveName << bookname << endl;

	bookname += ".txt";
	bookname = "c:\\\\Resource\\\\BOOKS\\\\" + bookname;

	ofstream SaveBook(bookname,ios::ate);
	/*������ӵ���Ŀ�½�һ��txt�ļ�,�洢��ָ����Ŀ¼��*/
	SaveBook << book.getID() << endl << book.isInStorage() << endl << book.getAuthorName() << endl
		<< book.getPublisherName() << endl << book.getContent() << endl;
}

bool operation::DeleteResourse_B(int id)
{
	for (std::list<Book>::iterator i = bList.begin(); i != bList.end(); ++i)
	{
		if ((*i).getID() == id)
		{
			bList.remove(*i);
			return true;
		}
	}
	return false;
}

void operation::AddResourse(Eassy & eassy)
{
	eList.push_front(eassy);

	string eassyname = eassy.getName();
	ofstream SaveName("c:\\\\Resource\\\\EASSYS\\\\eassylist.txt", ios::app);
	SaveName << eassyname << endl;

	eassyname += ".txt";
	eassyname = "c:\\\\Resource\\\\EASSYS\\\\" + eassyname;

	ofstream SaveEassy(eassyname, ios::ate);
	/*������ӵ������½�һ��txt�ļ�,�洢��ָ����Ŀ¼��*/
	SaveEassy << eassy.getID() << endl << eassy.isInStorage() << endl << eassy.getAuthorName()
		<< endl << eassy.getContent() << endl;
}

bool operation::DeleteResourse_E(int id)
{
	for (std::list<Eassy>::iterator i = eList.begin(); i != eList.end(); ++i) {
		if (i->getID() == id) {
			eList.remove(*i);
			return true;
		}
	}
	return false;
}

void operation::AddPerson(User &us)
{
	uList.push_front(us);
}

bool operation::DeletePerson(const std::string & name)
{
	for (std::list<User>::iterator i = uList.begin(); i != uList.end(); ++i) {
		if (i->getName() == name) {
			uList.remove(*i);
			return true;
		}
	}
	return false;
}


bool operation::QueryBook(const std::string& name)
{
	bool ret = false;

	for (std::list<Book>::iterator i = bList.begin(); i != bList.end(); ++i) {
		if ((*i).getName().find(name, 0) != std::string::npos||i->isInStorage())
		{
			ret = true;
			std::cout << i->getID() << ' ' << i->getName() << ' ' << i->getAuthorName()
				<< ' ' << i->getPublisherName() << std::endl;
		}
	}
	return ret;
}

bool operation::QueryEassy(const std::string &name)
{
	bool ret = false;

	for (std::list<Eassy>::iterator i = eList.begin(); i != eList.end(); ++i) {
		if (i->getName().find(name, 0) != std::string::npos) {
			ret = true;
			std::cout << i->getID() << ' ' << i->getName() << ' ' << i->getAuthorName() << std::endl;
		}
	}
	return ret;
}

bool operation::RentBook(int id)
{
	for (std::list<Book>::iterator i = bList.begin(); i != bList.end(); ++i) {
		if (i->getID() == id) {
			i->checkOUT();
			return true;
		}
	}
	return false;
}

bool operation::RentEassy(int id)
{
	for (std::list<Eassy>::iterator i = eList.begin(); i != eList.end(); ++i) {
		if (i->getID() == id) {
			i->checkOUT();
			return true;
		}
	}
	return false;
}

bool operation::BackBook(int id)
{
	for (std::list<Book>::iterator i = bList.begin(); i != bList.end(); ++i) {
		if (i->getID() == id) {
			i->checkIN();
			return true;
		}
	}
	return false;
}

bool operation::BackEassy(int id)
{
	for (std::list<Eassy>::iterator i = eList.begin(); i != eList.end(); ++i) {
		if (i->getID() == id) {
			i->checkIN();
			return true;
		}
	}
	return false;
}

void operation::MENU()
{
	cout << "��ѡ��������еĲ���" << endl;
	cout << "1������û�" << endl;
	cout << "2��ɾ���û�" << endl;
	cout << "3��������Ŀ" << endl;
	cout << "4��ɾ����Ŀ" << endl;
	cout << "5����������" << endl;
	cout << "6��ɾ������" << endl;
	cout << "7����ѯͼ��" << endl;
	cout << "8����ѯ����" << endl;
	cout << "9��ͼ����" << endl;
	cout << "10��ͼ��黹" << endl;
	cout << "11�����׽��" << endl;
	cout << "12�����׹黹" << endl;
	cout << "13�������Ķ�" << endl;
}


operation::~operation() {
	ofstream SaveBookName("c:\\\\Resource\\\\BOOKS\\\\booklist.txt", ios::trunc | ios::app);
	for (std::list<Book>::iterator i = bList.begin(); i != bList.end(); ++i) {
		SaveBookName << i->getName() << endl;
	}

	ofstream SaveEassyName("c:\\\\Resource\\\\EASSYS\\\\eassylist.txt", ios::trunc | ios::app);
	for (std::list<Eassy>::iterator i = eList.begin(); i != eList.end(); ++i) {
		SaveEassyName << i->getName() << endl;
	}

	ofstream SaveUserName("c:\\\\Resource\\\\USERS\\\\userlist.txt", ios::trunc | ios::app);
	for (std::list<User>::iterator i = uList.begin(); i != uList.end(); ++i) {
		SaveUserName << i->getName() << endl;
	}
}

