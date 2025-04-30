#ifndef WF_H
#define WF_H

#include <iostream>
#include <string>
#include <stdexcept>

class WF {
private:
    int* pm;
    int M;
    int N;
    std::string s;
    std::string t;
    bool initialized;

public:
    WF();
    ~WF();

    void Init(const char* sc, const char* tc);

    int Rows() const;
    int Columns() const;
    int Get(int i, int j) const;
    void Set(int i, int j, int val);
    int Distance() const;

    // «апрещаем копирование и присваивание
    WF(const WF&) = delete;
    WF& operator=(const WF&) = delete;
};

#endif
