#pragma once
#include <iostream>
#include <iomanip>
#include "DataInputValidation.cpp"
#include "BadInputException.cpp"
using namespace std;

class BankAccount {
protected:
int account_number;
string name;
double balance;
DataInputValidation val;

public:
BankAccount() {
    account_number = 0;
    name = "unknown";
    balance = 0;
}

BankAccount(int account_number, string name, double balance){
  setNum(account_number);
  setName(name);
  setBalance(balance);
}



void setNum(const int account_number){
    if(account_number>0){
        this->account_number = account_number;
    }else{
        throw BadInputException();
    }
}
int getNum() const{
    return account_number;
}

void setName(const string name){
    if(!name.empty()){
        this->name = name;
    }else{
        throw BadInputException();
    }
}
string getName() const{
    return this->name;
}

void setBalance(const double balance){
    if(balance>0){
        this->balance = balance;
    }else{
        throw BadInputException();
    }
}
double getBalance() const{
    return balance;
}

  virtual void output(){
    
    cout << setw(8) << getNum() << setw(16) << getName() << setw(13) << getBalance();
  }
  
  virtual void input(){
    int number;
    string name;
    double balance;

    number = val.input_Accountnum();
    setNum(number);

    name = val.input_name();
    setName(name);

    balance = val.input_balance();
    setBalance(balance);

  }


};