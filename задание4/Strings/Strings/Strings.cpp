#include <iostream>
#include "Str.h"

int main() {
    Str s1 = "Hello";
    Str s2 = " World";

    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;

    s1 += s2; 
    std::cout << "s1 after s1 += s2: " << s1 << std::endl;

    Str s3 = s1 + "!"; 
    std::cout << "s3 (s1 + '!'): " << s3 << std::endl;

    Str s4 = "New string";
    s4 += " appended";
    std::cout << "s4 after append: " << s4 << std::endl;

    return 0;
}