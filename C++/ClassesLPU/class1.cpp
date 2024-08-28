#include <iostream>
using namespace std;

float generateBill(float bill){
    float result = 0;
    if(bill > 100){
        result = bill * 6.95;
    }
    else{
        result = bill * 5.95;
    }
    return result;
}

float shopping(int mobile, int powerbank){
    int MobileAmount  = 10000;
    int PowerBankAmount = 500;

    float total = 0;

    if(mobile >= 1 && powerbank >= 1){
        total = ((MobileAmount*mobile) + (PowerBankAmount*powerbank)) * 0.25;
    }
    else{
        total = ((MobileAmount*mobile) + (PowerBankAmount*powerbank)) * 0.05;
    }
    return total;
}

float balance(int amount){
    float total = amount;

    if(amount >= 5000 && amount <= 10000){
        total += amount * 0.10;
    }
    else if(amount >= 4000 && amount < 5000){
        total += amount * 0.08;
    }
    else if(amount >= 3000 && amount < 4000){
        total += amount * 0.07;
    }
    else if(amount >= 2000 && amount < 3000){
        total += amount * 0.05;
    }
    return total;
}

bool bankEligibility(int creditScore, double anualIncome, double DebtToIncome){
    if(creditScore > 650 && anualIncome >= 30000 && DebtToIncome < 0.4){
        return true;
    }
    return false;
}

int main(){
    // float bill = 230;
    // cout<<"Total Amount: "<<generateBill(bill)<<endl;

    // int mobile, powerbank;
    // cout<<"Enter no. of mobiles: ";
    // cin>>mobile;

    // cout<<"Enter no. of powerbank: ";
    // cin>>powerbank;

    // cout<<"Final discount: "<<shopping(mobile, powerbank)<<endl;

    // cout<<"Final balance: "<<balance(5000);

    if(bankEligibility(700, 40000, 0.3)){
        cout<<"Loan Approved";
    }
    else{
        cout<<"Loan Denied";
    }
}