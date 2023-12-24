#pragma once
#include <iostream>
#include "BankAccount.cpp"
#include "DataInputValidation.cpp"
#include <iomanip>

using namespace std;

class SavingAccount : public BankAccount {
private:
double interest_rate;
public:
SavingAccount() : BankAccount() {
    interest_rate = 0;
}

SavingAccount(int account_number, string name, double balance, double interest_rate) : BankAccount(account_number, name, balance){
  setRate(interest_rate);
}

void setRate(const double interest_rate) {
    if(interest_rate>0){
        this->interest_rate = interest_rate;
    }else {
        throw BadInputException();
    }
}
double getRate() const{
    return interest_rate;
}

void input(){
    double rate;
    BankAccount::input();
    rate = val.input_interest();
    setRate(rate);
}

void output()override{
    cout << "Saving Account: " << endl;
    cout << "-------------------------------------------------------------------\n";
    cout << "Account number      Name        Balance            Interest rate \n";
    cout << "-------------------------------------------------------------------\n";
    BankAccount::output();
  cout << setw(18) << getRate() << endl;
}

};

