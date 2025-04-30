#include "PH.h"

PH::PH(int length) : L(length) {
    kp.resize(L + 1);
    kp[0] = 1;
    // ��������� ������� k �� ������ Q
    for (int i = 1; i <= L; ++i) {
        kp[i] = static_cast<int>((static_cast<long long>(kp[i - 1]) * k) % Q); //����� �������������� � int ����� ����������
    }
}

PH::~PH() {}

int PH::Hash(const char* s) {
    long long h = 0;
    // ��������� �������������� ���
    for (int i = 0; i < L; ++i) {
        h = (h + static_cast<long long>(s[i]) * kp[L - 1 - i]) % Q;
    }
    // �����������, ��� ��������� ��������������� � ������ Q
    return static_cast<int>((h % Q + Q) % Q); // ����������� �� ������������� �������� �����
}

int PH::Shift(int h, char pref, char suff) {
    long long newHash = (static_cast<long long>(h) * k - static_cast<long long>(pref) * kp[L] + suff) % Q;
    // �����������, ��� ��������� ��������������� � ������ Q
    return static_cast<int>((newHash % Q + Q) % Q); // ����������� �� ������������� �������� �����
}