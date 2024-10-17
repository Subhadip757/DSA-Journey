#include<bits/stdc++.h>
using namespace std;

struct employee{
    int empID;
    string empName;
    int salary;
    string role;
};

union money{
    int rice;
    char car[100];
    int veges;
};

int main(){

    struct employee subha;

    union money m1;

    enum days {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};
    days d1 = Monday;

    cout<<d1<<endl;

    strcpy(m1.car, "Ferrari");
    cout<<m1.car;
    
    subha.empID = 01;
    subha.empName = "Subhadip Dey";
    subha.salary = 50000;
    subha.role = "SDE";


    // cout<<subha.empID<<endl;
    // cout<<subha.empName<<endl;
    // cout<<subha.salary<<endl;
    // cout<<subha.role;
}