#include <iostream>
#include "windows.h"
#define _CRTDBG_MAP_ALLOC // to get more details
#include <stdlib.h>  
#include <crtdbg.h>   // for malloc and free
#include "Str.h"

void f() {
    Str s = "abcDEF";
    std::cout << "Original string: " << s << std::endl;
    Str reversed = !s; // Используем наш оператор логического отрицания
    std::cout << "Reversed string: " << reversed << std::endl;
}

int main() {
    _CrtMemState sOld;
    _CrtMemState sNew;
    _CrtMemState sDiff;
    _CrtMemCheckpoint(&sOld); // take a snapshot

    f(); // вызываем функцию f

    if (_CrtMemDifference(&sDiff, &sOld, &sNew)) { // if there is a difference
        OutputDebugString(L"-----------_CrtMemDumpStatistics ---------");
        _CrtMemDumpStatistics(&sDiff);
        OutputDebugString(L"-----------_CrtMemDumpAllObjectsSince ---------");
        _CrtMemDumpAllObjectsSince(&sOld);
        OutputDebugString(L"-----------_CrtDumpMemoryLeaks ---------");
        _CrtDumpMemoryLeaks();
    }

    return 0;
}