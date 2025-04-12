#pragma once
#include <string>
#include "Media.h"

using namespace std;

class Audiobook : public Media {
private:
    string narrator;
public:
    Audiobook(string narrator = "Unknown", string mediaType = "", int mediaId = 0, int year = 0, string mediaName = "Unknown");
    virtual ~Audiobook();

    string getNarrator() const ;
    string getInfo() const override;

};


