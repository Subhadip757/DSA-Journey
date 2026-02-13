#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class TwoDimensionalShape{
public:
    virtual double area() = 0;
};

class ThreeDimensionalShape{
public:
    virtual double area() = 0;
    virtual double volume() = 0;
};

class Square: public TwoDimensionalShape{
private:
    double side;

public:
    Square(double s) : side(s) {}

    double area() override{
        return side * side;
    }
};

class Rectangle: public TwoDimensionalShape{
private:
    double len, wid;

public:
    Rectangle(double l, double w) : len(l), wid(w) {}

    double area() override{
        return len * wid;
    }
};

class Cube: public ThreeDimensionalShape{
private:
    double side;
public:
    Cube(double s) : side(s) {}

    double area() override{
        return 6 * side * side;
    }

    double volume() override{
        return side * side * side;
    }
};

int main(){

    Square *sq = new Square(4);
    Rectangle *rec = new Rectangle(2, 10);
    Cube *cube = new Cube(3);

    cout<<"\nArea of Square: "<<sq -> area()<<endl;
    cout<<"Area of Rectangle: "<<rec -> area()<<endl;
    cout<<"Area of Cube: "<<cube -> area()<<endl;
    cout<<"Volume of Cube: "<<cube -> volume()<<"\n\n";
    
    

    return 0;
}