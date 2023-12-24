#pragma once
#include <iostream>
#include "BankAccount.cpp"
#include "DataInputValidation.cpp"
#include <iomanip>
using namespace std;

class CheckingAccount : public BankAccount {
private:
double transaction_fee;
public:
CheckingAccount() : BankAccount() {
    transaction_fee = 0;
}

CheckingAccount(int account_number, string name, double balance, double transaction_fee) : BankAccount(account_number, name, balance){
  setFee(transaction_fee);
}

void setFee(const double transaction_fee) {
    if(transaction_fee>0){
        this->transaction_fee = transaction_fee;
    }else {
        throw BadInputException();
    }
}
double getFee() const{
    return transaction_fee;
}

void input(){
    double fee;
    BankAccount::input();
    fee = val.input_Fee();
    setFee(fee);
}

void output() override{
    cout << "Checking Account: " << endl;
    cout << "-------------------------------------------------------------------\n";
    cout << "Account number      Name        Balance            Transaction fee \n";
    cout << "-------------------------------------------------------------------\n";
    BankAccount::output();
  cout << setw(18) << getFee() << endl;
}
};