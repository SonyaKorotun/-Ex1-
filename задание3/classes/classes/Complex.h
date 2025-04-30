#pragma once
#include <iostream>
#include <cmath> 

class Complex {
public:
    double Re, Im;

    Complex() : Re(0.0), Im(0.0) {}

    Complex(double re = 0.0, double im = 0.0) : Re(re), Im(im) {}

    inline friend std::ostream& operator<<(std::ostream& o, const Complex& c) {
        return o << '(' << c.Re << ", " << c.Im << ')';
    }

    Complex operator+(const Complex& c) const {
        return Complex(Re + c.Re, Im + c.Im);
    }

    Complex operator-(const Complex& c) const {
        return Complex(Re - c.Re, Im - c.Im);
    }

    Complex operator*(const Complex& c) const {
        return Complex(Re * c.Re - Im * c.Im, Re * c.Im + c.Re * Im);
    }

    Complex operator/(const Complex& c) const {
        double denominator = c.Re * c.Re + c.Im * c.Im;
        if (denominator == 0.0) {
            return Complex(INFINITY, INFINITY); 
        }
        return Complex((Re * c.Re + Im * c.Im) / denominator, (Im * c.Re - Re * c.Im) / denominator);
    }

    Complex Conjugate() const {
        return Complex(Re, -Im);
    }

    double Mod() const {
        return sqrt(Re * Re + Im * Im);
    }

    double Arg() const {
        if (Mod() == 0.0) {
            return 0.0;
        }
        if (Re > 0.0) {
            return atan(Im / Re);
        }
        else if (Re < 0.0) {
            return (Im >= 0.0) ? acos(-1.0) + atan(Im / Re) : -acos(-1.0) + atan(Im / Re);
        }
        else { 
            return (Im > 0.0) ? acos(0.0) : -acos(0.0);
        }
    }
};