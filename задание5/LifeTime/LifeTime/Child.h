#ifndef CHILD_H
#define CHILD_H

#include "Test.h"

class Child : public Test {
public:
    Child();
    ~Child();
    void printMessage() const override {
        std::cout << "��������� �� Child\n";
    }
};

#endif

