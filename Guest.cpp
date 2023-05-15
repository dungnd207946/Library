
#include "Guest.h"
#include<vector>
#include<string>
Guest::Guest(){}
Guest::Guest(int newID)
{
	ID = newID;
}
int Guest::getID()
{
	return ID;
}

void Guest::setID(int newID)
{
	ID = newID;
}

void Guest::Register()
{
	cout << "Register as member Successfully!" << endl;
	cout << "Your member account has been created.\nPlease login using the following credentials: " << endl;
	cout << "Username: member3" << endl;
	cout << "Password: 456789" << endl;
}
void Guest::read_G(Collection c) {
	cout << "Sample Books" << endl;
	for (int i = 0; i < c.getBook().size(); i++) {
		cout << i + 1 << ". " << c.getBook()[i].getTitle() << endl;
		cout << "   Serial: " << c.getBook()[i].getSerial() << endl;
	}
	char check;
	cout << "Do you want to read a book?(y/n): ";
	cin >> check;
	if (check == 'y' || check == 'Y') {
		string title_b;
		string serial;
		int count = 0;
		cout << "Enter the title of book you want to read: ";
		cin.ignore();
		getline(cin, title_b);
		cout << "Enter the serial of book you want to read: ";
		getline(cin, serial);
		for (int i = 0; i < c.getBook().size(); i++) {
			if (c.getBook()[i].getTitle().compare(title_b) == 0 && c.getBook()[i].getSerial().compare(serial) == 0) {
				cout << "Reading " << c.getBook()[i].getFreePage() << " Free Pages!" << endl;
				count++;
			}
		}
		if (count == 0) {
			cout << "Book is not in the list. Please return to the main option." << endl;
		}
	}
	else { return; }
}