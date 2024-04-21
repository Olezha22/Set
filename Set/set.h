#pragma once
#include <iostream>

enum class Product { Bread, Butter, Milk, Cheese, Meat, Fish, Salt, Sugar, Tea, Coffee, Water };
enum class Name {
    Oleksa, Yuliya, Kateryna, Vitaliy, Artemiy, Markiyan, Vladyslav, Oleh, Kseniya,
    Olga, Sofiya, Andriy, Ivan, Yuriy, Taras, Kostyantyn, Halyna, Vasyl, Solomiya,
    Mykola, Iryna
};
enum class City {
    Kyiv, Lviv, Kharkiv, Dnipro, Odesa, Ternopil, Uzhgorod, Lutsk, Rivne, Ivano_Frankivsk,
    Zhytomyr, Sumy, Donetsk, Luhansk, Zaporizhzhia, Simferopol, Chernivtsi, Khmelnytskyi,
    Vinnytsia, Cherkasy, Poltava, Chernihiv, Kropyvnytskyi, Mykolaiv, Kherson
};

std::ostream& operator<<(std::ostream& os, const Product& product);
std::ostream& operator<<(std::ostream& os, const Name& name);
std::ostream& operator<<(std::ostream& os, const City& city);

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
    Set();//oleh
    Set(const Set&);//andriy
    Set(T* elements, int n);//taras
    ~Set();//sofia
    Set& operator=(const Set&);
    Set& add(T x);//sofia
    Set& add(T* x, int n);//taras
    int getSize() const;//andriy
    Set unionSet(const Set&) const;//oleh
    Set unionSetIfNotContains(const Set&) const;
    Set intersect(const Set&) const;//andriy
    Set difference(const Set&) const;//taras
    Set sym_difference(const Set&) const;//sofia
    bool contain(const T& x) const;//taras
    Set& remove(const T& x);//sofia
    void print() const;//oleh
    void deleteAll();//sofia
    void calculateExp();
    Set& addIfNotContains(T x);
    Set<T>& addIfNotContains(T* x, int n);
    Set<T>& repeatedChars(bool is);
    void writeTo(std::ostream& os) const;//oleh
    T operator[](int index) const;
};


int digits(int n);
void task31(char chars[]);
void task32(char chars[]);
void task33(char chars[]);
void eratosthenes(int n);




template <typename T>
T Set<T>::operator[](int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }

    Node* current = head;
    int currentIndex = 0;
    while (current != nullptr) {
        if (currentIndex == index) {
            return current->value;
        }
        current = current->next;
        currentIndex++;
    }
}



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
template<typename T>
std::ostream& operator<<(std::ostream& os, const Set<T>& set) {
    set.writeTo(os);
    return os;
}

template <typename T>
void Set<T>::writeTo(std::ostream& os) const
{
    os << "Set elements: ";
    Node* current = head;
    while (current != nullptr) {
        
        os << current->value << " ";
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
Set<T>& Set<T>::repeatedChars(bool is) {
    const int SIZE = 256; 
    int occurrences[SIZE] = { 0 };

    Node* current = head;
    while (current != nullptr) {
        occurrences[(int)current->value]++;
        current = current->next;
    }

    deleteAll();
    
    for (int i = 0; i < SIZE; ++i) {
        if (is) {
            if (occurrences[i] >= 2) {
                add((char)i);
            }
        }
        else if (!is) {
            if (occurrences[i] == 1) {
                add((char)i);
            }
        }
        
    }
   
    return *this;
}


template <typename T>
Set<T>& Set<T>::addIfNotContains(T x) {
    if (!contain(x)) {
        Node* newNode = new Node;
        newNode->value = x;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }

        ++size;
        return *this;
    }
    return *this;
}

template <typename T>
Set<T>& Set<T>::addIfNotContains(T* x, int n) {
    for (int i = 0; i < n; ++i) {
        addIfNotContains(x[i]);
    }
    return *this;
}

template <typename T>
Set<T>& Set<T>::add(T x) {
    Node* newNode = new Node;
    newNode->value = x;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    ++size;
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
    if (size == 0)
    {
        std::cout << "Set is empty...\n";
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



template <typename T>
void Set<T>::calculateExp() {

    int numbers = 0;
    int signs = 0;
    int brackets = 0;
   
    Node* current = head;
    while (current != nullptr) {
        int currVal = (int)current->value;
        if (currVal > 47 && currVal < 58)
        {
            ++numbers;
        }
        else if(currVal == 43 || currVal == 45 || currVal == 47 || currVal == 42)
        {
            ++signs;
        }
        else if (currVal == 40 || currVal == 41)
        {
            ++brackets;
        }
        current = current->next;
    }
    
    if (brackets % 2 == 0) {
        std::cout << "Our expression has: \n" << "Numbers: " << numbers << "\n" << "Signs: " << signs << "\n" << "Brackets: " << brackets << "\n";
    }
    else {
        std::cout << "Invalid format: brackets is not valid\n";
    }
    




}



template <typename T>
Set<T> Set<T>::unionSetIfNotContains(const Set& S) const {
    Set<T> result;
    Node* current = head;
    while (current != nullptr) {
        result.add(current->value);
        current = current->next;
    }
    current = S.head;
    while (current != nullptr) {
        result.addIfNotContains(current->value);
        current = current->next;
    }
    return result;
}