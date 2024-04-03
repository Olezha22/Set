#pragma once
#include <iostream>

template <typename T>
class Set {
private:
    struct Node {
        T value;
        Node* next;
    };
    Node* head;
    int size;

public:
    Set();
    Set(const Set&);
    Set(T* elements, int n);
    ~Set();
    Set& operator=(const Set&);
    Set& add(T x);
    Set& add(T* x, int n);
    int getSize() const;
    Set unionSet(const Set&) const;
    Set intersect(const Set&) const;
    Set difference(const Set&) const;
    Set sym_difference(const Set&) const;
    bool contain(const T& x) const;
    Set& remove(const T& x);
    void print() const;
    void deleteAll();
};

template <typename T>
Set<T>::Set() : head(nullptr), size(0) {}

template <typename T>
Set<T>::Set(const Set& S) : head(nullptr), size(0) {
    Node* current = S.head;
    while (current != nullptr) {
        this->add(current->value);
        current = current->next;
    }
}

template <typename T>
Set<T>::Set(T* elements, int n) : head(nullptr), size(0) {
    for (int i = 0; i < n; i++) {
        this->add(elements[i]);
    }
}

template <typename T>
Set<T>::~Set() {
    deleteAll();
}

template <typename T>
Set<T>& Set<T>::operator=(const Set<T>& S) {
    if (this != &S) {
        deleteAll();
        Node* S_current = S.head;
        while (S_current != nullptr) {
            add(S_current->value);
            S_current = S_current->next;
        }
    }
    return *this;
}

template <typename T>
Set<T>& Set<T>::add(T x) {
    if (!contain(x)) {
        Node* newNode = new Node;
        newNode->value = x;
        newNode->next = head;
        head = newNode;
        ++size;
    }
    return *this;
}

template <typename T>
Set<T>& Set<T>::add(T* x, int n) {
    for (int i = 0; i < n; ++i) {
        add(x[i]);
    }
    return *this;
}

template <typename T>
int Set<T>::getSize() const {
    return size;
}

template <typename T>
bool Set<T>::contain(const T& x) const {
    if (size == 0) {
        std::cout << "Set is empty." << std::endl;
        return;
    }
    Node* current = head;
    while (current != nullptr) {
        if (current->value == x) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template <typename T>
Set<T>& Set<T>::remove(const T& x) {
    if (size == 0) {
        std::cout << "Set is empty." << std::endl;
        return;
    }
    Node* current = head;
    Node* prev = nullptr;
    while (current != nullptr) {
        if (current->value == x) {
            if (prev == nullptr) {
                head = current->next;
            }
            else {
                prev->next = current->next;
            }
            delete current;
            size--;
            break;
        }
        prev = current;
        current = current->next;
    }
    return *this;
}

template <typename T>
void Set<T>::print() const {
    if (size == 0) {
        std::cout << "Set is empty." << std::endl;
        return;
    }
    Node* current = head;
    std::cout << "Set elements: [ ";
    while (current != nullptr) {
        std::cout << current->value << ". ";
        current = current->next;
    }
    std::cout << "]" << std::endl;
}

template <typename T>
void Set<T>::deleteAll() {
    if (size == 0) {
        std::cout << "Set is empty." << std::endl;
        return;
    }
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    size = 0;
}

template <typename T>
Set<T> Set<T>::unionSet(const Set& S) const {
    if (S.size == 0) {
        std::cout << "Set is empty." << std::endl;
        return;
    }
    Set<T> result;
    Node* current = head;
    while (current != nullptr) {
        result.add(current->value);
        current = current->next;
    }
    current = S.head;
    while (current != nullptr) {
        result.add(current->value);
        current = current->next;
    }
    return result;
}

template <typename T>
Set<T> Set<T>::intersect(const Set& S) const {
    if (S.size == 0) {
        std::cout << "Set is empty. So intersect is null" << std::endl;
        return;
    }
    Set<T> result;
    Node* current = head;
    while (current != nullptr) {
        if (S.contain(current->value))
            result.add(current->value);
        current = current->next;
    }
    return result;
}

template <typename T>
Set<T> Set<T>::difference(const Set& S) const {
    Set<T> result;
    Node* current = head;
    while (current != nullptr) {
        if (!S.contain(current->value)) {
            result.add(current->value);
        }
        current = current->next;
    }
    return result;
}

template <typename T>
Set<T> Set<T>::sym_difference(const Set& S) const {
    Set<T> unionS = this->unionSet(S);
    Set<T> intersectSet = this->intersect(S);
    return unionS.difference(intersectSet);
}

