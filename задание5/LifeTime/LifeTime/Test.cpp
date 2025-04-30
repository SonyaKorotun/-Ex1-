#include "Test.h"
#include <iostream>

int Test::nCount = 0;

Test::Test() {
    nCount++;
    std::cout << "Конструктор Test вызван. nCount = " << nCount << "\n";
}

Test::Test(const Test& other) { // Конструктор копирования
    nCount++;
    std::cout << "Конструктор копирования Test вызван. nCount = " << nCount << "\n";
}

Test::~Test() {
    nCount--;
    std::cout << "Деструктор Test вызван. nCount = " << nCount << "\n";
}

// 8. Определение функции foo
void foo(Test t) {
    std::cout << "foo is running\n";
    t.printMessage(); // Добавлено для демонстрации полиморфизма
}