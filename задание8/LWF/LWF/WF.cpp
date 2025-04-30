#include "WF.h"
#include <algorithm>
#include <iostream>
#include <vector>

WF::WF() : pm(nullptr), M(0), N(0), initialized(false) {}

WF::~WF() {
    if (pm != nullptr) {
        delete[] pm;
        pm = nullptr;
    }
}

void WF::Init(const char* sc, const char* tc) {
    if (initialized) {
        if (pm != nullptr) {
            delete[] pm;
            pm = nullptr;
        }
        M = 0;
        N = 0;
    }

    s = std::string(sc);
    t = std::string(tc);
    M = s.length() + 1;
    N = t.length() + 1;

    pm = new int[M * N];
    initialized = true;

    // Заполнение матрицы алгоритмом Вагнера-Фишера
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == 0) {
                pm[i * N + j] = j;
            }
            else if (j == 0) {
                pm[i * N + j] = i;
            }
            else {
                int cost = (s[i - 1] == t[j - 1]) ? 0 : 1;
                pm[i * N + j] = std::min({
                    pm[(i - 1) * N + j] + 1,      // Удаление
                    pm[i * N + (j - 1)] + 1,      // Вставка
                    pm[(i - 1) * N + (j - 1)] + cost // Замена
                    });
            }
        }
    }
}

int WF::Rows() const {
    return M;
}

int WF::Columns() const {
    return N;
}

int WF::Get(int i, int j) const {
    if (i < 0 || i >= M || j < 0 || j >= N) {
        throw std::out_of_range("Get: Index out of range");
    }
    return pm[i * N + j];
}

void WF::Set(int i, int j, int val) {
    if (i < 0 || i >= M || j < 0 || j >= N) {
        throw std::out_of_range("Set: Index out of range");
    }
    pm[i * N + j] = val;
}

int WF::Distance() const {
    if (!initialized) {
        throw std::runtime_error("WF::Distance: Object not initialized");
    }
    return pm[(M - 1) * N + (N - 1)];
}
