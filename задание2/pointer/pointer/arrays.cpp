#include "stdafx.h" // Если используете precompiled headers
#include <iostream>

using namespace std;

// 6. Rotate array
void rotate(int a[], int n) {
    int x = a[0];
    for (int i = 1; i < n; i++)
        a[i - 1] = a[i];
    a[n - 1] = x;
}

// 7. Rotate array with direction
void rotate(int a[], int n, bool clockwise) {
    if (clockwise) {
        int x = a[n - 1];
        for (int i = n - 1; i > 0; i--)
            a[i] = a[i - 1];
        a[0] = x;
    }
    else {
        rotate(a, n); // Use existing rotate function for counter-clockwise
    }
}


int main() {
    // 5. Arrays
    int a[5]{ 1,2,3,4,5 };
    cout << "Array a: ";
    for (int i = 0; i < 5; i++)
        cout << a[i] << ' ';
    cout << endl;

    cout << "Array a (using pointer): ";
    for (int* p = a; p - a < 5; p++)
        cout << *p << ' ';
    cout << endl;

    // 6. Rotate array test
    cout << "Rotate array: ";
    rotate(a, 5);
    for (int i = 0; i < 5; i++)
        cout << a[i] << ' ';
    cout << endl;

    // Reset array
    int b[5]{ 1,2,3,4,5 };

    // 7. Rotate array with direction
    cout << "Rotate array clockwise: ";
    rotate(b, 5, true);
    for (int i = 0; i < 5; i++)
        cout << b[i] << ' ';
    cout << endl;

    return 0;
}