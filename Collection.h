#pragma once
#include"Book.h"
#include"User.h"
#include<vector>
#include"Member.h"

class Member;
class Collection : public Book {
private:
	int ID;
	string name;
	vector<Book> bList;
	vector<Member> subcribed_Member;
public: 
	Collection();
	Collection(int newID, string newName);
	~Collection();

	int getID();
	string getName();
	
	void setID(int);
	void setName(string);

	void addBook(Book b);
	vector<Book> getBook();
	void removeBook();
	void addSubMember(Member &m);

};
