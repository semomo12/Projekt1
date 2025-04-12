#include <iostream>
#include "Library.h"
#include "InputHandler.h"
#include "MediaHandler.h"
#include "Menu.h"
#include "System.h"
using namespace std;


void System::start()
{

    Library library;
    InputHandler inputHandler;
    MediaHandler mediaHandler;

    Menu menu(library, inputHandler, mediaHandler);  // Skapar ett Menu-objekt

    bool running = true;
    while (running) {
        menu.showMainMenu(); 
        int choice = inputHandler.getInt("Choose from options (1-4) --> ", 1, 4);
        if (choice == 4)
        {
            running = false;

            system("cls");

        }
        menu.handleChoice(choice);

    }

};

