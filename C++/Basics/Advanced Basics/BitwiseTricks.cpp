#include<bits/stdc++.h>
using namespace std;

int main(){
    //----------------Trick #1------------------
    // Check even or odd
    int x1 = 10;
    if((x1 & 1) == 0){
        cout<<"Even"<<endl;
    }
    else{
        cout<<"Odd"<<endl;
    }

    //----------------Trick #2------------------
    //Power of two
    int x2 = 16;
    if(x2 & (x2 - 1)){
        cout<<"Not a Power of Two"<<endl;
    }
    else{
        cout<<"Power of Two"<<endl;
    }

    //----------------Trick #3----------------------
    //Check if the Kth bit is set
    int x3 = 10;
    int k1 = 3;
    cout<<"Chcek Kth bit: "<<(x3 & (1 << k1))<<endl;

    // Toggle the Kth Bit
    int toggleBit = x3 ^ (1 << k1);
    cout<<"Toggle Bit: "<<toggleBit<<endl;

    // Set the Kth Bit
    int setKthBit = x3 | (1 << k1);
    cout<<"Set Kth Bit: "<<setKthBit<<endl;

    // Unset the Kth Bit
    int unsetKthBit = x3 & ~(1 << k1);
    cout<<"Unset Kth Bit: "<<unsetKthBit<<endl;

    //-----------------Trick #4---------------------
    // Divide by 2 -> 10/2 = 5 ( 1010 -> 101 ) | Divide by 4 -> 1010 -> 10 | Divide by 8 -> 1010 -> 1
    int x4 = 10;
    int result1 = x4 >> 1;
    int result2 = x4 >> 2;
    int result3 = x4 >> 3;
    cout<<x4<<" Divide by 2: "<<result1<<endl;
    cout<<x4<<" Divide by 4: "<<result2<<endl;
    cout<<x4<<" Divide by 8: "<<result3<<endl;

    // Divide by 2^k 
    int x5 = 10;
    int k2 = 3;
    int result4 = x5 >> k2;
    cout<<x5<<" Divide by 2^"<<k2<<": "<<result4<<endl;

    //Multiply by 2^k
    int x6 = 10;
    int k3 = 2;
    int result5 = x6 << k3;
    cout<<x6<<" Multiply by 2^"<<k3<<": "<<result5<<endl;

    // Multiply by 2 -> 10*2 = 20
    int x7 = 10;
    int result6 = x7 << 1;
    cout<<x7<<" Multiplied by 2: "<<result6<<endl;

    //-----------------Trick #5---------------------
    // Find out x % 2^k
    int x8 = 25;
    int k4 = 2;
    int result7 = x8 & ((1<<k4) - 1);
    cout<<"Remainder: "<<result7<<endl;

    //-----------------Trick #6----------------------
    // Swap 2 numbers
    int a = 15;
    int b = 20;

    cout<<"Before Swap"<<endl;
    cout<<"Value of a: "<<a<<endl;
    cout<<"Value of b: "<<b<<endl;

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    cout<<"After Swap: "<<endl;
    cout<<"Value of a: "<<a<<endl;
    cout<<"Value of b: "<<b<<endl;

    //------------------Trick #7---------------------
    int x9 = 5;
    int k5 = 7;

    // If number of set bits in a is x
    // number of set bits in b is y
    // number of set bits in a ^ b is z
    // then z is even if x + y is even
    // z is odd if x + y is odd


    //------------------Trick #8---------------------
    // Toggle values
    int value = 5;
    int tog1 = 5;
    int tog2 = 10;

    int toggleValue = tog1 ^ tog2 ^ value;
    cout<<"After toggling: "<<toggleValue<<endl;


    //------------------Trick #9---------------------
    // 1. A + B = (A ^ B) + 2(A & B)
    // 2. A + B = (A | B) + (A & B) 

    //------------------Trick #10---------------------
    // Finding the number of set bits in number X

    unsigned int temp1 = 9;
    cout<<"Number of set bits: "<<__builtin_popcount(temp1)<<endl;

    unsigned long long temp2 = 19;
    cout<<"Number of set bits in ll: "<<__builtin_popcountll(temp2)<<endl;
}