#pragma once
#include"User.h"
class registerUser : public User {
private:
	int ID;
	int userCount;
	string userName;
	string passWord;
	string phoneNumber;
public:
	registerUser();
	registerUser(string userName, string passWord);
	//~registerUser();
	
	int getID();
	string getName();
	string getPassWord();
	string getPhoneNumber();
	int getUserCount();
	
	void setID(int);
	void setName(string);
	void setPassWord(string);
	void setPhoneNumber(string);

	bool login(string user, string pass);
	void logout();
};
