#include"Administrator.h"

Administrator::Administrator()
{
}

Administrator::~Administrator()
{
	//cList.clear();
	//bList.clear();
}
Administrator::Administrator(string username, string password) : registerUser(username, password)
{
}
void Administrator::add(Book b, vector<Book> &bList)
{
	bList.push_back(b);
}

void Administrator::show(vector<Book> &bList)
{
	for (int i = 0; i < bList.size(); i++) {
		cout << i + 1 << ". " << bList[i].getTitle() << endl;
		cout << "   Serial: " << bList[i].getSerial() << endl;
	}
	char check;
	cout << "Do you want to see the detail of a book?(y/n): ";
	cin >> check;
	if (check == 'y' || check == 'Y') {
		string title_b;
		string serial;
		int count = 0;
		cout << "Enter the title of book you want to see: ";
		cin.ignore();
		getline(cin, title_b);
		cout << "Enter the serial of book you want to see: ";	
		getline(cin, serial);
		for (int i = 0; i < bList.size(); i++) {
			if (bList[i].getTitle().compare(title_b) == 0 && bList[i].getSerial().compare(serial) == 0) {
				cout << endl;
				cout << "Title: " << bList[i].getTitle() << endl;
				cout << "Serial: " << bList[i].getSerial() << endl;
				cout << "Author name: " << bList[i].getAuthorName() << endl;
				cout << "Number of page: " << bList[i].getPageNumber() << endl;
				cout << "Free page number: " << bList[i].getFreePage() << endl;
				cout << "Category: " << bList[i].getCategory() << endl <<endl;
				if (bList[i].getAvailability()) {
					cout << "Availability: Available" << endl;
				}
				else {
					cout << "Availability: Not available" << endl;
				}
				if (bList[i].getVisibility()) {
					cout << "Visibility: Visible" << endl;
				}
				else {
					cout << "Visibility: Not visible" << endl;
				}
				count++;
			}
			
		}
		if(count==0) {
			cout << "Book is not in the list. Please return the main option." << endl;
		}
	}
	else { return; }
}

void Administrator::hide(vector<Book>& bList)
{
	string title_b;
	string serial;
	int count = 0;
	cout << "Enter the title of book you want to hide: ";
	cin.ignore();
	getline(cin, title_b);
	cout << "Enter the serial of book you want to hide: ";
	getline(cin, serial);
	for (int i = 0; i < bList.size(); i++) {
		if (bList[i].getTitle().compare(title_b) == 0 && bList[i].getSerial().compare(serial) == 0) {
			bList[i].setVisibility(false);
			cout << "The book " << bList[i].getTitle() << " have been hidden."<<endl;
			count++;
		}	
	}
	if(count==0) {
		cout << "Book is not in the list. Please return the main option." << endl;
	}
}

void Administrator::remove(vector<Book>& bList)
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
			bList.erase(bList.begin()+i);
			cout << "Remove book from Library successfully" << endl;
			count++;
		}		
	}
	if(count==0) {
		cout << "Book is not in the list. Please return the main option." << endl;
	}
}

void Administrator::edit(vector<Book>& bList)
{
	string title_b;
	string serial;
	int count = 0;
	cout << "Enter the title of book you want to edit: ";
	cin.ignore();
	getline(cin, title_b);
	cout << "Enter the serial of book you want to edit: ";
	getline(cin, serial);
	for (int i = 0; i < bList.size(); i++) {
		if (bList[i].getTitle().compare(title_b)==0 && bList[i].getSerial().compare( serial)==0) {
			int p;
			cout << "Edit book's free page number: " ;
			cin >> p;
			bList[i].setFreePage(p);
			count++;
		}
		
	}
	if(count == 0) {
		cout << "Book is not in the list. Please return the main option." << endl;
	}
}

void Administrator::createCollection( vector<Collection> &cList)
{
	Collection c;
	string name_c;
	int ID_c;
	cout << "Enter the name of the collection: ";
	cin.ignore();
	getline(cin, name_c);
	cout << "Enter the ID of the collection: ";
	cin >> ID_c;
	c.setName(name_c);
	c.setID(ID_c);
	cout << "Finish adding collection." << endl;
	cList.push_back(c);

}

void Administrator::deleteCollection(vector<Collection> &cList)
{
	string name_c;
	int ID_c;
	int count = 0;
	cout << "Enter the information of collection you want to delete: "<<endl;
	cout << "Name: ";
	cin.ignore();
	getline(cin, name_c);
	cout << "ID: ";
	cin >> ID_c;
	for (int i = 0; i < cList.size(); i++) {
		if (cList[i].getName().compare(name_c) == 0 && cList[i].getID() == ID_c) {		
			cList.erase(cList.begin()+i);
			cout << "Collection " << name_c << " has been deleted." << endl;
			count++;
		}		
	}
	if(count == 0) {
		cout << "Collection is not in the list. Please return the main option." << endl;
	}

}

void Administrator::addToCol( vector<Book> &bList,vector<Collection> &cList) // cList la collection list o ham main
{
	string title_b;
	string serial;
	int count = 0;
	cout << "Enter the title of book you want to add: ";
	cin.ignore();
	getline(cin, title_b);
	cout << "Enter the serial of book you want to add: ";
	getline(cin, serial);
	for (int i = 0; i < bList.size(); i++) {
		if (bList[i].getTitle().compare(title_b) == 0 && bList[i].getSerial().compare(serial) == 0) {
			string name_c;
			int ID_c;
			int isCol = 0;
			cout << "Enter the information of collection you want to add book to: " << endl;
			cout << "Name: ";
			//cin.ignore();
			getline(cin, name_c);
			cout << "ID: ";
			cin >> ID_c;
			for (int k = 0; k < cList.size(); k++) {
				if (cList[k].getName().compare(name_c) == 0 && cList[k].getID() == ID_c) {
					cList[k].addBook(bList[i]);
					cout << "Add book to collection successfully" << endl;
					isCol++;
				}
			}
			if (isCol == 0) {
				cout << "Collection is not in the list. Please return the main option." << endl;
			}
			count++;
		}
		if(count ==0) {
			cout << "Book is not in the list. Please return the main option." << endl;
		}
	}
}

void Administrator::removeFromCol(vector<Collection>& cList)
{
	string name_c;
	int ID_c;
	int count = 0;
	cout << "Enter the information of collection you want to remove book: " << endl;
	cout << "Name: ";
	cin.ignore();
	getline(cin, name_c);
	cout << "ID: ";
	cin >> ID_c;
	for (int k = 0; k < cList.size(); k++) {
		if (cList[k].getName().compare(name_c) == 0 && cList[k].getID() == ID_c) {
			cList[k].removeBook();
			cout << "Remove book from collection successfully" << endl;
			count++;
		}
	}
	if (count == 0) {
		cout << "Book is not in the list. Please return the main option." << endl;
	}
}

void Administrator::showCol(vector<Collection> cList)
{
	for (int i = 0; i < cList.size(); i++) {
		cout << i + 1 << ". " << cList[i].getName() << endl;
		cout << "ID: " << cList[i].getID()<<endl<<endl;

	}
}
