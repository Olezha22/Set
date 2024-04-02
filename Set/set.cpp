#include "set.h"



template <typename T>
Set<T>::Set() : head(nullptr), size(0) 
{
}

template <typename T>
Set<T>::Set(const Set& S) : head(S.head), size(S.size)
{
}

template <typename T>
Set<T>::Set(T* elements, int n) : head(elements), size(n)
{
}

template <typename T>
Set<T>::~Set()
{
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





template<typename T>
Set<T>& Set<T>::add(T x)
{
    if (!contain(x)) {
        Node* newNode = new Node;
        newNode->value = x;
        newNode->next = head;
        head = newNode;
        ++size;
    }
    return *this;
}



template<typename T>
Set<T>& Set<T>::add(T* x, int n)
{
    for (int i = 0; i < n; ++i) {
        add(x[i]);
    }
    return *this;
}

template<typename T>
int Set<T>::getSize() const {
    return size;
}


template<typename T>
bool Set<T>::contain(const T& x) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->value == x) {
            return true;
        }
        current = current->next;
    }
    return false;
}


template<typename T>
Set<T>& Set<T>::remove(const T& x) {
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


template<typename T>
void Set<T>::print() const {
    Node* current = head;
    std::cout << "Set elements: [ ";
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << " ]" << std::endl;
}



template <typename T>
void Set<T>::deleteAll() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    size = 0;
}


template<typename T>
Set<T> Set<T>::unionSet(const Set& S) const {
    Set<T> result(*this);
    Node* current = S.head;
    while (current != nullptr) {
        result.add(current->value);
        current = current->next;
    }
    return result;
}

template<typename T>
Set<T> Set<T>::intersect(const Set& S) const {
    Set<T> result;
    Node* current = head;
    while (current != nullptr) {
        if (S.contain(current->value))
            result.add(current->value); 
        current = current->next;
    }
    return result;
}

template<typename T>
Set<T> Set<T>::difference(const Set& S) const {
    Set<T> result(*this); 
    Node* current = S.head;
    while (current != nullptr) {
        result.remove(current->value); 
        current = current->next;
    }
    return result;
}

template<typename T>
Set<T> Set<T>::sym_difference(const Set& S) const {
    Set<T> intersectSet = intersect(S);
    Set<T> unionSet = unionSet(S);
    return unionSet.difference(intersectSet); 
}