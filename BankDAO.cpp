#include <iostream>
#include "BankAccount.cpp"
using namespace std;

class BankDAO {
public:
virtual void addBank(BankAccount* account) = 0;
virtual void viewBank() = 0;
virtual void updateBankAccount(BankAccount* account) = 0;
virtual void deleteBankAccount(BankAccount* account) = 0;
virtual void sortBankAccount() = 0;
virtual void searchBankAccount(BankAccount* account) = 0;
virtual void depositAccount() = 0;
virtual void withdrawAccount() = 0;
virtual void saveBankAccount() = 0;
virtual void loadBankAccount() = 0;
};