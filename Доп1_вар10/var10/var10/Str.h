#ifndef STR_H
#define STR_H

#include <iostream>
#include <cstring>
#include <algorithm>

class Str {
    char* cstring;

public:
    // ����������� ��� ����������
    Str() : cstring(nullptr) {}

    // ����������� � ����������
    Str(const char* cstr) {
        size_t n = std::strlen(cstr) + 1;
        cstring = new char[n];
        std::copy(cstr, cstr + n, cstring);
    }

    // ����������� �����������
    Str(const Str& other) {
        size_t n = std::strlen(other.cstring) + 1;
        cstring = new char[n];
        std::copy(other.cstring, other.cstring + n, cstring);
    }

    // �������� ������������
    Str& operator=(const Str& other) {
        if (this == &other) return *this;

        delete[] cstring; // ������� ������ ������

        size_t n = std::strlen(other.cstring) + 1;
        cstring = new char[n];
        std::copy(other.cstring, other.cstring + n, cstring);

        return *this;
    }

    // �������� �������������� � const char*
    operator const char* () const {
        return cstring;
    }

    // �������� ����������� ���������: ���������� ����� ������ � �������� �������
    Str operator!() const {
        if (cstring == nullptr) return Str();

        size_t length = std::strlen(cstring);
        Str reversed;
        reversed.cstring = new char[length + 1]; // �������� ������ ��� ����� ������

        for (size_t i = 0; i < length; ++i) {
            reversed.cstring[i] = cstring[length - 1 - i]; // �������� � �������� �������
        }
        reversed.cstring[length] = '\0'; // ��������� ������� ���� � �����

        return reversed;
    }

    // ����������
    ~Str() {
        delete[] cstring;
    }
};

#endif // STR_H

