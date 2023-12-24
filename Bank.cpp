#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "BankAccount.cpp"
#include "SavingAccount.cpp"
#include "CheckingAccount.cpp"
#include "BankDAO.cpp"
#include <algorithm>
#include <chrono>
#include <thread>
using namespace std;

enum {
    FINDNUM =1, FINDNAME
};

enum {
 SORTNUM =1, SORTNAME
};

class Bank : public BankDAO{
private:
 vector<BankAccount*> bankAcc;
 public:

 ~Bank(){
    for (auto& account : bankAcc) {
            delete account;
        }
 }
 
 void addBank(BankAccount* bAcc){
    bankAcc.push_back(bAcc);
 }


void viewBank() {
    for (const auto& it : bankAcc) {
        try {
            it->output();
            cout << endl;
        } catch (const std::exception& e) {
            cerr << "Exception: " << e.what() << endl;
        }
    }

    cout << "Press any key to continue...";
    cin.ignore();
    cin.get();
}






void updateBankAccount(BankAccount* account) {
    int choice;
    cout << "==========FIND MENU==========" << endl;
        cout << "1. Find by account number" << endl;
        cout << "2. Find by name" << endl;
        cout << "3. Back to main menu" << endl;
        cout << "Enter choice(1-3)-> ";
        cin>> choice;
        switch (choice)
        {
        case FINDNUM:{
            char performChoice;
            

               int accountNumber;
            cout << "Enter account number: ";
            cin >> accountNumber;
            auto it = find_if(bankAcc.begin(),bankAcc.end(),
            [accountNumber](const BankAccount* account) { return account->getNum() == accountNumber; });
            do{
                 if(it != bankAcc.end()){
                int choice;
                
                    cout << "==========EDIT MENU==========" << endl;
                cout << "1.	Account number" << endl;
                cout << "2.	Name" << endl;
                cout << "3.	Transaction/Interest" << endl;
                cout << "4. Back" << endl;
                cout << "Enter choice(1-3)-> ";
                cin >> choice;
                switch (choice)
                {
                case 1:{
                  int new_num;                    
                cout << "Enter new account number: ";
                cin >> new_num;
                              
                 account->setNum(new_num);
                cout << "Account number changed successfully" << endl;

                }
                 
                    break;
                case 2:{
                    string new_name;                    
                    cout << "Enter new name: ";
                    cin >> new_name;
                              
                  account->setName(new_name);
                  cout << "Name changed successfully" << endl;
                }

                break;
                case 3:
                    if (typeid(*account) == typeid(SavingAccount)) {
        
                        double newInterestRate;
                        cout << "Enter new interest rate: ";
                        cin >> newInterestRate;
                       dynamic_cast<SavingAccount*>(account)->setRate(newInterestRate);
                           cout << "Transaction interest updated successfully.\n";
                   } else if (typeid(*account) == typeid(CheckingAccount)) {
        
                       double newTransactionFee;
                       cout << "Enter new transaction fee: ";
                        cin >> newTransactionFee;
                        dynamic_cast<CheckingAccount*>(account)->setFee(newTransactionFee);
                        cout << "Transaction fee updated successfully.\n";
                    } else {
                        // Unknown account type
                        cout << "Error: Unknown account type.\n";
                    } 
                break;
                case 4: //break out to main menu
                break;

                default:
                cout << "Invalid Choice. Please try again" << endl;
                    break;
                }
              }else {
                cout << "Account is not found" << endl;
                cout << "Do you want to continue? (y/n) ->";
                cin >> performChoice;
             }
            }while(performChoice == 'y' || performChoice == 'Y');
            

            
                
            
        }
                    
            break;
        case FINDNAME:{
            char performChoice;
            do{
                string name;
          cout << "Enter name: ";
          cin >> name;
          auto it = find_if(bankAcc.begin(), bankAcc.end(),
            [name](const BankAccount* account) { return account->getName() == name; });
            if(it != bankAcc.end()){
                    int choice;
                cout << "==========EDIT MENU==========" << endl;
                cout << "1.	Account number" << endl;
                cout << "2.	Name" << endl;
                cout << "3.	Transaction/Interest" << endl;
                cout << "4. Back" << endl;
                cout << "Enter choice(1-3)-> ";
                cin >> choice;
                switch (choice)
                {
                case 1:{
                  int new_num;                    
                cout << "Enter new account number: ";
                cin >> new_num;
                              
                 account->setNum(new_num);
                cout << "Account number changed successfully" << endl;
                }
                 
                    break;
                case 2:{
                    string new_name;                    
                    cout << "Enter new name: ";
                    cin >> new_name;
                              
                  account->setName(new_name);
                  cout << "Name changed successfully" << endl;
                }

                break;
                case 3:
                    if (typeid(*account) == typeid(SavingAccount)) {
        
                        double newInterestRate;
                        cout << "Enter new interest rate: ";
                        cin >> newInterestRate;
                       dynamic_cast<SavingAccount*>(account)->setRate(newInterestRate);
                           cout << "Interest fee updated successfully.\n";
                   } else if (typeid(*account) == typeid(CheckingAccount)) {
        
                       double newTransactionFee;
                       cout << "Enter new transaction fee: ";
                        cin >> newTransactionFee;
                        dynamic_cast<CheckingAccount*>(account)->setFee(newTransactionFee);
                        cout << "Transaction fee updated successfully.\n";
                    } else {
                        // Unknown account type
                        cout << "Error: Unknown account type.\n";
                    } 
                break;
                case 4: //break out to main menu
                break;

                default:
                cout << "Invalid Choice. Please try again" << endl;
                    break;
                }
            }else {
                cout << "Account not found" << endl;
                cout << "Do you want to continue? (y/n) -> ";
                cin >> performChoice; 
            }
            }while(performChoice == 'y' || performChoice == 'Y');
            
        }
          
         break;
        default:
        cout << "Invalid choice." << endl;
        cout << "Press any key to continue...";
        cin.ignore();
        cin.get();
            break;
        }


}


void deleteBankAccount(BankAccount* account) {
    int choice;
    cout << "==========FIND MENU==========" << endl;
        cout << "1. Find by account number" << endl;
        cout << "2. Find by name" << endl;
        cout << "3. Back to main menu" << endl;
        cout << "Enter choice(1-3)-> ";
        cin>> choice;
        switch(choice){
            case FINDNUM: {
            int accountNumber;
            cout << "Enter account number: ";
            cin >> accountNumber;
            auto it = find_if(bankAcc.begin(),bankAcc.end(),
            [accountNumber](const BankAccount* account) { return account->getNum() == accountNumber; });
            if(it != bankAcc.end()){
              // Display the information before deletion
            cout << "Account information to be deleted:\n";
            account->output();

            // Confirm deletion
            cout << "Do you want to delete this account? (y/n): ";
            char choice;
            cin >> choice;

            if (choice == 'y' || choice == 'Y') {
                // Perform deletion
                auto iter = find(bankAcc.begin(), bankAcc.end(), account);
                bankAcc.erase(iter);
                cout << "Account deleted successfully.\n";

            } else {
                cout << "Deletion canceled.\n";

            }
            }else {
                cout << "Bank info not found" << endl;
            cout << "Press any key to continue..." << endl;
            cin.ignore();
            cin.get();
            }

                
            }

            break;
            case FINDNAME:{
                string name;
            cout << "Enter name: ";
            cin >> name;
            auto it = find_if(bankAcc.begin(),bankAcc.end(),
            [name](const BankAccount* account) { return account->getName() == name; });
            if(it != bankAcc.end()){
              // Display the information before deletion
            cout << "Account information to be deleted:\n";
            account->output();

            // Confirm deletion
            cout << "Do you want to delete this account? (y/n): ";
            char choice;
            cin >> choice;

            if (choice == 'y' || choice == 'Y') {
                // Perform deletion
                auto iter = find(bankAcc.begin(), bankAcc.end(), account);
                bankAcc.erase(iter);
                cout << "Account deleted successfully.\n";

            } else {
                cout << "Deletion canceled.\n";

            }
            }else {
                cout << "Bank info not found" << endl;
            cout << "Press any key to continue..." << endl;
            cin.ignore();
            cin.get();
            }
            }

            break;

            case 3:
            break;

            default:
            cout << "Invalid choice." << endl;
            cout << "Press any key to continue...";
            cin.ignore();
            cin.get();
            break;
        }
}

void sortBankAccount() {
    int choice;
    cout << "==========EDIT MENU==========" << endl;
        cout << "1. Sort by account number" << endl;
        cout << "2. Sort by name" << endl;
        cout << "3. Back to main menu" << endl;
        cout << "Enter choice(1-3)-> ";
        cin >> choice;
        switch (choice)
        {
        case SORTNUM:{
            int choice;
            cout << "==========EDIT METHOD==========" << endl;
        cout << "1. Sort by Ascending" << endl;
        cout << "2. Sort by Descending" << endl;
        cout << "3. Back to main menu" << endl;
        cout << "Enter choice(1-3) -> ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            sort(bankAcc.begin(), bankAcc.end(), [](const BankAccount* a, const BankAccount* b) {
                return a->getNum() < b->getNum();                
                });    
                cout << "Sorting";
                   DotDotDot();
                   cout << "Sorted successfully" << endl;
                   cout << "Press any key to continue..." << endl;
                   cin.ignore();
                   cin.get(); 
            break;
        case 2:
            sort(bankAcc.begin(), bankAcc.end(), [](const BankAccount* a, const BankAccount* b) {
                return a->getNum() > b->getNum();
                });
                cout << "Sorting";
                   DotDotDot();
                   cout << "Sorted successfully" << endl;
                   cout << "Press any key to continue..." << endl;
                   cin.ignore();
                   cin.get();  
        break;
        default:
        cout << "Invalid choice." << endl;
        cout << "Press any key to continue..." << endl;
        cin.ignore();
        cin.get();      
        break;
        }

        }
            break;
        case SORTNAME:{
            int choice;
            cout << "==========EDIT METHOD==========" << endl;
        cout << "1. Sort by Ascending" << endl;
        cout << "2. Sort by Descending" << endl;
        cout << "3. Back to main menu" << endl;
        cout << "Enter choice(1-3) -> ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            sort(bankAcc.begin(), bankAcc.end(), [](const BankAccount* a, const BankAccount* b) {
                return a->getName() < b->getName();                
                });    
                cout << "Sorting";
                   DotDotDot();
                   cout << "Sorted successfully" << endl;
                   cout << "Press any key to continue..." << endl;
                   cin.ignore();
                   cin.get(); 
            break;
        case 2:
            sort(bankAcc.begin(), bankAcc.end(), [](const BankAccount* a, const BankAccount* b) {
                return a->getName() > b->getName();
                });
                cout << "Sorting";
                   DotDotDot();
                   cout << "Sorted successfully" << endl;
                   cout << "Press any key to continue..." << endl;
                   cin.ignore();
                   cin.get();  
        break;
        default:
        cout << "Invalid choice." << endl;
        cout << "Press any key to continue..." << endl;
        cin.ignore();
        cin.get();      
        break;
        }
        }
        default:
        cout << "Invalid choice." << endl;
        cout << "Press any key to continue..." << endl;
        cin.ignore();
        cin.get();
            break;
        }
}

