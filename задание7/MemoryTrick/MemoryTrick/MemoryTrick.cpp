#include <iostream>
#include <vector>
#include <iomanip> // Для форматированного вывода (std::setw)

using namespace std;

int main() {
    // 2. Подключение модуля vector и объявление динамического массива
    vector<int> myVector;

    // 3. Вывод размера и вместимости
    cout << "Size: " << setw(3) << myVector.size() << ", Capacity: " << setw(3) << myVector.capacity() << endl;

    // 4. Цикл push_back и вывод
    int count = 32;
    int prevCapacity = myVector.capacity();
    for (int i = 0; i < count; ++i) {
        myVector.push_back(1);
        if (myVector.capacity() != prevCapacity) {
            cout << "Size: " << setw(3) << myVector.size() << ", Capacity: " << setw(3) << myVector.capacity() << endl;
            prevCapacity = myVector.capacity();
        }
    }

    // 5. Доработка программы (размер и вместимость выводятся только при изменении вместимости - уже сделано выше)

    return 0;
}