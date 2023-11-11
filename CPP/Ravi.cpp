#include <iostream>
using namespace std;

class NegativeDepositException : public exception {
public:
    const char* what() const throw() {
        return "Cannot deposit a negative amount or zero.";
    }
};

class BankAccount {
private:
    double balance;

public:
    BankAccount() : balance(0) {}

    void deposit(double amount) {
        if (amount <= 0) {
            throw NegativeDepositException();
        }
        balance += amount;
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount account;

    try {
        double depositAmount;
        cin >> depositAmount;

        account.deposit(depositAmount);
        cout << "Deposit successful. Balance: " << account.getBalance() << endl;
    } catch (const NegativeDepositException& e) {
        cout << "Exception caught: Error: " << e.what() << endl;
    }

    return 0;
}
