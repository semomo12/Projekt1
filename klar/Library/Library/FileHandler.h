#pragma once
#include "Media.h"
#include "Book.h"
#include "Film.h"
#include "Audiobook.h"
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

class FileHandler {
public:
    FileHandler();
    ~FileHandler();

    vector<Media*> loadMediaFromFile(const string& filename, const string& type);
   
    string trim(const string& str);
    string removeSpaces(const std::string& str);
};

