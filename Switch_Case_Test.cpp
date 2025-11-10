#include<iostream>
using namespace std;

int main() {
    int choice;
    double balance=100000;

    cout<<".............Bank Management System.......... "<<endl;
    cout<<"1. Create Account"<<endl;
    cout<<"2. Deposit"<<endl;
    cout<<"3. Withdraw"<<endl;
    cout<<"4. Exit"<<endl;

    cout<<"Enter your choice: ";
    cin>>choice;

    switch(choice) {
        case 1:
            cout<<"Account open successfully"<<endl;
            break;
        case 2:
            double deposit;
            cout<<" Enter Amount to Deposit "<<endl;
            cin>>deposit;
            balance += deposit;
            cout<<"Deposit Successfully; Now Your Current Balance is: "<<balance<<endl;
            break;
        case 3:
            double withdraw;
            cout<<"Enter Amount to Withdraw "<<endl;
            cin>>withdraw;
            if (withdraw <= balance) {
                balance -= withdraw;
                cout<<"Withdraw successful. Now Your remaining balance is "<<endl;

            }
            else {
                balance += withdraw;
                cout<<"Insufficient Balance"<<endl;
            }
            break;
        case 4:
            cout<<"Thank you for using my Banking System"<<endl;
            break;
        default:
            cout<<"Invalid Choice"<<endl;

    }
    return 0;
}
