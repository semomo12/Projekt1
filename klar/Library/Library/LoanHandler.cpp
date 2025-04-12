#include "LoanHandler.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

LoanHandler::LoanHandler()
{
}

LoanHandler::~LoanHandler()
{

}

void LoanHandler::addLoan(const Loan& loan) {
    loans.push_back(loan);
}

Loan* LoanHandler::getLoanById(int loanId) {
    for (auto& loan : loans) {
        if (loan.getLoanId() == loanId) {
            return &loan;
        }
    }
    return nullptr;
}

void LoanHandler::removeLoan(int loanId) {
    for (auto it = loans.begin(); it != loans.end(); ++it) {
        if (it->getLoanId() == loanId) {
            loans.erase(it);
            break;
        }
    }
}

void LoanHandler::loadLoansFromFile() {
    ifstream loanFile("loans.txt");
    if (!loanFile.is_open()) {
        cout << "Error: Unable to open loans.txt file.\n";
        return;
    }

    string line;
    bool isFirstLine = true;
    while (getline(loanFile, line)) {
        if (isFirstLine) {
            isFirstLine = false;
            continue;  
        }
        if (line.empty()) {
            continue;
        }

        stringstream ss(line);
        int loanId = 0;
        int personId = 0;
        int mediaId = 0;
        string loanDate, mediaName;

        if (getline(ss, line, ',')) loanId = stoi(line);
        if (getline(ss, line, ',')) personId = stoi(line);
        if (getline(ss, line, ',')) mediaId = stoi(line);
        if (getline(ss, line, ',')) loanDate = line;
        if (getline(ss, line, ',')) mediaName = line;
   
        Loan loan(loanId, mediaId, loanDate, mediaName);
        addLoan(loan);
    }

    loanFile.close();
}

void LoanHandler::removeLoanFromFile(int loanId)
{
    ifstream inputFile("loans.txt");
        ofstream tempFile("temp.txt");
    
        if (!inputFile.is_open()) {
            cout << "Error: Could not open loans.txt for reading.\n";
            return;
        }
        if (!tempFile.is_open()) {
            cout << "Error: Could not open temp.txt for writing.\n";
            return;
        }
    
        string line;
        bool isFirstLine = true;
        while (getline(inputFile, line)) {
            if (isFirstLine) {
                isFirstLine = false;
                tempFile << line << "\n";
                continue; 
            }
            if (line.empty()) {
                continue; // Hoppa över tomma rader
            }
            stringstream ss(line);
            string idStr;
            getline(ss, idStr, ',');
    
            try {
                int loanIdFromFile = stoi(idStr);
                if (loanIdFromFile != loanId) {
                    tempFile << line << "\n"; 
                }
            }
            catch (const invalid_argument& ) {
                cout << "Error: Invalid loanId in file.\n";
                continue; 
            }
        }
    
        inputFile.close();
        tempFile.close();
    
        // Radera den ursprungliga filen och byta namn på den tillfälliga filen
        if (remove("loans.txt") != 0) {
            cout << "Error: Could not remove the original loan file.\n";
            return;
        }
    
        if (rename("temp.txt", "loans.txt") != 0) {
            cout << "Error: Could not rename the temporary file.\n";
            return;
        }
    
}

void LoanHandler::saveLoanToFile(int loanId, Media* media)
{
        
    int personID = loanId;
    if (personID <= 0) {
        cout << "Error: Invalid Person ID (" << personID << ") for Loan ID: " << loanId << ". Loan will not be saved.\n";
        return;
    }
     Loan* loan = getLoanById(loanId);
    ofstream file("loans.txt", ios::app);
    if (file.is_open()) {
        file << loanId << ","
            << personID << ","
            << loan->getMediaId() << ","
            << loan->getLoanDate()<< ","
            << media->getMediaName() << ",";
        if (auto* book = dynamic_cast<Book*>(media)) {
            file << book->getAuthor() << ",";
        }
        else if (auto* audiobook = dynamic_cast<Audiobook*>(media)) {
            file << audiobook->getNarrator() << ",";
        }
        else if (auto* film = dynamic_cast<Film*>(media)) {
            file << film->getDirector() << ",";
        }
            file<< media->getYear() << ",";
            file<< media->getMediaType() << endl;
            file.close();
    }
    else {
        cout << "Error: Could not open loan file for writing.\n";
    }
}

bool LoanHandler::isMediaAlreadyLoaned(int mediaID)const
{
    for (const auto& loan : loans) {
        if (loan.getMediaId() == mediaID) {
            return true;
        }
    }
    return false;
}

string LoanHandler::generateLoanDate()
{
    time_t now = time(0);
    tm localTime;
    localtime_s(&localTime, &now);

    string currentDate = to_string(1900 + localTime.tm_year) + "-" +
        to_string(1 + localTime.tm_mon) + "-" +
        to_string(localTime.tm_mday);

    now += 14 * 86400;
    localtime_s(&localTime, &now);

    // Skapa datumformatet: YYYY-MM-DD för datumet om 14 dagar
    string futureDate = to_string(1900 + localTime.tm_year) + "-" +
        to_string(1 + localTime.tm_mon) + "-" +
        to_string(localTime.tm_mday);

    return currentDate + " - " + futureDate;
}
