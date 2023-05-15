#pragma once
#include<iostream>
using namespace std;


class Book {
private:
	string title;
	string serialNumber;
	string authorName;
	int pageNumber;
	int freePageNumber;
	string Cate;
	bool visibilityStatus;
	bool availability;
public:
	Book();
	Book(string newTile, string newSerial, string newAuthorName,
		int newPageNum, int newFreePage, string newCate, bool status, bool avail);
	//~Book();

	string getTitle();
	string getSerial();
	string getAuthorName();
	int getPageNumber();
	int getFreePage();
	string getCategory();
	bool getVisibility();
	bool getAvailability();

	void setTitle(string);
	void setSerial(string);
	void setAuthorName(string);
	void setPageNumber(int);
	void setFreePage(int);
	void setCategory(string);
	void setVisibility(bool);
	void setAvailability(bool);

};