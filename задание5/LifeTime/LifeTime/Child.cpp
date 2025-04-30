#include "Child.h"
#include <iostream>

Child::Child() : Test() { //явный вызов конструктора базового класса
    std::cout << " онструктор Child вызван.\n";
}

Child::~Child() {
    std::cout << "ƒеструктор Child вызван.\n";
}