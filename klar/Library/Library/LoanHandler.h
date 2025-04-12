#pragma once
#include <vector>
#include "Loan.h"
#include "Book.h"
#include "Film.h"
#include "Audiobook.h"


using namespace std;

class LoanHandler {
private:
    vector<Loan> loans;

public:
    LoanHandler();
    ~LoanHandler();


    void addLoan(const Loan& loan);
    void removeLoan(int loanId);

    void loadLoansFromFile();
    void  removeLoanFromFile(int loanId);
    void  saveLoanToFile(int loanId, Media* media);

    bool isMediaAlreadyLoaned(int mediaID)const;

    Loan* getLoanById(int loanId);
    string generateLoanDate();
};

