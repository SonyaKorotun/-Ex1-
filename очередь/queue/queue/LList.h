#ifndef LLIST_H
#define LLIST_H

#include "ILinkedList.h"
#include <memory>  // For smart pointers
#include <stdexcept> // For exceptions

template <typename T>
class LList : public ILinkedList<T> {
private:
    struct Node {
        T data;
        std::shared_ptr<Node> next;  // Use shared_ptr to manage nodes
        Node(const T& data) : data(data), next(nullptr) {}
    };

    std::shared_ptr<Node> head;
    std::shared_ptr<Node> tail;
    size_t listSize;

public:
    LList() : head(nullptr), tail(nullptr), listSize(0) {}

    // Copy constructor
    LList(const LList& other) : head(nullptr), tail(nullptr), listSize(0) {
        if (!other.empty()) {
            std::shared_ptr<Node> currentOther = other.head;
            while (currentOther) {
                push_back(currentOther->data);
                currentOther = currentOther->next;
            }
        }
    }

    // Copy assignment operator
    LList& operator=(const LList& other) {
        if (this != &other) {
            // Clear the current list
            while (!empty()) {
                pop_front();
            }

            // Copy from the other list
            if (!other.empty()) {
                std::shared_ptr<Node> currentOther = other.head;
                while (currentOther) {
                    push_back(currentOther->data);
                    currentOther = currentOther->next;
                }
            }
        }
        return *this;
    }
    ~LList() override {}

    void push_back(const T& data) override {
        std::shared_ptr<Node> newNode = std::make_shared<Node>(data);
        if (empty()) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        listSize++;
    }

    void push_front(const T& data) override {
        std::shared_ptr<Node> newNode = std::make_shared<Node>(data);
        if (empty()) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
        listSize++;
    }

    void pop_back() override {
        if (empty()) {
            throw std::out_of_range("pop_back() called on empty list");
        }

        if (listSize == 1) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            std::shared_ptr<Node> current = head;
            while (current->next != tail) {
                current = current->next;
            }
            current->next = nullptr;
            tail = current;
        }
        listSize--;
    }

    void pop_front() override {
        if (empty()) {
            throw std::out_of_range("pop_front() called on empty list");
        }

        head = head->next;
        if (head == nullptr) {
            tail = nullptr; // If list becomes empty
        }
        listSize--;
    }

    T front() const override {
        if (empty()) {
            throw std::out_of_range("front() called on empty list");
        }
        return head->data;
    }

    T back() const override {
        if (empty()) {
            throw std::out_of_range("back() called on empty list");
        }
        return tail->data;
    }

    size_t size() const override {
        return listSize;
    }

    bool empty() const override {
        return listSize == 0;
    }
};

#endif

