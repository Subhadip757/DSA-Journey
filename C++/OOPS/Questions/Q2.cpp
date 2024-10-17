// 2. Create a base class "Shape" with methods to calculate the area and perimeter (pure virtual). Implement derived classes "Rectangle" and "Circle" that inherit from "Shape" and provide their own area and perimeter calculations.

#include<bits/stdc++.h>
using namespace std;

class Shape{
    virtual double area() = 0;
    virtual double perimeter() = 0;
};

class Rectangle : public Shape{
public:
    int area(){
        
    }
};

int main(){

}