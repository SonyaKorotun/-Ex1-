#ifndef TEST_H
#define TEST_H

#include <iostream>

class Test {
public:
    static int nCount;

    Test();
    Test(const Test& other); // ����������� �����������
    virtual ~Test(); // virtual ��� ����������� ������ ����������� � �������� �������

    virtual void printMessage() const {
        std::cout << "��������� �� Test\n";
    }
};

// 8. ���������� ������� foo
void foo(Test t);


#endif