#include <iostream>
#include <memory>

using namespace std;

// 1. Класс Test
class Test {
public:
    int Val;

    Test() {
        cout << "Test constructor called" << endl;
        Val = 0;
    }

    ~Test() {
        cout << "Test destructor called" << endl;
    }
};

// 2. Функция foo
shared_ptr<Test> foo() {
    shared_ptr<Test> ptr = make_shared<Test>();
    ptr->Val = 42;
    return ptr;
}

// 5. Функция goo
Test* goo() {
    Test* ptr = new Test();
    ptr->Val = 99;
    return ptr;
}

int main() {
    // 3. Вызов foo и вывод Val
    cout << "--- shared_ptr example ---" << endl;
    {
        shared_ptr<Test> p = foo(); 
        cout << "Val: " << p->Val << endl;
    }
    cout << "--- end of shared_ptr example ---" << endl;


    // 6. Вызов goo - закомментирован, чтобы не было утечки памяти
    cout << "\n--- raw pointer example (goo) ---" << endl;
    /*{
        Test* p = goo();
        cout << "Val: " << p->Val << endl;
        delete p; // Обязательно освободить память
    }*/

    // 7. Дополнительный блок и сообщение "after block"
    cout << "\n--- shared_ptr and block example ---" << endl;
    {
        auto p = foo();
        cout << "Val: " << p->Val << endl;
    }
    cout << "after block" << endl;

    // 8. Объявление shared_ptr<Test> t и присвоение
    cout << "\n--- shared_ptr assignment example ---" << endl;
    {
        shared_ptr<Test> t; // Объявление
        auto p = foo();
        t = p;
        cout << "Val: " << p->Val << endl;
    }
    cout << "after block" << endl;

    return 0;
}