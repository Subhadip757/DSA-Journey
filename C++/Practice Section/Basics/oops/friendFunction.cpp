#include <iostream>
using namespace std;

class Complex {
    private:
        int real, imag;
    
    public:
        Complex(int r = 0, int i = 0){
            real = r;
            imag = i;
        }
        
        // Friend function declaration
        friend Complex addComplex(const Complex &c1, const Complex &c2);
        
        void display() {
            cout << real << " + " << imag << "i" << endl;
        }
};

// Friend function definition
Complex addComplex(const Complex &c1, const Complex &c2) {
    Complex temp;
    temp.real = c1.real + c2.real;
    temp.imag = c1.imag + c2.imag;
    return temp;
}

int main() {
    Complex c1(3, 4), c2(1, 2);
    Complex result = addComplex(c1, c2);
    
    cout << "Sum of complex numbers: ";
    result.display();
    
    return 0;
}
