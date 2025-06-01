#include <iostream>
#include "windows.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "Str.h"

void f() {
    Str s1 = "abc";
    Str s2 = "xyz";
    Str s3 = "abc";

    std::cout << "s1 == s3: " << (s1 == s3) << std::endl;
    std::cout << "s1 != s2: " << (s1 != s2) << std::endl;
    std::cout << "s1 < s2: " << (s1 < s2) << std::endl;
    std::cout << "s1 > s2: " << (s1 > s2) << std::endl;
    std::cout << "s1 <= s3: " << (s1 <= s3) << std::endl;
    std::cout << "s1 >= s2: " << (s1 >= s2) << std::endl;
}

int main() {
    _CrtMemState sOld;
    _CrtMemState sNew;
    _CrtMemState sDiff;
    _CrtMemCheckpoint(&sOld); // take a snapshot

    f(); // вызываем функцию f

    if (_CrtMemDifference(&sDiff, &sOld, &sNew)) {
        OutputDebugString(L"-----------_CrtMemDumpStatistics ---------");
        _CrtMemDumpStatistics(&sDiff);
        OutputDebugString(L"-----------_CrtMemDumpAllObjectsSince ---------");
        _CrtMemDumpAllObjectsSince(&sOld);
        OutputDebugString(L"-----------_CrtDumpMemoryLeaks ---------");
        _CrtDumpMemoryLeaks();
    }

    return 0;
}