#include "Aggregate.h"
#include <iostream>

Aggregate::Aggregate() : m_objTest() { //�������������� ���� ������ ���� � ������ �������������
    std::cout << "����������� Aggregate ������.\n";
}

Aggregate::~Aggregate() {
    std::cout << "���������� Aggregate ������.\n";
}