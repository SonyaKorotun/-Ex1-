#pragma once
#include "_str.h"
#include <iostream>
#include <string.h>
#include <stdexcept>

class Str {
private:
    _str* ps;

public:
    Str() : ps(new _str(0)) {}

    Str(const char* s) : ps(new _str(strlen(s))) {
        strcpy(ps->data, s);
    }

    Str(const Str& s) : ps(s.ps) { // Copy constructor: share data
        ++ps->nrefs;
    }

    ~Str() {
        if (--ps->nrefs == 0) {
            delete ps;
        }
    }

    Str& operator=(const Str& s) {
        if (this != &s) {
            if (--ps->nrefs == 0) {
                delete ps;
            }
            ps = s.ps;
            ++ps->nrefs;
        }
        return *this;
    }

    const char* str() const { return ps->data; }

    operator const char* () const { return ps->data; }

    Str& operator+=(const Str& s) {
        int newSize = ps->size + s.ps->size;
        _str* newPs = new _str(newSize);
        strcpy(newPs->data, ps->data);
        strcat(newPs->data, s.ps->data);

        if (--ps->nrefs == 0) {
            delete ps;
        }
        ps = newPs;
        return *this;
    }

    const char& operator[](int i) const { // Read-only access
        if (i < 0 || i >= ps->size) {
            throw std::out_of_range("Index out of range");
        }
        return ps->data[i];
    }

    char& operator[](int i) { // Read-write access with copy-on-write
        if (i < 0 || i >= ps->size) {
            throw std::out_of_range("Index out of range");
        }

        // Copy-on-write: Separate if multiple references exist
        if (ps->nrefs > 1) {
            _str* newPs = new _str(ps->size);
            strcpy(newPs->data, ps->data);
            if (--ps->nrefs == 0) {
                delete ps;
            }
            ps = newPs;
        }
        return ps->data[i];
    }


    friend std::ostream& operator<<(std::ostream& os, const Str& str);
};

std::ostream& operator<<(std::ostream& os, const Str& str) {
    os << str.str();
    return os;
}

