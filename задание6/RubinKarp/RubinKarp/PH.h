#ifndef RUBINKARP_PH_H
#define RUBINKARP_PH_H

#include <iostream>
#include <vector>

class PH {
private:
    static const int k = 257;  // ��������� �����, ������ 255
    static const int Q = 65521; // ���������� ������� ������� �����

    std::vector<int> kp; // ������ �������� k �� ������ Q
    int L;                 // ����� ����

public:
    PH(int length);         // �����������
    ~PH();                // ����������

    int Hash(const char* s); // ���������� ����
    int Shift(int h, char pref, char suff); // ����� ����
};

#endif // RUBINKARP_PH_H