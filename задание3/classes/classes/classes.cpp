#include <iostream>
#include <cmath> 
#include "Complex.h"

int main() {
    Complex a(1, 2);
    Complex b = 3; 
    std::cout << "a: " << a << ", b: " << b << std::endl;

    Complex sum = a + b;
    std::cout << "a + b: " << sum << std::endl;

    Complex diff = a - b;
    std::cout << "a - b: " << diff << std::endl;

    Complex mult = a * b;
    std::cout << "a * b: " << mult << std::endl;

    Complex div = a / b;
    std::cout << "a / b: " << div << std::endl;

    Complex conj = a.Conjugate();
    std::cout << "Conjugate of a: " << conj << std::endl;

    std::cout << "Modulus of a: " << a.Mod() << std::endl;

    std::cout << "Argument of a: " << a.Arg() << std::endl;

    Complex v[4]{ 1, 2, Complex(2, 3) };
    std::cout << "Array v: ";
    for (int i = 0; i < 4; ++i) {
        std::cout << v[i] << (i == 3 ? "" : ", ");
    }
    std::cout << std::endl;

    Complex* pc = new Complex(1, 2);
    std::cout << "pc: " << *pc << std::endl;
    std::cout << "pc->Re: " << pc->Re << std::endl;
    std::cout << "pc->Im: " << pc->Im << std::endl;
    delete pc;

    Complex* pcArray = new Complex[3];
    std::cout << "pcArray: ";
    for (int i = 0; i < 3; ++i) {
        std::cout << pcArray[i] << (i == 2 ? "" : ", ");
    }
    std::cout << std::endl;

    pcArray[1].Re = 5;
    std::cout << "pcArray[1].Re: " << pcArray[1].Re << std::endl;

    delete[] pcArray;


    return 0;
}