#ifndef STR_H
#define STR_H

#include <cstring>
#include <iostream>

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

        delete[] cstring;
        size_t n = std::strlen(other.cstring) + 1;
        cstring = new char[n];
        std::copy(other.cstring, other.cstring + n, cstring);
        return *this;
    }

    // �������� �������������� � const char*
    operator const char* () const {
        return cstring;
    }

    // �������� ��������� ==
    bool operator==(const Str& other) const {
        return std::strcmp(cstring, other.cstring) == 0;
    }

    // �������� ��������� !=
    bool operator!=(const Str& other) const {
        return !(*this == other);
    }

    // �������� ��������� <
    bool operator<(const Str& other) const {
        return std::strcmp(cstring, other.cstring) < 0;
    }

    // �������� ��������� >
    bool operator>(const Str& other) const {
        return std::strcmp(cstring, other.cstring) > 0;
    }

    // �������� ��������� <=
    bool operator<=(const Str& other) const {
        return !(*this > other);
    }

    // �������� ��������� >=
    bool operator>=(const Str& other) const {
        return !(*this < other);
    }

    // ����������
    ~Str() {
        delete[] cstring;
    }
};

#endif // STR_H
