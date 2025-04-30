#pragma once
#include <string.h>
#include <iostream>

class _str {
public:
    int nrefs;
    int size;
    char* data;

    _str(int sz) : nrefs(1), size(sz) {
        data = new char[size + 1];
        data[0] = 0; // Ensure null termination
    }

    ~_str() {
        delete[] data;
    }

    _str(const _str& other) : nrefs(1), size(other.size) { // Copy constructor
        data = new char[size + 1];
        strcpy(data, other.data);
    }

    _str& operator=(const _str& other) { // Assignment operator
        if (this != &other) {
            size = other.size;
            data = new char[size + 1];
            strcpy(data, other.data);
        }
        return *this;
    }
};