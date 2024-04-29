
#include<iostream>
using namespace std;

class BankAccount{
    int accountId;
    double balance;
    int* transactionHistory;
    int numTransactions;

public:
    BankAccount() {}

    BankAccount(int accountId, double balance, int numTransactions) {
        this->accountId = accountId;
        this->balance = balance;
        this->numTransactions = numTransactions;
        transactionHistory = new int[numTransactions];
        cout << "Enter the transaction history:\n";
        for (size_t i = 0; i < numTransactions; i++) {
            cout << "Enter Transaction number " << i + 1 << ": ";
            cin >> this->transactionHistory[i];
        }
    }

    BankAccount(const BankAccount &account) {
        this->accountId = account.accountId;
        this->balance = account.balance;
        this->numTransactions = account.numTransactions;
        this->transactionHistory = new int[numTransactions];
        
        for (int i = 0; i < numTransactions; i++) {
            this->transactionHistory[i] = account.transactionHistory[i];
        }
    }
    
    void display() {
        cout << "Account Id: " << accountId << endl
             << "Balance: " << balance << endl;

        for (size_t i = 0; i < numTransactions; i++) {
            cout << "Transaction number " << i + 1 << " is: " << transactionHistory[i] << endl;
        }   
        cout << endl; 
    }

    ~BankAccount() {
        delete[] transactionHistory;
    }

    void update() {
        delete[] transactionHistory;
        cout << "Enter the number of transactions: ";
        cin >> numTransactions;
        transactionHistory = new int[numTransactions];
        for (size_t i = 0; i < numTransactions; i++) {
            cout << "Enter Transaction number " << i + 1 << ": ";
            cin >> this->transactionHistory[i];
        }   
    }   
};

int main() {
    BankAccount obj1(1, 23.34, 3);
    BankAccount copy(obj1);

    cout << "------------- Main object -------------\n\n";
    obj1.display();
    cout << "------------- Copy object -------------\n\n";
    copy.display();
    
    return 0;
}
