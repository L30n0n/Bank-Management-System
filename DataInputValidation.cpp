#pragma once
#include <iostream>

using namespace std;

class DataInputValidation {
private:
bool validate_num(int num){
    if(cin.fail() || num > 1000){
        return false;
    }
    return true;
}

bool validate_doublenum(double num){
    if(cin.fail() || num > 1000){
        return false;
    }
    return true;
}

bool validate_name(string name){
    if (name.length() > 10) {
        return false;
  }

    for(int i = 0;i<name.length();i++){
        if(!(name[i] >= 65 && name[i] <= 122)) {
            return false;
        }
    }
    return true;
}
public:

int input_Accountnum(){
    int num;
    while(true){
        cout << "Enter account number: ";
        cin>>num;
        if(!validate_num(num)){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: Invalid Input" << endl;
        }else{
            return num;
        }
    }
}

double input_balance(){
    double balance;
    while(true){
        cout << "Enter balance: ";
        cin>>balance;
        if(!validate_doublenum(balance)){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: Invalid Input" << endl;
        }else{
            return balance;
        }
    }
}

string input_name(){
    string name;
    while (true)
    {
       cout << "Enter name: ";
       cin>> name;
       if(!validate_name(name)){
        cout << "Error: Invalid/max letter reached" << endl;
       }else{
        return name;
       }
    }
    
}

double input_Fee(){
    double Fee;
    while(true){
        cout << "Enter transaction fee: ";
        cin>>Fee;
        if(!validate_doublenum(Fee)){
            cin.clear();
            cin.ignore(100000, '\n');
            cout << "Error: Invalid Input" << endl;
        }else{
            return Fee;
        }
    }
}

double input_interest(){
    double interest;
    while(true){
        cout << "Enter interest rate: ";
        cin>>interest;
        if(!validate_doublenum(interest)){
            cin.clear();
            cin.ignore(100000, '\n');
            cout << "Error: Invalid Input" << endl;
        }else{
            return interest;
        }
    }
}

};
