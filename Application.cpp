#pragma once

#include <iostream>
#include "Bank.cpp"
#include "SavingAccount.cpp"
#include "CheckingAccount.cpp"
#include "Login&Register.cpp"

using namespace std;

enum {
    ADDBANK = 1,
    DISPLAYBANK,
    UPDATEBANK,
    DELETEBANK,
    SORTBANK,
    SEARCHBANK,
    DEPOSIT,
    WITHDRAW,
    SAVEBANK,
    LOADBANK,
    LOGOUT

};

class Application {
 private:

Bank b;
BankAccount* account{};

    void bankMenu() {
        cout << "==========Bank Management Menu==========" << endl;
        cout << "1. Create bank account" << endl;
        cout << "2. View all bank account" << endl;
        cout << "3. Update a specific bank account" << endl;
        cout << "4. Delete a specific bank account" << endl;
        cout << "5. Sort bank account" << endl;
        cout << "6. Search for a specific bank account" << endl;
        cout << "7. Deposit a specific bank account" << endl;
        cout << "8. Withdraw a specific bank account" << endl;
        cout << "9. Save bank data" << endl;
        cout << "10. Log out" << endl;
    }

    void authenticationMenu(){
        cout <<"==========Bank Management System==========" << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
    }


    int getChoice() {
        int choice;

        cout << "Enter your choice(1-10)-> ";
        cin >> choice;
        return choice;

    }

    
 public:

 void bankManagement(){
    
        int choice = 0;
    int option = 0;

   
    do {
        bankMenu();
        choice = getChoice();

        switch (choice) {
            case ADDBANK: {
                cout << "1. SavingAccount" << endl;
                cout << "2. CheckingAccount" << endl;
                cout << "Choose your bank account(1-2)-> ";
                cin >> option;
                
                switch (option) {
                    case 1:{
                        auto savingAccount = make_unique<SavingAccount>();  
            savingAccount->input();
            b.addBank(savingAccount.release());                  
                        break;
                    }   
                    case 2:
                    {    
                       auto checkingAccount = make_unique<CheckingAccount>();
            checkingAccount->input();
            b.addBank(checkingAccount.release());
                        break;

                    }
                        
                    default:
                    cout << "Invalid Account type" << endl;
                    cout << "Press any key to contine..." << endl;
                    cin.ignore();
                    cin.get();
                    bankManagement();
                        break;
                }
                cout << "Bank account created successfully." << endl;
                break;
            }

            case DISPLAYBANK:
                b.viewBank();
                break;

            case UPDATEBANK: {
                b.updateBankAccount(account);
                break;
            }

            case DELETEBANK:
                b.deleteBankAccount(account);
                break;

            case SORTBANK:
                 b.sortBankAccount();
                break;

            case SEARCHBANK:
                b.searchBankAccount(account);
                break;
            case DEPOSIT:
                b.depositAccount();
                break;

            case WITHDRAW:
                b.withdrawAccount();
                break;

            case SAVEBANK:
                b.saveBankAccount();
                break;
            break;
            case LOGOUT:
                break;

            default:
                cout << "Invalid Choice, Try again" << endl;
                break;
            }    
        
        }while (choice != 10);
 }

    void run() {
     int choice = 0;
     Login log;


     do {
     
      authenticationMenu();
      choice = getChoice();
      switch (choice)
      {
      case 1:
        if(log.userLogin()==true){
               system("cls");
           b.loadBankAccount();
            bankManagement();
        }else{
            cout << "Login failed. Please try again." << endl;
        }
          break;
      case 2:
        log.userRegister();
      break;
      case 3:
      exit(1);
     
      default:
      cout << "Invalid choice. Please try again." << endl;
        break;
      }


     }while(choice != 0);
    }







};







