#pragma once
#include "Media.h"

using namespace std;

class Film : public Media {
private:
    string director;
public:
    Film(string director = "Unknown",string mediaType = "", int mediaId = 0, int year = 0, string mediaName = "Unknown");
    virtual  ~Film();


    string getDirector() const;

    string getInfo() const override;

};
