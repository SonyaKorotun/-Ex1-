#ifndef ILINKEDLIST_H
#define ILINKEDLIST_H

#include <cstddef> // For size_t

template <typename T>
struct ILinkedList {
    virtual void push_back(const T& data) = 0;
    virtual void push_front(const T& data) = 0;
    virtual void pop_back() = 0;
    virtual void pop_front() = 0;
    virtual T front() const = 0;
    virtual T back() const = 0;
    virtual size_t size() const = 0;
    virtual bool empty() const = 0;
    virtual ~ILinkedList() {}
};

#endif

