#include "Child.h"
#include <iostream>

Child::Child() : Test() { //����� ����� ������������ �������� ������
    std::cout << "����������� Child ������.\n";
}

Child::~Child() {
    std::cout << "���������� Child ������.\n";
}