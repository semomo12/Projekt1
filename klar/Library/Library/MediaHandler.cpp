#include "MediaHandler.h"
#include <iostream>

MediaHandler::MediaHandler() : media(nullptr)
{

}

MediaHandler::~MediaHandler() {
    for (auto& media : mediaList) {
        if (media) {
            delete media;
            media = nullptr;
        }
    }
    mediaList.clear();

    if (media) {
        delete media;
        media = nullptr;  
    }

}

void MediaHandler::loadMedia() {
    for (auto* media : mediaList) {
        delete media;
    }
    mediaList.clear();

    vector<Media*> books = fileHandler.loadMediaFromFile("book.txt", "Book");
    vector<Media*> audiobooks = fileHandler.loadMediaFromFile("audioBook.txt", "Audiobook");
    vector<Media*> films = fileHandler.loadMediaFromFile("film.txt", "Movie");

    //kopierar alla element från books och lägger till dem i slutet av mediaList.
    mediaList.insert(mediaList.end(), books.begin(), books.end());
    mediaList.insert(mediaList.end(), audiobooks.begin(), audiobooks.end());
    mediaList.insert(mediaList.end(), films.begin(), films.end());

}


void MediaHandler::removeMedia(int mediaId)
{
    bool removed = false;
    auto it = mediaList.begin();
    while (it != mediaList.end()) {
        if ((*it)->getMediaId() == mediaId) {
            delete* it;  
            it = mediaList.erase(it);  
            removed = true;
            break;  
        }
        else {
            ++it;
        }
    }

}


void MediaHandler::showAvailableMedia(const string& type) {
    bool found = false;
    for (auto* media : mediaList) {
        if (media->getMediaType() == type) {
            cout << media->getInfo() << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No media of the type available: " << type << endl;
    }
}

void MediaHandler::viewAllMedia(const string& type)
{
    loadMedia();
    showAvailableMedia(type);
}


Media* MediaHandler::getMediaById(int mediaId) {
    for (auto* media : mediaList) {
        if (media->getMediaId() == mediaId) {
            return media;
        }
    }
    return nullptr;
}