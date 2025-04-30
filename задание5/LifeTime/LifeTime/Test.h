#ifndef TEST_H
#define TEST_H

#include <iostream>

class Test {
public:
    static int nCount;

    Test();
    Test(const Test& other); // Конструктор копирования
    virtual ~Test(); // virtual для правильного вызова деструктора в дочерних классах

    virtual void printMessage() const {
        std::cout << "Сообщение от Test\n";
    }
};

// 8. Объявление функции foo
void foo(Test t);


#endif