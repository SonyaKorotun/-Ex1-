#include <iostream>
#include "WF.h"
#include "WFOpt.h"

int main() {
    WF wf;

    //8. Инициализация и вывод матрицы
    try {
        wf.Init("no", "ono");

        std::cout << "Матрица WF:\n";
        for (int i = 0; i < wf.Rows(); ++i) {
            for (int j = 0; j < wf.Columns(); ++j) {
                std::cout << wf.Get(i, j) << "\t";
            }
            std::cout << std::endl;
        }

        //9. Вывод расстояния
        std::cout << "\nРасстояние WF: " << wf.Distance() << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка WF: " << e.what() << std::endl;
        return 1; // Exit with an error code
    }

    // 10. Проверка свойств метрики (неполная, т.к. это сложно автоматизировать)
    //    Здесь можно добавить больше проверок, например, для разных пар строк

    //Проверка Distance >=0
    try
    {
        wf.Init("aba", "cba");
        int dist = wf.Distance();
        if (dist < 0)
        {
            std::cout << "Нарушено свойство метрики d(x, y) >= 0" << std::endl;
        }
        else
        {
            std::cout << "Метрика неотрицательна!" << std::endl;
        }

    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка при проверке метрики: " << e.what() << std::endl;
    }

    //13. Проверка Optimized Distance
    const char* str1 = "no";
    const char* str2 = "ono";

    int distance_wf = 0;
    int distance_opt = 0;

    wf.Init(str1, str2);
    distance_wf = wf.Distance();


    distance_opt = DistanceOpt(str1, str2);

    std::cout << "Distance WF = " << distance_wf << std::endl;
    std::cout << "Distance Optimized = " << distance_opt << std::endl;
    if (distance_wf != distance_opt)
    {
        std::cout << "Result of WFOpt  and WF are different! " << std::endl;
    }
    else
        std::cout << "Result of WFOpt  and WF are the same! " << std::endl;

    return 0;
}