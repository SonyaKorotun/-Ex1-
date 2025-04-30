
#include <iostream>
#include "Test.h"
#include "Child.h"
#include "Aggregate.h"
#include "AggregateT.h"

// 4. Объявление глобального объекта Test
Test globalTestObject;

int main() {
    std::cout << "Начало работы программы.\n";

    // 2. Строка вывода перед созданием объекта
    std::cout << "Перед созданием объекта testObject.\n";

    // Объявление объекта типа Test
    Test testObject;

    std::cout << "Работа с объектом testObject.\n";

    // 5. Создание динамического объекта
    Test* p = new Test;
    std::cout << "Создан динамический объект.\n";

    // 6. Добейтесь, что бы вызывался деструктор созданного динамического объекта.
    delete p;
    p = nullptr; // Важно обнулять указатель после delete
    std::cout << "Удален динамический объект.\n";

    // 7. Создайте динамический массив объектов Test
    int arraySize = 3;
    Test* testArray = new Test[arraySize]; // Конструктор будет вызван для каждого элемента

    std::cout << "Создан динамический массив объектов Test.\n";

    // 7. Удаление массива объектов Test (ВАЖНО: используйте delete[])
    delete[] testArray; // Деструктор будет вызван для каждого элемента
    testArray = nullptr;
    std::cout << "Удален динамический массив объектов Test.\n";

    // 8. Вызов foo с одним из объектов Test
    std::cout << "Перед вызовом foo.\n";
    foo(testObject);
    std::cout << "После вызова foo.\n";

    // 10. Создание объекта Child
    std::cout << "Перед созданием объекта Child.\n";
    Child childObject;
    std::cout << "После создания объекта Child.\n";

    // 11. Создание объекта Aggregate
    std::cout << "Перед созданием объекта Aggregate.\n";
    Aggregate aggregateObject;
    std::cout << "После создания объекта Aggregate.\n";

    // 12. Создание объекта AggregateT<Test>
    std::cout << "Перед созданием объекта AggregateT<Test>.\n";
    AggregateT<Test> aggregateTTest;
    std::cout << "После создания объекта AggregateT<Test>.\n";

    // 12. Создание объекта AggregateT<Child>
    std::cout << "Перед созданием объекта AggregateT<Child>.\n";
    AggregateT<Child> aggregateTChild;
    std::cout << "После создания объекта AggregateT<Child>.\n";

    std::cout << "Конец работы программы.\n";

    return 0;
}