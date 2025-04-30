#pragma once
#include <iostream>
#include <string.h>

class Str {
private:
    char* m_pszText;
    int m_nLength;

public:
    Str() : m_pszText(nullptr), m_nLength(0) {
        m_pszText = new char[1];
        m_pszText[0] = '\0';
    }

    Str(const char* pszText) : m_nLength(strlen(pszText)) {
        m_pszText = new char[m_nLength + 1];
        strcpy(m_pszText, pszText);
    }

    Str(const Str& other) : m_nLength(other.m_nLength) {
        m_pszText = new char[m_nLength + 1];
        strcpy(m_pszText, other.m_pszText);
    }

    ~Str() {
        delete[] m_pszText;
        m_pszText = nullptr;
    }

    Str& operator=(const Str& other) {
        if (this != &other) {
            delete[] m_pszText; 
            m_nLength = other.m_nLength;
            m_pszText = new char[m_nLength + 1];
            strcpy(m_pszText, other.m_pszText);
        }
        return *this;
    }

    operator const char* () const {
        return m_pszText;
    }

    Str& operator+=(const char* sz) {
        int szLength = strlen(sz);
        int newLength = m_nLength + szLength;
        char* newText = new char[newLength + 1];

        strcpy(newText, m_pszText);
        strcat(newText, sz);

        delete[] m_pszText; 
        m_pszText = newText;
        m_nLength = newLength;

        return *this;
    }

    Str operator+(const char* sz) const {
        Str result(m_pszText);
        result += sz;          
        return result;            
    }
};
