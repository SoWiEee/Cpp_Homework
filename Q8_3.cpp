#include <iostream>
#include<cstdlib>

using namespace std;

class Complex{
private:
    double real;
    double imaginary;

public:
    // constructor
    Complex(): real(0), imaginary(0) {};
    Complex(double re, double im): real(re), imaginary(im) {};

    // overloading operator
    bool operator==(const Complex& other) const {
        return (real == other.real && imaginary == other.imaginary);
    }

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imaginary * other.imaginary,
                       real * other.imaginary + imaginary * other.real);
    }

    friend ostream& operator<<(ostream& os, const Complex& complex) {
        os << complex.real << " + " << complex.imaginary << "i";
        return os;
    }

    friend istream& operator>>(istream& is, Complex& complex) {
        is >> complex.real >> complex.imaginary;
        return is;
    }

};

const Complex i(0, 1);  // const i

int main(){
    Complex a(1, 2);
    Complex b(3, 4);
    Complex c = a + b;  // 4 + 6i

    cout << "c = " << c << endl;

    system("pause");
    return 0;
}
