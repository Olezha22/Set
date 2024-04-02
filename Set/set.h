#pragma once
#include <iostream>
template <typename T>
class Set
{
private:

    struct Node
    {
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
    int getSize()const;
    Set unionSet(const Set&) const;
    Set intersect(const Set&) const;
    Set difference(const Set&) const;
    Set sym_difference(const Set&) const;
    bool contain(const T& x)const;
    Set& remove(const T& x);
    void print() const;
    void deleteAll();
};

