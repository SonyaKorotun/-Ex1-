#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "LList.h"
#include "IPriorityQueue.h"
#include <algorithm> // For std::sort
#include <vector>
#include <limits>

template <typename T>
class PriorityQueue : public LList<T>, public IPriorityQueue<T> {
public:
    PriorityQueue() : LList<T>() {}
    ~PriorityQueue() override {}

    //Copy Constructor
    PriorityQueue(const PriorityQueue& other) : LList<T>(other) {}

    void push(const T& data) override {
        LList<T>::push_back(data);
        // Maintain priority order by sorting after each insertion
        std::vector<T> tempVector;

        // Use LList's front and pop_front to access elements
        LList<T> tempList = *this; // Create a copy to iterate without modifying the original list
        while (!tempList.empty()) {
            tempVector.push_back(tempList.front());
            tempList.pop_front();
        }

        std::sort(tempVector.begin(), tempVector.end(), std::greater<T>()); // Sort in descending order (highest priority first)

        // Clear the list and re-insert in sorted order
        while (!LList<T>::empty()) {
            LList<T>::pop_front();
        }

        for (const T& item : tempVector) {
            LList<T>::push_back(item);
        }
    }

    void pop() override {
        if (LList<T>::empty()) {
            throw std::out_of_range("pop() called on empty PriorityQueue");
        }
        LList<T>::pop_front();
    }

    T top() const override {
        if (LList<T>::empty()) {
            throw std::out_of_range("top() called on empty PriorityQueue");
        }
        return LList<T>::front();
    }

    size_t size() const override {
        return LList<T>::size();
    }

    bool empty() const override {
        return LList<T>::empty();
    }
};

#endif

