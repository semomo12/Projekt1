#pragma once
#include <string>

using namespace std;

class Media {
private:
    int mediaId;
    int year;
    string mediaName;
    string mediaType;
public:

    Media(string mediaType="", int mediaId = 0, int year = 0, string mediaName = "Unknown");
    virtual ~Media();

    int getMediaId() const;
    int getYear() const;
    string getMediaName() const;
    string getMediaType() const;



    virtual string getInfo() const = 0;

};
