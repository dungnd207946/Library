#include"Book.h"

Book::Book():title(""),serialNumber(""),authorName(""), Cate(""), pageNumber(0), freePageNumber(0), visibilityStatus(0), availability(0) {}

Book::Book(string newTile, string newSerial, string newAuthorName, int newPageNum, int newFreePage, string newCate, bool status, bool avail)
{
	title = newTile;
	serialNumber = newSerial;
	authorName = newAuthorName;
	pageNumber = newPageNum;
	freePageNumber = newFreePage;
	Cate = newCate;
	visibilityStatus = status;
	availability = avail;
}

string Book::getTitle()
{
	return title;
}

string Book::getSerial()
{
	return serialNumber;
}

string Book::getAuthorName()
{
	return authorName;
}

int Book::getPageNumber()
{
	return pageNumber;
}

int Book::getFreePage()
{
	return freePageNumber;
}

string Book::getCategory()
{
	return Cate;
}

bool Book::getVisibility()
{
	return visibilityStatus;
}

bool Book::getAvailability()
{
	return availability;
}

void Book::setTitle(string newTitle)
{
	title = newTitle;
}

void Book::setSerial(string newSerial)
{
	serialNumber = newSerial;
}

void Book::setAuthorName(string newAuthorName)
{
	authorName = newAuthorName;
}

void Book::setPageNumber(int newPageNum)
{
	pageNumber = newPageNum;
}

void Book::setFreePage(int newFreePage)
{
	freePageNumber = newFreePage;
}

void Book::setCategory(string newCate)
{
	Cate = newCate;
}

void Book::setVisibility(bool check)
{
	visibilityStatus = check;
}

void Book::setAvailability(bool check)
{
	availability = check;
}


