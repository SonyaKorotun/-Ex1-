#include "stdafx.h" // Если используете precompiled headers
#include <iostream>
#include "utils.h"

using namespace std;

int main() {
    // 8. Z-strings
    char str[] = "Hello!";
    cout << "String: " << str << endl;
    cout << "strlen(str): " << strlen(str) << ", sizeof(str): " << sizeof(str) << endl;

    char t[32];
    string_copy(t, str);
    cout << "Copied string: " << t << endl;

    cout << "Len: " << len(str) << endl;

    cout << "Compare: " << compare("abc", "abd") << endl;
    cout << "Compare: " << compare("abc", "abc") << endl;
    cout << "Compare: " << compare("abd", "abc") << endl;

    return 0;
}