#include "User.h"
#include<vector>
#include<string>
User::User()
{
}



void User::searchByTitle(vector<Book> bList )
{
	string title_b;
	string serial;
	int count = 0;
	cout << "Enter the title of book you want to search: ";
	cin.ignore();
	getline(cin, title_b);
	
	for (int i = 0; i < bList.size(); i++) {
		if (bList[i].getTitle().compare(title_b) == 0 ) {
			cout << i+1<<". " << bList[i].getTitle()<<" - Serial: " << bList[i].getSerial() << endl;
			count++;
		}
	}
	if (count == 0) {
		cout << "Book is not in the Library. \nPlease return the main option." << endl;
	}
}

void User::searchBySerial(vector<Book> bList)
{
	string title_b;
	string serial;
	int count = 0;

	cout << "Enter the serial of book you want to search: ";
	cin.ignore();
	getline(cin, serial);
	for (int i = 0; i < bList.size(); i++) {
		if ( bList[i].getSerial().compare(serial) == 0) {
			cout << i+1<<". " << bList[i].getTitle() << " - Serial: "<< bList[i].getSerial() << endl;
			count++;
		}
	}
	if (count == 0) {
		cout << "Book is not in the Library. \nPlease return the main option." << endl;
	}
}

