#include "Menu.h"

using namespace std;

Menu::Menu(Library& lib, InputHandler& input, MediaHandler& media)
    : library(lib), inputHandler(input), mediaHandler(media) {
}

void Menu::showMainMenu() {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << " Welcome to the Library!" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
    cout << "1. Borrow media" << endl;
    cout << "2. Return media" << endl;
    cout << "3. View library" << endl;
    cout << "4. Exit\n" << endl;

}

void Menu::handleChoice(int choice) {
    switch (choice) {
    case 1:
        system("cls");
        borrowMedia();
        break;
    case 2:
        system("cls");
        returnMedia();
        break;
    case 3:
        system("cls");
        viewLibrary();
        break;
    case 4:
        system("cls");
        cout << "Thank you for using the library! \n";
        break;
        cin.ignore();
        cin.get();
    }
}

void Menu::borrowMedia() {
    cout << "--- Borrow Media ---\n";
    cout << "Select the type of media you want to borrow:\n";
    cout << "1. Book\n2. Audiobook\n3. Movie\n4. Main menu\n";

    int mediaChoice = inputHandler.getInt("Enter your choice (1-4): ", 1, 4);
    if (mediaChoice == 4) {
        return;  // Go back to main menu
    }
    system("cls");
    string mediaType;
    switch (mediaChoice) {
    case 1: mediaType = "Book"; break;
    case 2: mediaType = "Audiobook"; break;
    case 3: mediaType = "Movie"; break;

    }
    library.borrowMedia(mediaType);
}

void Menu::returnMedia() {
    cout << "--- Return Media ---\n";
    cout << "Enter 0 to return to the main menu\n";
    int loanId = inputHandler.getInt("Enter the loan ID for return: ");
    if (loanId != 0) {
        library.returnMedia(loanId);
    }
}

void Menu::viewLibrary() {
    cout << "--- Available media to borrow ---\n";
    cout << "1. Book\n2. Audiobook\n3. Movie\n4. Main menu\n";
    int mediaChoice = inputHandler.getInt("Enter your choice (1-4): ", 1, 4);
    if (mediaChoice == 4) {
        return;  // Go back to main menu
    }

    string mediaType;
    switch (mediaChoice) {
    case 1: mediaType = "Book"; break;
    case 2: mediaType = "Audiobook"; break;
    case 3: mediaType = "Movie"; break;
    }
    mediaHandler.viewAllMedia(mediaType);
}
