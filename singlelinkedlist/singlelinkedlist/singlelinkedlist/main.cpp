#include <iostream>
#include <iterator>
#include <numeric>

template <typename T>
class LList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    size_t list_size;

public:
    LList() : head(new Node(T())), list_size(0) {} // Служебный узел с значением по умолчанию

    /*служебного узла делает код более чистым и менее подверженным ошибкам, так как минимизирует 
        количество условий, которые нужно проверять при работе с пустым списком и при добавлении и удалении узлов*/


    ~LList() { clear(); delete head; } // Очистка и удаление служебного узла

    // Правило трёх
    LList(const LList& other) : head(new Node(T())), list_size(0) {
        for (Node* curr = other.head->next; curr != nullptr; curr = curr->next) {
            push_back(curr->data);
        }
    }

    LList& operator=(const LList& other) {
        if (this != &other) {
            clear();
            for (Node* curr = other.head->next; curr != nullptr; curr = curr->next) {
                push_back(curr->data);
            }
        }
        return *this;
    }

    LList(LList&& other) noexcept : head(other.head), list_size(other.list_size) {
        other.head = new Node(T());
        other.list_size = 0;
    }

    LList& operator=(LList&& other) noexcept {
        if (this != &other) {
            clear();
            delete head;
            head = other.head;
            list_size = other.list_size;
            other.head = new Node(T());
            other.list_size = 0;
        }
        return *this;
    }

    void push_back(const T& value) {
        Node* new_node = new Node(value);
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = new_node;
        list_size++;
    }

    void push_front(const T& value) {
        Node* new_node = new Node(value);
        new_node->next = head->next;
        head->next = new_node;
        list_size++;
    }

    void insert(size_t idx, const T& value) {
        if (idx > list_size) throw std::out_of_range("Index out of range");
        Node* new_node = new Node(value);
        Node* curr = head;
        for (size_t i = 0; i < idx; ++i) {
            curr = curr->next;
        }
        new_node->next = curr->next;
        curr->next = new_node;
        list_size++;
    }

    void pop_back() {
        if (empty()) throw std::underflow_error("List is empty");
        Node* curr = head;
        while (curr->next && curr->next->next) {
            curr = curr->next;
        }
        delete curr->next;
        curr->next = nullptr;
        list_size--;
    }

    void pop_front() {
        if (empty()) throw std::underflow_error("List is empty");
        Node* to_delete = head->next;
        head->next = to_delete->next;
        delete to_delete;
        list_size--;
    }

    void remove_at(size_t index) {
        if (index >= list_size) throw std::out_of_range("Index out of range");
        Node* curr = head;
        for (size_t i = 0; i < index; ++i) {
            curr = curr->next;
        }
        Node* to_delete = curr->next;
        curr->next = to_delete->next;
        delete to_delete;
        list_size--;
    }

    T& operator[](const size_t index) {
        if (index >= list_size) throw std::out_of_range("Index out of range");
        Node* curr = head->next;
        for (size_t i = 0; i < index; ++i) {
            curr = curr->next;
        }
        return curr->data;
    }

    const T& operator[](const size_t index) const {
        if (index >= list_size) throw std::out_of_range("Index out of range");
        Node* curr = head->next;
        for (size_t i = 0; i < index; ++i) {
            curr = curr->next;
        }
        return curr->data;
    }

    size_t size() const {
        return list_size;
    }

    bool empty() const {
        return list_size == 0;
    }

    void clear() {
        while (!empty()) {
            pop_front();
        }
    }

    T& front() {
        if (empty()) throw std::underflow_error("List is empty");
        return head->next->data;
    }

    const T& front() const {
        if (empty()) throw std::underflow_error("List is empty");
        return head->next->data;
    }

    T& back() {
        if (empty()) throw std::underflow_error("List is empty");
        Node* curr = head->next;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        return curr->data;
    }

    const T& back() const {
        if (empty()) throw std::underflow_error("List is empty");
        Node* curr = head->next;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        return curr->data;
    }

    struct iterator {
        Node* current;
        iterator(Node* node) : current(node) {}

        T& operator*() { return current->data; }
        iterator& operator++() {
            if (current) current = current->next;
            return *this;
        }
        bool operator!=(const iterator& other) const { return current != other.current; }
    };

    iterator begin() { return iterator(head->next); }
    iterator end() { return iterator(nullptr); }

};

int main() {
    LList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_front(0);
    /*list.push_front(3);
    list.push_back(4);
    list.push_front(5);
    list.push_back(6);*/

    std::cout << "Front: " << list.front() << std::endl;   
    std::cout << "Back: " << list.back() << std::endl;

    for (const auto& value : list) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    list.pop_front();
    list.pop_back();

    std::cout << "List after pop_front and pop_back: ";
    for (const auto& value : list) {
        std::cout << value << " "; // Outputs: 1 
    }
    std::cout << std::endl;

    return 0;
}