#include"Collection.h"
#include<string>
Collection::Collection():ID(0), name(""){}

Collection::Collection(int newID, string newName)
{
	ID = newID;
	name = newName;
}

Collection::~Collection()
{
	bList.clear();
	subcribed_Member.clear();
}

int Collection::getID()
{
	return ID;
}

string Collection::getName()
{
	return name;
}

void Collection::setID(int newID)
{
	ID = newID;
}

void Collection::setName(string newName)
{
	name = newName;
}

void Collection::addBook(Book b)
{
	bList.push_back(b);
}

vector<Book> Collection::getBook()
{
	return bList;
}

void Collection::removeBook()
{
	string title_b;
	string serial;
	int count = 0;
	cout << "Enter the title of book you want to remove: ";
	cin.ignore();
	getline(cin, title_b);
	cout << "Enter the serial of book you want to remove: ";
	getline(cin, serial);
	for (int i = 0; i < bList.size(); i++) {
		if (bList[i].getTitle().compare(title_b) == 0 && bList[i].getSerial().compare(serial) == 0) {
			bList.erase(bList.begin() + i);
			count++;
		}		
	}
	if(count == 0) {
		cout << "Book is not in the list. Please return the main option." << endl;
	}
}

void Collection::addSubMember(Member &m)
{
	subcribed_Member.push_back(m);
}


