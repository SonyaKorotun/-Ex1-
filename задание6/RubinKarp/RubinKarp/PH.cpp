#include "PH.h"

PH::PH(int length) : L(length) {
    kp.resize(L + 1);
    kp[0] = 1;
    // Вычисляем степени k по модулю Q
    for (int i = 1; i <= L; ++i) {
        kp[i] = static_cast<int>((static_cast<long long>(kp[i - 1]) * k) % Q); //Явное преобразование к int после вычисления
    }
}

PH::~PH() {}

int PH::Hash(const char* s) {
    long long h = 0;
    // Вычисляем полиномиальный хеш
    for (int i = 0; i < L; ++i) {
        h = (h + static_cast<long long>(s[i]) * kp[L - 1 - i]) % Q;
    }
    // Гарантируем, что результат неотрицательный и меньше Q
    return static_cast<int>((h % Q + Q) % Q); // Избавляемся от необходимости проверки знака
}

int PH::Shift(int h, char pref, char suff) {
    long long newHash = (static_cast<long long>(h) * k - static_cast<long long>(pref) * kp[L] + suff) % Q;
    // Гарантируем, что результат неотрицательный и меньше Q
    return static_cast<int>((newHash % Q + Q) % Q); // Избавляемся от необходимости проверки знака
}