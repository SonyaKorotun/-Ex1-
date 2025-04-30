#include "stdafx.h" // Если используете precompiled headers
#include <iostream>
#include "utils.h" // Include utils.h

using namespace std;

int main() {
    // Комментируем код из пунктов 1 и 2
    /*
    int x = 3;
    int *p = &x;
    cout << x << ' ' << *p << ' ' << p << endl;

    p++;
    cout << p << endl;
    cout << p - &x << endl;

    typedef unsigned char byte;
    byte *pb = (byte *)--p;
    for (byte *pt = pb; pt - pb<sizeof(int); pt++)
        cout << (int)*pt << ' ';
    cout << endl;
    */


    // 3. Swap function test
    int a = 3, b = 5;
    cout << "Before swap: a = " << a << ", b = " << b << endl;

    Swap(a, b);

    cout << "After swap: a = " << a << ", b = " << b << endl;


    return 0;
}