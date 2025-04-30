#include "Test.h"
#include <iostream>

int Test::nCount = 0;

Test::Test() {
    nCount++;
    std::cout << "����������� Test ������. nCount = " << nCount << "\n";
}

Test::Test(const Test& other) { // ����������� �����������
    nCount++;
    std::cout << "����������� ����������� Test ������. nCount = " << nCount << "\n";
}

Test::~Test() {
    nCount--;
    std::cout << "���������� Test ������. nCount = " << nCount << "\n";
}

// 8. ����������� ������� foo
void foo(Test t) {
    std::cout << "foo is running\n";
    t.printMessage(); // ��������� ��� ������������ ������������
}