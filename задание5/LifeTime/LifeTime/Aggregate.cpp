#include "Aggregate.h"
#include <iostream>

Aggregate::Aggregate() : m_objTest() { //Инициализируем член класса явно в списке инициализации
    std::cout << "Конструктор Aggregate вызван.\n";
}

Aggregate::~Aggregate() {
    std::cout << "Деструктор Aggregate вызван.\n";
}