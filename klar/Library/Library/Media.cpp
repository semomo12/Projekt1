#include "Media.h"
#include <iostream>

Media::Media(string mediaType, int mediaId, int year, string mediaName)
	: mediaType(mediaType), mediaId(mediaId), year(year), mediaName(mediaName)
{
}

Media::~Media()
{
}

string Media::getInfo() const
{
	return "Media: " + this->getMediaType()+ " | ID : " + to_string(this->getMediaId()) + " | Name: " + this->getMediaName()  +
		"| year of publication: " + to_string(this->getYear());
}


int Media::getMediaId() const
{
	return this->mediaId;
}

int Media::getYear() const
{
	return this->year;
}

string Media::getMediaName() const
{
	return this->mediaName;
}

string Media::getMediaType() const
{
	return this->mediaType;
}
