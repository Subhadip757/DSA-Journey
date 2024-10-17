// 1. Create a class "BankAccount" with attributes account number and balance. Implement methods to deposit and withdraw funds, and a display method to show the account details.

#include<bits/stdc++.h>
using namespace std;

class BankAccount{
private:
    int accountNumber;
    double balance;

public:
    int depositAmount(int amount){
        return balance += amount;
    }

    int withdrawAmount(int amount){
        if((balance - amount) < 0){
            cout<<"Insufficient Balance";
        }
        return balance -= amount;
    }

    void setDetails(int acn, int bal){
        accountNumber = acn;
        balance = bal;
    }

    void displayDetails(){
        cout<<"Account Number: "<<accountNumber<<endl;
        cout<<"Balance: "<<balance;
    }
};

int main(){
    BankAccount ac1;
    ac1.setDetails(1, 1000);

    ac1.depositAmount(5000);
    ac1.withdrawAmount(2000);

    ac1.displayDetails();
}
