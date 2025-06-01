#ifndef STR_H
#define STR_H

#include <iostream>
#include <cstring>
#include <algorithm>

class Str {
    char* cstring;

public:
    // Конструктор без параметров
    Str() : cstring(nullptr) {}

    // Конструктор с параметром
    Str(const char* cstr) {
        size_t n = std::strlen(cstr) + 1;
        cstring = new char[n];
        std::copy(cstr, cstr + n, cstring);
    }

    // Конструктор копирования
    Str(const Str& other) {
        size_t n = std::strlen(other.cstring) + 1;
        cstring = new char[n];
        std::copy(other.cstring, other.cstring + n, cstring);
    }

    // Оператор присваивания
    Str& operator=(const Str& other) {
        if (this == &other) return *this;

        delete[] cstring; // Удаляем старую память

        size_t n = std::strlen(other.cstring) + 1;
        cstring = new char[n];
        std::copy(other.cstring, other.cstring + n, cstring);

        return *this;
    }

    // Оператор преобразования в const char*
    operator const char* () const {
        return cstring;
    }

    // Оператор логического отрицания: возвращает новую строку в обратном порядке
    Str operator!() const {
        if (cstring == nullptr) return Str();

        size_t length = std::strlen(cstring);
        Str reversed;
        reversed.cstring = new char[length + 1]; // Выделяем память для новой строки

        for (size_t i = 0; i < length; ++i) {
            reversed.cstring[i] = cstring[length - 1 - i]; // Копируем в обратном порядке
        }
        reversed.cstring[length] = '\0'; // Добавляем нулевой байт в конец

        return reversed;
    }

    // Деструктор
    ~Str() {
        delete[] cstring;
    }
};

#endif // STR_H

