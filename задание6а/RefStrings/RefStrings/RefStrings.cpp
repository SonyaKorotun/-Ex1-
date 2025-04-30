#include <iostream>
#include "Str.h"

int main() {
    Str s1 = "Hello";
    Str s2 = s1; // Copy constructor

    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;

    // Reading a character (const access)
    try {
        std::cout << "s1[0]: " << s1[0] << std::endl;
        //std::cout << "s1[100]: " << s1[100] << std::endl; // Should throw exception
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Modifying a character (non-const access with copy-on-write)
    s1[0] = 'J'; // This should trigger the copy-on-write

    std::cout << "s1 after modification: " << s1 << std::endl;
    std::cout << "s2 after s1 modification: " << s2 << std::endl; // s2 should remain unchanged

    // Multiple modifications to the same string
    Str s3 = "Test";
    Str s4 = s3;

    s3[0] = 'A';
    s3[1] = 'B';

    std::cout << "s3 after multiple modifications: " << s3 << std::endl;
    std::cout << "s4 after s3 modifications: " << s4 << std::endl;

    return 0;
}