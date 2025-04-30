#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdexcept> // Для исключений
#include <cstddef>   // Для size_t

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t listSize;

public:
    // Конструкторы, деструктор и оператор присваивания (Правило трех/пяти)
    List() : head(nullptr), tail(nullptr), listSize(0) {}

    List(const List& other) : head(nullptr), tail(nullptr), listSize(0) {
        // Копирующий конструктор
        Node* current = other.head;
        while (current != nullptr) {
            push_back(current->data);
            current = current->next;
        }
    }

    List& operator=(const List& other) {
        // Оператор присваивания
        if (this != &other) {
            clear(); // Освобождаем текущий список
            Node* current = other.head;
            while (current != nullptr) {
                push_back(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    ~List() {
        clear(); // Деструктор
    }

    // Методы

    void push_back(const T& value) {
        Node* newNode = new Node(value);
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

    void push_front(const T& value) {
        Node* newNode = new Node(value);
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

    void insert(size_t idx, const T& value) {
        if (idx > listSize) {
            throw std::out_of_range("Index out of range");
        }

        if (idx == 0) {
            push_front(value);
            return;
        }

        if (idx == listSize) {
            push_back(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* current = head;
        for (size_t i = 0; i < idx - 1; ++i) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
        listSize++;
    }

    void pop_back() {
        if (empty()) {
            throw std::out_of_range("List is empty");
        }

        if (listSize == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else {
            Node* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = nullptr;
        }
        listSize--;
    }

    void pop_front() {
        if (empty()) {
            throw std::out_of_range("List is empty");
        }

        Node* temp = head;
        head = head->next;
        delete temp;

        if (head == nullptr) {
            tail = nullptr; // Список стал пустым
        }
        listSize--;
    }

    void remove_at(size_t index) {
        if (index >= listSize) {
            throw std::out_of_range("Index out of range");
        }

        if (index == 0) {
            pop_front();
            return;
        }

        if (index == listSize - 1) {
            pop_back();
            return;
        }

        Node* current = head;
        for (size_t i = 0; i < index - 1; ++i) {
            current = current->next;
        }

        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        listSize--;
    }

    T& operator[](size_t index) {
        if (index >= listSize) {
            throw std::out_of_range("Index out of range");
        }

        Node* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    const T& operator[](size_t index) const {
        if (index >= listSize) {
            throw std::out_of_range("Index out of range");
        }

        Node* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    size_t size() const {
        return listSize;
    }

    bool empty() const {
        return listSize == 0;
    }

    void clear() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
        listSize = 0;
    }

    T front() const {
        if (empty()) {
            throw std::out_of_range("List is empty");
        }
        return head->data;
    }

    T back() const {
        if (empty()) {
            throw std::out_of_range("List is empty");
        }
        return tail->data;
    }

    // ListIterator
    class ListIterator {
    private:
        Node* current;

    public:
        ListIterator(Node* start) : current(start) {}

        T& operator*() {
            if (current == nullptr) {
                throw std::out_of_range("Dereferencing a null iterator");
            }
            return current->data;
        }

        const T& operator*() const {
            if (current == nullptr) {
                throw std::out_of_range("Dereferencing a null iterator");
            }
            return current->data;
        }

        ListIterator& operator++() {
            if (current != nullptr) {
                current = current->next;
            }
            return *this;
        }

        ListIterator operator++(int) {
            ListIterator temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const ListIterator& other) const {
            return current == other.current;
        }

        bool operator!=(const ListIterator& other) const {
            return current != other.current;
        }
    };

    ListIterator begin() {
        return ListIterator(head);
    }

    ListIterator end() {
        return ListIterator(nullptr);
    }
};

#endif

