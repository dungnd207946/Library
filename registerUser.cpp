#include"registerUser.h"
#include<string>

registerUser::registerUser()
{
	ID = 0;
	userName = "";
	passWord = "";
	phoneNumber = "";
	userCount++;
}
registerUser::registerUser(string userName, string passWord) {
	this->userName = userName;
	this->passWord = passWord;
}

bool registerUser::login(string user, string pass)
{
	bool check = false;
	if (user.compare(userName)==0 && pass.compare(passWord)==0) {
		check = true;
	}
	return check;
}

void registerUser::logout()
{
	cout << "Logout" << endl;
}



int registerUser::getID()
{
	return ID;
}

string registerUser::getName()
{
	return userName;
}

string registerUser::getPassWord()
{
	return passWord;
}

string registerUser::getPhoneNumber()
{
	return phoneNumber;
}

int registerUser::getUserCount()
{
	userCount = 0;
	return userCount++;
}

void registerUser::setID(int newID)
{
	ID = newID;
}

void registerUser::setName(string newName)
{
	userName = newName;
}

void registerUser::setPassWord(string newPassWord)
{
	passWord = newPassWord;
}

void registerUser::setPhoneNumber(string newPhone)
{
	phoneNumber = newPhone;
}
