#pragma once
#include"registerUser.h"
#include"Collection.h"
#include<vector>

class Collection;

class Member : public registerUser {
private:
	string startDate;
	string endDate;
	vector<Book> borrowList;
	vector<Collection> subColList;
public:
	Member();
	Member(string username, string password);
	~Member();

	string getStartDate();
	string getEndDate();

	void setStartDate(string);
	void setEndDate(string);

	void borrowBook(vector<Book> &bList);
	void returnBook(vector<Book>& bList);
	void read_M(vector<Book>& bList);
	void subcribe(vector<Collection> );
	void unsubcribe();
	void displayCollectionSubcribed();
	void displayBookBorrow();
	void Samplesubscribe(Collection c);
};
