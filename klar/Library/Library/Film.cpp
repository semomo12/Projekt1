#include "Film.h"

#include <iostream>

using namespace std;

Film::Film(string director, string type, int mediaId, int year, string mediaName)
	:Media("Movie", mediaId, year, mediaName),director(director)
{
}

Film::~Film()
{
}

string Film::getDirector() const
{
    return this->director;
}

string Film::getInfo() const
{
	return Media::getInfo() +" | Director: " + getDirector();


}
