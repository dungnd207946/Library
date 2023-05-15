#pragma once
#include"User.h"
#include<vector>
#include"Collection.h"


class Guest : public User {
private:
	int ID;
public:
	Guest();
	Guest(int);
	int getID();
	void setID(int);
	void Register();
	void read_G(Collection );
};
