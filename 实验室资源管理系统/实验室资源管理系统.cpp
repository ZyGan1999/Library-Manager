
#include"operation.h"

int main()
{
	operation* op = new operation;
	while (1) {
		op->MENU();
		int choice;
		cin >> choice;

		switch (choice) {
		case 1: {
			cout << "请输入要创建的用户名" << endl;
			string UserName;
			cin >> UserName;
			op->AddPerson(User(UserName));
			cout << "添加成功" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 2: {
			cout << "请输入要删除的用户的用户名" << endl;
			string name;
			cin >> name;
			op->DeletePerson(name);
			cout << "删除成功" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 3: {
			cout << "请输入要增添的书目的名称" << endl;
			string bookname; cin >> bookname;
			cout << "请输入要增添的书目的作者名" << endl;
			string authorname; cin >> authorname;
			cout << "请输入要增添的书目的出版社名" << endl;
			string publishername; cin >> publishername;
			cout << "请录入书本的正文内容" << endl;
			string content; cin >> content;

			op->AddResourse(Book(bookname, authorname, publishername,content));
			cout << "添加成功" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 4: {
			cout << "请输入要删除的书目的ID" << endl;
			int id;
			cin >> id;
			if (op->DeleteResourse_B(id)) {
				cout << "删除成功" << endl;
			}
			else {
				cout << "删除失败" << endl;
			}
			system("pause");
			system("cls");
			break;
		}
		case 5: {
			cout << "请输入要增添的文献的名称" << endl;
			string bookname; cin >> bookname;
			cout << "请输入要增添的文献的作者名" << endl;
			string authorname; cin >> authorname;
			cout << "请录入文献内容" << endl;
			string _content; cin >> _content;
			op->AddResourse(Eassy(bookname, authorname,_content));
			cout << "添加成功" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 6: {
			cout << "请输入要删除的文献的ID" << endl;
			int id;
			cin >> id;
			if (op->DeleteResourse_E(id)) {
				cout << "删除成功" << endl;
			}
			else {
				cout << "删除失败" << endl;
			}
			system("pause");
			system("cls");
			break;
		}
		case 7: {
			cout << "请检索要查询的书目的关键字" << endl;
			string key;
			cin >> key;
			if (op->QueryBook(key)) {
				cout << "以上是您的查询结果" << endl;
			}
			else {
				cout << "未找到相关信息" << endl;
			}
			system("pause");
			system("cls");
			break;
		}
		case 8: {
			cout << "请检索要查询的文献的关键字" << endl;
			string key;
			cin >> key;
			if (op->QueryBook(key)) {
				cout << "以上是您的查询结果" << endl;
			}
			else {
				cout << "未找到相关信息" << endl;
			}
			system("pause");
			system("cls");
			break;
		}
		case 9: {
			cout << "请输入借出的图书的ID" << endl;
			int id;
			cin >> id;
			if (op->RentBook(id)) {
				cout << "借出成功" << endl;
			}
			else {
				cout << "借出失败，ID不存在" << endl;
			}
			system("pause");
			system("cls");
			break;
		}
		case 10: {
			cout << "请输入归还的图书的ID" << endl;
			int id;
			cin >> id;
			if (op->BackBook(id)) {
				cout << "归还成功" << endl;
			}
			else {
				cout << "归还失败，ID不存在" << endl;
			}
			system("pause");
			system("cls");
			break;
		}
		case 11: {
			cout << "请输入借出的文献的ID" << endl;
			int id;
			cin >> id;
			if (op->RentEassy(id)) {
				cout << "借出成功" << endl;
			}
			else {
				cout << "借出失败，ID不存在" << endl;
			}
			system("pause");
			system("cls");
			break;
		}
		case 12: {
			cout << "请输入归还的文献的ID" << endl;
			int id;
			cin >> id;
			if (op->BackBook(id)) {
				cout << "归还成功" << endl;
			}
			else {
				cout << "归还失败，ID不存在" << endl;
			}
			system("pause");
			system("cls");
			break;
		}

		}

	}

	delete op;
    return 0;
}

