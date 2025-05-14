#include <iostream>
#include "Str.h"

int main() {
    Str str("Hello, world!");
    std::cout << "Searching empty string: " << str.find("", 0) << std::endl;
    std::cout << "Searching 'l': " << str.find("l", 0) << std::endl;
    std::cout << "Searching 'l' again: " << str.find("l", 1) << std::endl;
    std::cout << "Searching 'o' with off = 7: " << str.find("o", 7) << std::endl;
    std::cout << "Searching 'world!': " << str.find("world!", 7) << std::endl;
    std::cout << "Searching 'xxx': " << str.find("xxx", 0) << std::endl;

    return 0;
}
