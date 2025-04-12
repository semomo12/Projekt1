#include "Book.h"
#include <iostream>

using namespace std;

Book::Book(string author, string type, int mediaId, int year, string mediaName)
	:Media("Book",mediaId, year, mediaName),author(author)
{
}

Book::~Book()
{
}

string Book::getAuthor() const
{
	return this->author;
}

string Book::getInfo() const
{
	return Media::getInfo() +" | Author: " + getAuthor();
}
