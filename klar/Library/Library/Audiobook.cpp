#include "Audiobook.h"
#include <iostream>

using namespace std;

Audiobook::Audiobook(string narrator , string mediaType, int mediaId , int year , string mediaName )
	:Media("Audiobook", mediaId, year, mediaName), narrator(narrator)
{
}

Audiobook::~Audiobook()
{
}

string Audiobook::getNarrator()const
{
    return this->narrator;
}

string Audiobook::getInfo() const
{
	return Media::getInfo() + " | Narrator: " + getNarrator();
}
