#pragma once
#include "Media.h"

using namespace std;

class Book : public Media {

private:
    string author;
public:
    Book(string author = "Unknown", string mediaType = "", int mediaId = 0, int year = 0, string mediaName = "Unknown");
    virtual ~Book();


    string getAuthor() const;
    string getInfo() const override;

};


