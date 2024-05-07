#include <iostream>
using namespace std;

class Account {
protected:
    int accountNumber;
    double balance;

public:
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual void calculateInterest() = 0;

    int getAccountNumber() {
        return accountNumber;
    }

    double getBalance() {
        return balance;
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(int accNumber, double initialBalance, double rate) {
        accountNumber = accNumber;
        balance = initialBalance;
        interestRate = rate;
    }

    void deposit(double amount) override {
        balance += amount;
    }

    void withdraw(double amount) override {
        if (balance >= amount)
            balance -= amount;
        else
            cout << "Insufficient funds!" <<endl;
    }

    void calculateInterest() override {
        double interest = balance * (interestRate / 100);
        balance += interest;
    }
};

class CurrentAccount : public Account {
private:
    double overdraftLimit;

public:
    CurrentAccount(int accNumber, double initialBalance, double limit) {
        accountNumber = accNumber;
        balance = initialBalance;
        overdraftLimit = limit;
    }

    void deposit(double amount) override {
        balance += amount;
    }

    void withdraw(double amount) override {
        if (balance + overdraftLimit >= amount)
            balance -= amount;
        else
            cout << "Transaction exceeds overdraft limit!" <<endl;
    }

    void calculateInterest() override {
        cout << "No interest is calculated for current accounts." <<endl;
    }
};

int main() {
    SavingsAccount savings(12345, 1000.0, 5.0);
    CurrentAccount current(54321, 500.0, 200.0);

    savings.deposit(500);
    current.deposit(200);
    savings.withdraw(200);
    current.withdraw(700);

    savings.calculateInterest();
    current.calculateInterest();

    cout << "Savings Account: " << savings.getAccountNumber() << ", Balance: $" << savings.getBalance() <<endl;
    cout << "Current Account: " << current.getAccountNumber() << ", Balance: $" << current.getBalance() <<endl;

    return 0;
}
