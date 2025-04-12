#pragma once
#include "Library.h"
#include "InputHandler.h"
#include "MediaHandler.h"
#include <iostream>
using namespace std;
class Menu {

private:
    Library& library;
    InputHandler& inputHandler;
    MediaHandler& mediaHandler;

    void borrowMedia();
    void returnMedia();
    void viewLibrary();

public:
    Menu(Library& library, InputHandler& inputHandler, MediaHandler& mediaHandler);

    void showMainMenu();
    void handleChoice(int choice);


};
