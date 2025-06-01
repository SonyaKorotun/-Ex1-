#ifndef IPRIORITYQUEUE_H
#define IPRIORITYQUEUE_H

#include <cstddef> // For size_t

template <typename T>
struct IPriorityQueue {
    virtual void push(const T& data) = 0;
    virtual void pop() = 0;
    virtual T top() const = 0;
    virtual size_t size() const = 0;
    virtual bool empty() const = 0;
    virtual ~IPriorityQueue() {}
};

#endif

