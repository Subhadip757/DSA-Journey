#include <bits/stdc++.h>
using namespace std;

class DepositOnlyAccount{
public:
    virtual void deposit(double amount) = 0;
};

class WithdrawableAccount: public DepositOnlyAccount{
public:
    virtual void withdraw(double amount) = 0;
};

class SavingsAccount: public WithdrawableAccount{
private:
    double balance;

public:
    SavingsAccount(){
        balance = 0;
    }

    void deposit(double amount){
        balance += amount;
        cout<<"Balance in Account after depost: "<<balance<<endl;
    }

    void withdraw(double amount){
        if(balance >= amount){
            balance -= amount;
            if(balance < 0){
                balance = 0;
            }
            cout<<"Balance in Account after withdraw: "<<balance<<endl;
        }
        else{
            cout<<"Insufficient Balance!!"<<endl;
        }
    }
};

class CurrentAccount: public WithdrawableAccount{
private:
    double balance;

public:
    CurrentAccount(){
        balance = 0;
    }

    void deposit(double amount){
        balance += amount;
        cout<<"Balance in Account after depost: "<<balance<<endl;
    }

    void withdraw(double amount){
        if(balance >= amount){
            balance -= amount;
            if(balance < 0){
                balance = 0;
            }
            cout<<"Balance in Account after withdraw: "<<balance<<endl;
        }
        else{
            cout<<"Insufficient Balance!!"<<endl;
        }
    }
};

class FixedAccount: public DepositOnlyAccount{
private:
    double balance;

public:
    FixedAccount(){
        balance = 0;
    }

    void deposit(double amount){
        balance += amount;
        cout<<"Balance in Account after depost: "<<balance<<endl;
    }
};

class BankClient{
private:
    vector<WithdrawableAccount*> withdrawableAccounts;
    vector<DepositOnlyAccount*> depositOnlyAccounts;

public:
    BankClient(vector<WithdrawableAccount*> wa, vector<DepositOnlyAccount*> da){
        this -> withdrawableAccounts = wa;
        this -> depositOnlyAccounts = da;
    }

    void proceedTransactions(){
        for(WithdrawableAccount* acc : withdrawableAccounts){
            acc->deposit(1000);
            acc->withdraw(500);
        }

        for(DepositOnlyAccount* acc : depositOnlyAccounts){
            acc->deposit(5000);
        }
    }
};

int main()
{
    vector<WithdrawableAccount*> wa;
    wa.push_back(new SavingsAccount());
    wa.push_back(new CurrentAccount());

    vector<DepositOnlyAccount*> da;
    da.push_back(new FixedAccount());

    BankClient* client = new BankClient(wa, da);
    client -> proceedTransactions();
    
    return 0;
}