#include <iostream>
#include <string>
#include <random>
#include "PH.h"

using namespace std;

int main() {
    // --- Тестирование класса PH ---
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 255); // Генерируем символы ASCII

    int L = 75;
    string text(L, ' ');
    for (int i = 0; i < L; ++i) {
        text[i] = static_cast<char>(distrib(gen));
    }
    const char* ctext = text.c_str();
    //cout << ctext << endl;

    for (int len = 1; len < L; ++len) {
        PH ph(len);

        for (int i = 0; i <= L - len; ++i) {
            string sub = text.substr(i, len);
            const char* csub = sub.c_str();
            // cout << csub << endl;
            int h = ph.Hash(csub);
            int hs;

            if (i < L - len) {
                hs = ph.Shift(h, text[i], text[i + len]);
                string shiftedSub = text.substr(i + 1, len);
                const char* cshiftedSub = shiftedSub.c_str();
                int hDirect = ph.Hash(cshiftedSub);

                if (hs != hDirect) {
                    cout << "Ошибка! Длина: " << len << ", позиция: " << i << endl;
                    cout << "Shifted Hash: " << hs << ", Direct Hash: " << hDirect << endl;
                    return 1; // Выход, если обнаружена ошибка
                }
            }
        }
    }

    cout << "Все тесты пройдены!" << endl;

    // --- Алгоритм Рабина-Карпа ---
    string pattern = "abc";
    string textToSearch = "abracadabraabcababc";

    int patternLength = pattern.length();
    PH patternHash(patternLength);
    int patternHashValue = patternHash.Hash(pattern.c_str());

    int textLength = textToSearch.length();
    if (textLength < patternLength) {
        cout << "Образец длиннее текста для поиска." << endl;
        return 0;
    }

    PH textHash(patternLength);
    int textHashValue = textHash.Hash(textToSearch.substr(0, patternLength).c_str());

    for (int i = 0; i <= textLength - patternLength; ++i) {
        if (patternHashValue == textHashValue) {
            if (textToSearch.substr(i, patternLength) == pattern) {
                cout << "Образец найден в позиции: " << i << endl;
            }
        }
        if (i < textLength - patternLength) {
            textHashValue = textHash.Shift(textHashValue, textToSearch[i], textToSearch[i + patternLength]);
        }
    }

    return 0;
}