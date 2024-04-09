#pragma once

template<typename Key, typename Value>
class Table {
private:
    struct Node {
        Key key;
        Value* value;
        int size;
        Node* next;

        Node(Key key, const Value* values, int n) : key(key), size(n), next(nullptr) {
            value = new Value[n];
            for (int i = 0; i < n; ++i) {
                value[i] = values[i];
            }
        }

        ~Node() {
            delete[] value;
        }

        void addValue(Value newValue) {
            Value* temp = new Value[size + 1];
            for (int i = 0; i < size; ++i) {
                temp[i] = value[i];
            }
            temp[size] = newValue;
            delete[] value;
            value = temp;
            ++size;
        }

        int getNodeSize() {
            return size;
        }

        bool contains(const Value& item) const {
            for (int i = 0; i < size; ++i) {
                if (value[i] == item) {
                    return true;
                }
            }
            return false;
        }
    };

    Node* head;

public:
    Table() : head(nullptr) {}

    ~Table() {
        clear();
    }

    void add(Key key, const Value* values, int n) {
        for (Node* cur = head; cur != nullptr; cur = cur->next) {
            if (cur->key == key) {
                for (int i = 0; i < n; ++i) {
                    cur->addValue(values[i]);
                }
                return;
            }
        }

        Node* newNode = new Node(key, values, n);
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
    }

    void add(Key key, Value value) {
        add(key, &value, 1);
    }

    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void print() {
        for (Node* temp = head; temp != nullptr; temp = temp->next) {
            std::cout << temp->key << ": ";
            std::cout << "[ ";
            for (int i = 0; i < temp->size; ++i) {
                std::cout << temp->value[i] << ". ";
            }
            std::cout << "]";
            std::cout << std::endl;
        }
    }

    int getSize()
    {
        int size = 0;
        for (Node* temp = head; temp != nullptr; temp = temp->next) {
            ++size;
        }
        return size;
    }


    Table<Name, int>* calculateVisits() {
        Table<Name, int>* visits = new Table<Name, int>();

        for (Node* temp = head; temp != nullptr; temp = temp->next) {
            for (int i = 0; i < temp->size; ++i) {
                visits->add(temp->value[i], 1);
            }
            visits->add(temp->key, 1);
        }

        return visits;
    }


    void printUnFriendlyName() {
        int minVisits = INT_MAX;
        Set<Name> leastVisitedGuests;

        for (Node* temp = head; temp != nullptr; temp = temp->next) {
            int numVisits = temp->getNodeSize();
            if (numVisits < minVisits) { 
                minVisits = numVisits;
                leastVisitedGuests.deleteAll();
                leastVisitedGuests.add(temp->key);
            }
            else if (numVisits == minVisits) {
                leastVisitedGuests.add(temp->key); 
            }
        }

        std::cout << "Least visited guests: ";
        leastVisitedGuests.print();

    }


    void printMostFriendlyName(int maxSize) {
        Set<Name> visitedAllGuests;

        for (Node* temp = head; temp != nullptr; temp = temp->next) {
            if (temp->getNodeSize() == maxSize) {
                visitedAllGuests.add(temp->key); 
            }
        }

        std::cout << "Guests who visited all friends: ";
        visitedAllGuests.print();

    }

    void checkCloseFriends(int numFriends) {
        Set<Name> closeFriends;

        
        for (Node* guest = head; guest != nullptr; guest = guest->next) {
            Set<Name> guestFriends;
            guestFriends.add(guest->key); 
            for (int i = 0; i < guest->size; ++i) {
                guestFriends.add(guest->value[i]); 
            }

            for (Node* otherGuest = head; otherGuest != nullptr; otherGuest = otherGuest->next) {
                if (guest != otherGuest) { 
                    Set<Name> commonFriends = guestFriends.intersect(Set<Name>(otherGuest->value, otherGuest->size));
                    if (commonFriends.getSize() == numFriends - 1) {
                        closeFriends.add(guest->key);
                        break;
                    }
                }
            }
        }

        if (closeFriends.getSize() == 0) {
            std::cout << "There are no close circles of " << numFriends << " friends." << std::endl;
        }
        else {
            std::cout << "Close circle of " << numFriends << " friends: ";
            closeFriends.print();
        }
    }



    Table<Name, Set<Name>>* buildGuestsTable() {
        Table<Name, Set<Name>>* guestsTable = new Table<Name, Set<Name>>();

        for (Node* temp = head; temp != nullptr; temp = temp->next) {
            Set<Name> guests;

            for (int i = 0; i < temp->size; ++i) {
                guests.add(temp->value[i]);
            }

            for (Node* curr = head; curr != nullptr; curr = curr->next) {
                if (curr != temp) { 
                    if (curr->contains(temp->key)) {
                        Set<Name> set1;
                        set1.add(curr->key);
                        guestsTable->add(temp->key, set1);
                    }
                }
            }
        }

        return guestsTable;
    }


    bool canReachDestination(City start, City destination) {

        for (Node* node = head; node != nullptr; node = node->next) {
            if ((start == node->key && node->contains(destination)) ||
                (destination == node->key && node->contains(start))) {
                return true;
            }
        }

        for (Node* node1 = head; node1 != nullptr; node1 = node1->next) {
            for (Node* node2 = head; node2 != nullptr; node2 = node2->next) {
                if (node1 != node2 && node1->contains(node2->key) && node2->contains(destination) || node1 != node2 && node1->contains(node2->key) && node2->contains(start)) {
                    return true;
                }
            }
        }

        
        return false;
    }


    };