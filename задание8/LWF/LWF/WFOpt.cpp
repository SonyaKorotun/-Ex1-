#include "WFOpt.h"
#include <algorithm>
#include <cstring>

int DistanceOpt(const char* s, const char* t) {
    int M = std::strlen(s) + 1;
    int N = std::strlen(t) + 1;

    int* p1 = new int[N];
    int* p2 = new int[N];

    // 1) Заполняем p1
    for (int j = 0; j < N; ++j) {
        p1[j] = j;
    }

    // Итерации по строкам
    for (int i = 1; i < M; ++i) {
        p2[0] = i; // Запомним номер текущей итерации

        for (int j = 1; j < N; ++j) {
            int cost = (s[i - 1] == t[j - 1]) ? 0 : 1;
            p2[j] = std::min({
                p1[j] + 1,       // Удаление
                p2[j - 1] + 1,       // Вставка
                p1[j - 1] + cost  // Замена
                });
        }

        // Обмен значениями p1 и p2
        std::swap(p1, p2);
    }

    int result = p1[N - 1]; // Результат находится в последнем элементе p1

    delete[] p1;
    delete[] p2;

    return result;
}