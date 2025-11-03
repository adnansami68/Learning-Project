#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
using namespace std;

class SSL_C {
protected:
    float amount{};
    float balance{};
    float serviceCharge{};
    string dateTime;

public:
    void setAmount(float x) { amount = x; }
    void setBalance(float x) { balance = x; }

    void setDateTime() {
        time_t now = time(nullptr);
        dateTime = ctime(&now);
        dateTime.pop_back();
    }

    void showTransaction() const {
        cout << "\nTransaction Details\n";
        cout << "-------------------------------------\n";
        cout << fixed << setprecision(2);
        cout << "Amount Paid       : " << amount << " Tk\n";
        cout << "Service Charge    : " << serviceCharge << " Tk\n";
        cout << "Remaining Balance : " << balance << " Tk\n";
        cout << "Transaction Time  : " << dateTime << "\n";
        cout << "---------------------------------------------\n";
    }
};

// ========== bKash ==========
class Bkash_Pay : public SSL_C {
public:
    void makePayment(float amount, float balance) {
        setAmount(amount);
        setBalance(balance);
        setDateTime();

        serviceCharge = amount * 0.03;
        float total = amount + serviceCharge;

        cout << "\n------ Processing bKash Payment ------\n";
        if (balance >= total) {
            this->balance -= total;
            cout << "bKash Payment Successful!\n";
            cout << "Total Deducted : " << total << " Tk\n";
        } else {
            cout << "Insufficient Balance for bKash Payment\n";
            return;
        }

        showTransaction();
    }
};

// ========== Nagad ==========
class Nagad_Pay : public SSL_C {
public:
    void makePayment(float amount, float balance) {
        setAmount(amount);
        setBalance(balance);
        setDateTime();

        serviceCharge = amount * 0.015;
        float total = amount + serviceCharge;

        cout << "\n------ Processing Nagad Payment ------\n";
        if (balance >= total) {
            this->balance -= total;
            cout << "Nagad Payment Successful!\n";
            cout << "Total Deducted : " << total << " Tk\n";
        } else {
            cout << "Insufficient Balance for Nagad Payment\n";
            return;
        }

        showTransaction();
    }
};

// ========== Rocket ==========
class Rocket_Pay : public SSL_C {
public:
    void makePayment(float amount, float balance) {
        setAmount(amount);
        setBalance(balance);
        setDateTime();

        serviceCharge = amount * 0.014;
        float total = amount + serviceCharge;

        cout << "\n------ Processing Rocket Payment ------\n";
        if (balance >= total) {
            this->balance -= total;
            cout << "Rocket Payment Successful!\n";
            cout << "Total Deducted : " << total << " Tk\n";
        } else {
            cout << "Insufficient Balance for Rocket Payment\n";
            return;
        }

        showTransaction();
    }
};

// ========== User Account ==========
class UserAccount {
private:
    string pin;
    float balance;

public:
    UserAccount() {
        balance = 50000;
    }

    void setPin() {
        cout << "\nSet a 4-digit PIN: ";
        cin >> pin;
        cout << "PIN successfully set!\n";
    }

    bool verifyPin() {
        string input;
        cout << "Enter your PIN: ";
        cin >> input;
        if (input == pin) return true;
        cout << "Incorrect PIN!\n";
        return false;
    }

    float getBalance() const { return balance; }
    void setBalance(float newBalance) { balance = newBalance; }
};

// ========== Main ==========
int main() {
    UserAccount user;
    Bkash_Pay bkash;
    Nagad_Pay nagad;
    Rocket_Pay rocket;

    cout << "===========================================\n";
    cout << "Hey! I'm Adnan Sami - Welcome to <ASPay>\n";
    cout << "===========================================\n";

    user.setPin();

    while (true) {
        cout << "\nChoose Payment Gateway:\n";
        cout << "1. bKash\n";
        cout << "2. Nagad\n";
        cout << "3. Rocket\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (choice == 4) {
            cout << "Thanks for using ASPay!\n";
            break;
        }

        float amount;
        cout << "Enter Amount to Pay: ";
        cin >> amount;

        if (!user.verifyPin()) continue;

        float balance = user.getBalance();

        if (choice == 1) {
            bkash.makePayment(amount, balance);
        } else if (choice == 2) {
            nagad.makePayment(amount, balance);
        } else if (choice == 3) {
            rocket.makePayment(amount, balance);
        } else {
            cout << "Invalid choice!\n";
            continue;
        }

        float chargeRate = (choice == 1) ? 0.03 : (choice == 2) ? 0.015 : 0.014;
        float newBalance = balance - (amount + amount * chargeRate);
        if (newBalance >= 0) user.setBalance(newBalance);
    }


    return 0;
}
