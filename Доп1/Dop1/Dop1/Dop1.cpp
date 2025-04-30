#include <iostream>
#include "list.h"
#include <numeric>

using namespace std;

int main() {
    // Создание списка
    List<char> myList;

    // Проверка empty()
    cout << myList.empty() << endl; // true

    // Добавление элементов
    myList.push_back('a');
    myList.push_back('b');
    myList.push_back('c');
    myList.push_back('d');
    myList.push_back('e');

    // Вывод списка
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        cout << *it << " -> ";
    }
    cout << endl; // a -> b -> c -> d -> e ->

    // Добавление в начало
    myList.push_front('v');
    myList.push_front('w');
    myList.push_front('x');
    myList.push_front('y');
    myList.push_front('z');

    // Вывод списка с расширенным диапазоном
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        cout << *it << " -> ";
    }
    cout << endl; // v -> w -> x -> y -> z -> a -> b -> c -> d -> e ->

    //Добавление элемента по индексу
    myList.insert(5, 'f');
    myList.insert(6, 'g');
    myList.insert(7, 'h');
    myList.insert(8, 'i');
    myList.insert(9, 'j');

    // Вывод списка
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        cout << *it << " -> ";
    }
    cout << endl; //v -> w -> x -> y -> z -> a -> b -> c -> d -> e ->f -> g -> h -> i ->j ->

    // Удаление элементов
    myList.pop_front(); // v
    myList.remove_at(0); //w
    myList.remove_at(12); //j

    // Вывод списка
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        cout << *it << " -> ";
    }
    cout << endl; //x -> y -> z -> a -> b -> c -> d -> e ->f -> g -> h -> i ->

    // Вставка элемента
    myList.insert(3, 'o');

    // Вывод списка
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        cout << *it << " -> ";
    }
    cout << endl; //x -> y -> z -> o -> a -> b -> c -> d -> e ->f -> g -> h -> i ->

    // Размер списка
    cout << myList.size() << endl; //13

    // Проверка empty()
    cout << myList.empty() << endl; //false

    // Доступ по индексу
    cout << myList[2] << endl; // z

    // Пример использования с accumulate
    List<int> l;
    l.push_back(3);
    l.push_back(5);
    l.push_back(2);
    l.push_back(7);
    l.push_back(8);

    int s = 0;
    for (auto& i : l) s += i * 10;
    auto lambda = [](int a, int b) { return a + b * 10; };
    cout << s << '\t' << std::accumulate(l.begin(), l.end(), 0, lambda) << '\n';

    return 0;
}