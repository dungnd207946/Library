#pragma once
#include<iostream>
#include"Book.h"
#include<vector>
using namespace std;

class User {
public:
	User();

	//~User();
	void read(Book b);
	//void read(sampleBook b);
	void searchByTitle(vector<Book>);
	void searchBySerial(vector<Book>);

};