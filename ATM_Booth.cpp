#include <iostream>
#include <conio.h>
#include<fstream>
using namespace std;

void display()
{
    cout << "=======Welcome to Adnan's ATM Booth======="<< endl;
    cout << "   1. Check Balance" << endl;
    cout << "   2. Deposit Money" << endl;
    cout << "   3. Withdraw Money" << endl;
    cout << "   4. Exit" << endl;
}

bool checkPin()
{
    int correctPin = 1234;
    int enteredPin;
    int attempts = 0;

    while (attempts < 3)
    {
        cout << "Enter your 4-digit PIN: ";
        cin >> enteredPin;

        if (enteredPin == correctPin)
        {
            return true;
        }
        else
        {
            cout << "Incorrect PIN. Try again." << endl;
            attempts++;
        }
    }

    cout << "Too many incorrect attempts. Exiting..." << endl;
    return false;
}

int main()
{
    int balance = 50000;
    int option;
    int deposit;
    int withdraw;
    ofstream myfile;
    myfile.open("atm.txt", ios::out | ios::app);

    if (!checkPin())
    {
        return 0;
    }

    while (true)
    {
        display();
        cout << "Choose Option:"<<endl;
        cin >> option;

        system("cls");

        switch (option)
        {
            case 1:
                cout << "Your Balance Now: " << balance << endl;
                myfile << "Current Balance: " << balance << endl;
                break;

            case 2:
                cout << "Enter Deposit Amount: ";
                cin >> deposit;
                balance += deposit;
                cout << "You have deposited: " << deposit << endl;
                cout << "My Current Balance Now: " << balance << endl;
                
                myfile << "Deposited Amount: " << deposit << endl;
                myfile << "Current Balance: " << balance << endl;
                break;

            case 3:
                cout << "Enter Withdraw Amount: ";
                cin >> withdraw;


                if (withdraw <= balance)
                {
                    balance -= withdraw;
                    cout << "You have withdrawn: " << withdraw << endl;
                    cout << "My Current Balance Now: " << balance << endl;
                    myfile << "Withdrawn Amount: " << withdraw << endl;
                    myfile << "Current Balance: " << balance << endl;
                }
                else
                {
                    cout << "Insufficient Balance!" << endl;
                    myfile << "Failed Withdrawal Attempt: " << withdraw << endl;
                }
                break;

            case 4:
                cout << "Thank you for using Adnan's ATM Booth!" << endl;
                myfile << "Session Ended. Final Balance: " << balance << endl;
                return 0;

            default:
                cout << "Wrong Input, please try again." << endl;
                myfile << "Invalid Option Selected: " << option << endl;

        }
        cout << "Press any key to continue... ... ..." << endl;
    }
    myfile.close();
    return 0;
}
