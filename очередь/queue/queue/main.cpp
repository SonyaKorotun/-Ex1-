#include <iostream>
#include "PriorityQueue.h"

int main() {
    PriorityQueue<char> pq; // �������� ����� std::priority_queue pq; � #inlcude
    pq.push('a');
    pq.push('c');
    pq.push('b');
    pq.push('e');
    pq.push('b');
    pq.push('c');

    std::cout << pq.size() << std::endl;
    auto q = pq; // ����� ����������� ����������� � LList
    while (!pq.empty()) {
        std::cout << pq.top() << '\t';
        pq.pop();
    }
    std::cout << std::endl;
    std::cout << pq.size() << '\t' << q.size()
        << '\t' << q.top() << std::endl;

    return 0;
}