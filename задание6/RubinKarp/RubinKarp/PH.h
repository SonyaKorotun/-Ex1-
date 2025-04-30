#ifndef RUBINKARP_PH_H
#define RUBINKARP_PH_H

#include <iostream>
#include <vector>

class PH {
private:
    static const int k = 257;  // Небольшое целое, больше 255
    static const int Q = 65521; // Достаточно большое простое число

    std::vector<int> kp; // Массив степеней k по модулю Q
    int L;                 // Длина хеша

public:
    PH(int length);         // Конструктор
    ~PH();                // Деструктор

    int Hash(const char* s); // Вычисление хеша
    int Shift(int h, char pref, char suff); // Сдвиг хеша
};

#endif // RUBINKARP_PH_H