void searchBankAccount(BankAccount * account){
    int choice;
    cout << "==========FIND MENU==========" << endl;
        cout << "1. Find by account number" << endl;
        cout << "2. Find by name" << endl;
        cout << "3. Back to main menu" << endl;
        cout << "Enter choice(1-3)-> ";
        cin>> choice;;
        switch (choice)
        {
        case FINDNUM:{
            int accountNumber;
            cout << "Enter account number: ";
            cin >> accountNumber;
            auto it = find_if(bankAcc.begin(),bankAcc.end(),
            [accountNumber](const BankAccount* account) { return account->getNum() == accountNumber; });
            if(it != bankAcc.end()){
             cout << "Account found:\n";
                account->output();  // Output the details of the found account
              cout <<  "Press any key to continue...";
              cin.ignore();
              cin.get();
            }else {
                cout << "Bank info not found" << endl;
                cout << "Press any key to continue..." << endl;
                cin.ignore();
                cin.get();
            }
        
        }
            break;
        case FINDNAME:{
            string name;
            cout << "Enter name: ";
            cin >> name;
            auto it = find_if(bankAcc.begin(),bankAcc.end(),
            [name](const BankAccount* account) { return account->getName() == name; });
            if(it != bankAcc.end()){
             cout << "Account found:\n";
                account->output();  // Output the details of the found account
              cout <<  "Press any key to continue...";
              cin.ignore();
              cin.get();
            }else {
                cout << "Bank info not found" << endl;
                cout << "Press any key to continue..." << endl;
                cin.ignore();
                cin.get();
            }
        
        }
        default:
        cout << "Invalid choice." << endl;
        cout << "Press any key to continue..." << endl;
        cin.ignore();
        cin.get();
            break;
        
        }
}        

    void depositAccount() {
        int accountNumber;
        double amount;

        std::cout << "Enter account number to deposit into: ";
        std::cin >> accountNumber;

        auto it = std::find_if(bankAcc.begin(), bankAcc.end(), [accountNumber](const BankAccount* account) {
            return account->getNum() == accountNumber;
            });

        if (it != bankAcc.end()) {
            std::cout << "Enter deposit amount: ";
            std::cin >> amount;

            if (amount > 0) {
                (*it)->setBalance((*it)->getBalance() + amount);
                std::cout << "Deposit successful. New balance: " << (*it)->getBalance() << std::endl;
            }
            else {
                std::cout << "Invalid deposit amount. Please enter a positive value." << std::endl;
            }
        }
        else {
            std::cout << "Account not found." << std::endl;
        }
    }

    void withdrawAccount() {
        int accountNumber;
        double amount;

        std::cout << "Enter account number to withdraw from: ";
        std::cin >> accountNumber;

        auto it = std::find_if(bankAcc.begin(), bankAcc.end(), [accountNumber](const BankAccount* account) {
            return account->getNum() == accountNumber;
            });

        if (it != bankAcc.end()) {
            std::cout << "Enter withdrawal amount: ";
            std::cin >> amount;

            if (amount > 0 && amount <= (*it)->getBalance()) {
                (*it)->setBalance((*it)->getBalance() - amount);
                std::cout << "Withdrawal successful. New balance: " << (*it)->getBalance() << std::endl;
            }
            else if (amount <= 0) {
                std::cout << "Invalid withdrawal amount. Please enter a positive value." << std::endl;
            }
            else {
                std::cout << "Insufficient funds. Withdrawal not allowed." << std::endl;
            }
        }
        else {
            std::cout << "Account not found." << std::endl;
        }
    }

void saveBankAccount() {
    ofstream outputFile("Bank.dat", ios::out | ios::binary);

    if (!outputFile.is_open()) {
        cout << "Error in creating file...\n";
        exit(1);
    } else {
        for (const auto& accountPtr : bankAcc) {
            outputFile.write(reinterpret_cast<char*>(accountPtr), sizeof(BankAccount));
        }

        cout << "File saved successfully" << endl;
    }

    outputFile.close();
}


void loadBankAccount() {
    ifstream inputFile("Bank.dat", ios::in | ios::binary);

    if (!inputFile.is_open()) {
        cout << "Error in opening file...\n";
        exit(1);
    }

    try {
        while (true) {
            BankAccount* account = new BankAccount();
            if (!inputFile.read(reinterpret_cast<char*>(account), sizeof(BankAccount))) {
                // Reached end of file
                delete account;  // Clean up the dynamically allocated memory
                break;
            }

            addBank(account);
            cout << "File loaded successfully" << endl;
        }
    } catch (const std::exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    inputFile.close();
}


    void DotDotDot() {
    for (int i = 0; i < 5; i++) {
        cout << ".";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(500));
    }

}
 


};