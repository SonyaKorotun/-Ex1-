#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <iterator>
#include <algorithm>
#include <iomanip>

using namespace std;

// Определение типа student_data
typedef tuple<string, string, bool, size_t, pair<double, size_t>> student_data;

// Функция для вывода данных студентов в удобном формате
void print(const vector<student_data>& group) {
    for (const auto& student : group) {
        const string& name = get<0>(student);
        const string& surname = get<1>(student);
        bool gender = get<2>(student);
        size_t zachete_id = get<3>(student);
        const auto& score = get<4>(student);
        double mean = score.first;
        size_t number = score.second;

        cout << setw(10) << left << name << ' '
            << setw(10) << left << surname << ' '
            << (gender ? 'M' : 'F') << ' '     // M для мужчин, F для женщин
            << zachete_id << ' '
            << mean << ' '
            << number << endl;
    }
}

int main() {
    // Инициализация вектора студентов
    vector<student_data> group = {
        { "Roma",     "Borovik",     1, 8434562, {4.92, 12} },
        { "Victoria", "Ivanova",     0, 6349523, {4.81, 13} },
        { "Igor",     "Kommisarov",  1, 2456246, {4.55, 8}  },
        { "Sofia",    "Petrova",     0, 5678901, {3.75, 10} },
        { "Viktor",   "Kuznetsov",   1, 7632184, {5.00, 15} },
        { "Olga",     "Semenova",    0, 3245678, {4.25, 9}  },
        { "Dmitry",   "Fadeev",      1, 4321980, {4.30, 7}  },
        { "Anna",     "Stolypina",   0, 8765432, {4.60, 1} },
        { "Mikhail",  "Troepolsky",  1, 2345671, {4.95, 14} },
        { "Elena",    "Dykhovichnaya", 0, 6543212, {4.20, 6} }
    };

    cout << "Initial group:\n";
    print(group);
    cout << endl;

    // Найти студентов с максимальным и минимальным zachete_id
    auto min_it = min_element(group.begin(), group.end(),
        [](const student_data& left, const student_data& right) {
            return get<3>(left) < get<3>(right); // Сравниваем по zachete_id
        });

    auto max_it = max_element(group.begin(), group.end(),
        [](const student_data& left, const student_data& right) {
            return get<3>(left) < get<3>(right); // Сравниваем по zachete_id
        });

    // Поменять местами студентов с максимальным и минимальным zachete_id
    swap(*min_it, *max_it);

    cout << "After swapping students with min and max zachete_id:\n";
    print(group);
    cout << endl;

    // Подсчитать количество студентов с четным zachete_id
    size_t even_count = count_if(group.begin(), group.end(),
        [](const student_data& student) {
            return get<3>(student) % 2 == 0; // Проверка на четность zachete_id
        });

    cout << "Number of students with even zachete_id: " << even_count << endl;

    return 0;
}