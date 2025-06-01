#ifndef STR_H
#define STR_H

#include <cstring>
#include <iostream>

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

        delete[] cstring;
        size_t n = std::strlen(other.cstring) + 1;
        cstring = new char[n];
        std::copy(other.cstring, other.cstring + n, cstring);
        return *this;
    }

    // Оператор преобразования в const char*
    operator const char* () const {
        return cstring;
    }

    // Оператор сравнения ==
    bool operator==(const Str& other) const {
        return std::strcmp(cstring, other.cstring) == 0;
    }

    // Оператор сравнения !=
    bool operator!=(const Str& other) const {
        return !(*this == other);
    }

    // Оператор сравнения <
    bool operator<(const Str& other) const {
        return std::strcmp(cstring, other.cstring) < 0;
    }

    // Оператор сравнения >
    bool operator>(const Str& other) const {
        return std::strcmp(cstring, other.cstring) > 0;
    }

    // Оператор сравнения <=
    bool operator<=(const Str& other) const {
        return !(*this > other);
    }

    // Оператор сравнения >=
    bool operator>=(const Str& other) const {
        return !(*this < other);
    }

    // Деструктор
    ~Str() {
        delete[] cstring;
    }
};

#endif // STR_H
