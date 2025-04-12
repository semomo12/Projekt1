#pragma once
#include "FileHandler.h"
#include "Media.h"
#include <vector>
#include <string>

using namespace std;

class MediaHandler {
private:
    vector<Media*> mediaList;

    FileHandler fileHandler;
    Media* media;

public:
    MediaHandler();
    ~MediaHandler();

    void loadMedia();  
    void removeMedia(int mediaId);

    void showAvailableMedia(const string& type);
    void viewAllMedia(const string & type);

    Media* getMediaById(int mediaId);
};
