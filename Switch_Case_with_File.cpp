#include<iostream>
#include<fstream>

using namespace std;

int main() {
    int choice;
    double balance=100000;
    ofstream myfile;
    myfile.open("test.txt", ios::out | ios::app);



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
            myfile<<"Account Created. Initial Balance: "<<balance<<endl;
            break;
        case 2:
            double deposit;
            cout<<" Enter Amount to Deposit "<<endl;
            cin>>deposit;
            balance += deposit;
            cout<<"Deposit Successfully; Now Your Current Balance is: "<<balance<<endl;
            myfile<<"Deposit Successfully | Current Balance: "<<balance<<endl;
            break;
        case 3:
            double withdraw;
            cout<<"Enter Amount to Withdraw "<<endl;
            cin>>withdraw;
            if (withdraw <= balance) {
                balance -= withdraw;
                cout<<"Withdraw successful. Now Your remaining balance is "<<endl;
                myfile << "Withdrawn: " << withdraw << " | Remaining Balance: " << balance << endl;
            }
            else {
                balance += withdraw;
                cout<<"Insufficient Balance"<<endl;
            }
            myfile<<"Failed Withdraw"<< withdraw<<"Balance is:"<<balance<<endl;
            break;
        case 4:
            cout<<"Thank you for using my Banking System"<<endl;
            myfile<<"Thank you for using my Banking System"<<endl;
            break;
        default:
            cout<<"Invalid Entered by user"<<endl;
            myfile<<"Invalid Entered by user, Please try again, Thank You"<<endl;
    }
    myfile.close();
    return 0;

}
