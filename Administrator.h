#pragma once
#include"registerUser.h"
#include"Collection.h"
#include<vector>
#include<string>
class Collection;
class Book;
class Administrator : public registerUser {
private: 
	//vector<Collection> cList;
	//vector<Book> bList;
public:
	Administrator();
	Administrator(string, string);
	~Administrator();

	void add(Book b, vector<Book> &bList);
	void show(vector<Book>& bList);
	void hide(vector<Book>& bList);
	void remove(vector<Book>& bList);
	void edit(vector<Book>& bList);
	void createCollection( vector<Collection> &cList);
	void deleteCollection(vector<Collection> &cList);
	void addToCol(vector<Book>& bList, vector<Collection>& cList);
	void removeFromCol(vector<Collection>& cList);
	void showCol(vector<Collection> cList);
};
