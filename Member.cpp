#include"Member.h"
#include<string>
Member::Member():startDate(""), endDate(""){}
Member::Member(string username, string password) : registerUser(username, password) {}

Member::~Member()
{
	borrowList.clear();
	subColList.clear();
}

string Member::getStartDate()
{
	return startDate;
}

string Member::getEndDate()
{
	return endDate;
}

void Member::setStartDate(string s)
{
	startDate = s;
}

void Member::setEndDate(string e)
{
	endDate = e;
}

void Member::borrowBook(vector<Book> &bList)
{
	string title_b;
	string serial;
	int count = 0;
	cout << "Enter the title of book you want to borrow: ";
	cin.ignore();
	getline(cin, title_b);
	cout << "Enter the serial of book you want to borrow: ";
	getline(cin, serial);
	for (int i = 0; i < bList.size(); i++) {
		if (bList[i].getTitle().compare(title_b) == 0 && bList[i].getSerial().compare(serial) == 0) {
			if (bList[i].getAvailability()) {
				if (bList[i].getVisibility()) {
					cout << "The book " << bList[i].getTitle() << " is available for you to borrow." << endl;
					bList[i].setAvailability(false);
					borrowList.push_back(bList[i]);
				}
				else {
					cout << "The book has been hidden." << endl;
				}
			}
			else {
				cout << "The book has been borrowed." << endl;
			}
			count++;
		}		
	}
	if(count==0) {
		cout << "Book is not in the list.\nPlease return the main option." << endl;
	}

}

void Member::returnBook(vector<Book>& bList)
{
	string title_b;
	string serial;
	int count=0;
	cout << "Enter the title of book you want to return: ";
	cin.ignore();
	getline(cin, title_b);
	cout << "Enter the serial of book you want to return: ";
	getline(cin, serial);
	for (int i = 0; i < bList.size(); i++) {
		if (bList[i].getTitle().compare(title_b) == 0 && bList[i].getSerial().compare(serial) == 0) {
			bList[i].setAvailability(true);
			cout << "The book " << bList[i].getTitle() << " is return successfully." << endl;
			count++;
		}	
	}
	if(count==0) {
		cout << "Book is not belong to the Library. \nPlease return the main option." << endl;
	}
}

void Member::read_M(vector<Book>& bList)
{
	string title_b;
	string serial;
	int count = 0;
	cout << "Enter the title of book you want to read: ";
	cin.ignore();
	getline(cin, title_b);
	cout << "Enter the serial of book you want to read: ";
	getline(cin, serial);
	for (int i = 0; i < bList.size(); i++) {
		if (bList[i].getTitle().compare(title_b) == 0 && bList[i].getSerial().compare(serial) == 0) {
			cout << "Reading book " << bList[i].getTitle() << " successfully." << endl;
			count++;
		}
	}
	if (count == 0) {
		cout << "Book is not belong to the Library. \nPlease return the main option." << endl;
	}
}

void Member::subcribe( vector<Collection> cList)
{
	string name_c;
	int ID_c;
	int count = 0;
	cout << "Enter the information of collection you want to subcribe: " << endl;
	cout << "Name: ";
	cin.ignore();
	getline(cin, name_c);
	cout << "ID: ";
	cin >> ID_c;
	for (int i = 0; i < cList.size(); i++) {
		if (cList[i].getName().compare(name_c) == 0 && cList[i].getID() == ID_c) {
			subColList.push_back(cList[i]);
			cList[i].addSubMember(*this);
			cout << "Collection " << name_c << " has been add to "<< this->getName()<<"'s subcribe list." << endl;
			count++;
		}	
	}
	if(count==0) {
		cout << "Collection is not in the Library.\n Please return the main option." << endl;
	}
}

void Member::unsubcribe()
{
	string name_c;
	int ID_c;
	int count = 0;
	cout << "Enter the information of collection you want to unsubcribe: " << endl;
	cout << "Name: ";
	cin.ignore();
	getline(cin, name_c);
	cout << "ID: ";
	cin >> ID_c;
	for (int i = 0; i < subColList.size(); i++) {
		if (subColList[i].getName().compare(name_c) == 0 && subColList[i].getID() == ID_c) {
			subColList.erase(subColList.begin()+i);
			cout << "Collection " << name_c << " has been unsubcribe from " << this->getName() << "'s subcribe list." << endl;
			count++;
		}		
	}
	if(count==0) {
		cout << "Collection is not in the subcribe list.\n Please return the main option." << endl;
	}
}

void Member::displayCollectionSubcribed()
{
	for (int i = 0; i < subColList.size(); i++) {
		cout << i + 1 << ". " << subColList[i].getName() << endl;
	}
}

void Member::displayBookBorrow()
{
	for (int i = 0; i < borrowList.size(); i++) {
		cout << i + 1 << ". " << borrowList[i].getTitle() << endl;
	}
}



void Member::Samplesubscribe(Collection c) {
	bool sampleExists = false;
	
		if (c.getName() == "Sample") {
			sampleExists = true;
			subColList.push_back(c);
			c.addSubMember(*this);
			//cout << "Collection Sample has been added to " << this->getName() << "'s subscriptions." << endl;
		}
	
}

