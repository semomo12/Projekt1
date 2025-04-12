#include "FileHandler.h"
#include <iostream>
#include <fstream>
#include <sstream>

FileHandler::FileHandler() {}

FileHandler::~FileHandler() {}


vector<Media*> FileHandler::loadMediaFromFile(const string& filename, const string& type) {
    vector<Media*> mediaList;
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Could not open file: " << filename << endl;
        return mediaList;
    }

    string line;
    getline(file, line);
    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        stringstream ss(line);
        string idStr, name, creator, yearStr;

        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, creator, ',');
        getline(ss, yearStr, ',');
        name = trim(name);
        creator = trim(creator);

        try {
            int id = stoi(idStr);
            int year = stoi(yearStr);

            if (type == "Book") {
                mediaList.push_back(new Book(creator, type, id, year, name));
            }
            else if (type == "Audiobook") {
                mediaList.push_back(new Audiobook(creator,type, id, year, name));
            }
            else if (type == "Movie") {
                mediaList.push_back(new Film(creator, type, id, year, name));
            }
        }
        catch (const exception& ) {
            cerr << " WARNING: Invalid data in file " << filename << ": " << line << endl;
        }
    }
    file.close();
    return mediaList;
}




string FileHandler::trim(const string& str)
{
    string result = str;

    // Ta bort mellanslag i början
    while (!result.empty() && isspace(result.front())) {
        result.erase(result.begin());
    }

    // Ta bort mellanslag i slutet
    while (!result.empty() && isspace(result.back())) {
        result.pop_back();
    }

    return result;
}
string FileHandler::removeSpaces(const string& str)
{
    string result;
    for (char c : str) {
        if (!isspace(c)) {
            result += c;
        }
    }
    return result;

}
