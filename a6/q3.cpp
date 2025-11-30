#include <iostream>
using namespace std;

class DNode {
public:
    int data;
    DNode* next;
    DNode* prev;
    
    DNode(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class CNode {
public:
    int data;
    CNode* next;
    
    CNode(int value) {
        data = value;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    DNode* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int value) {
        DNode* newNode = new DNode(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            DNode* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    int getSize() {
        int count = 0;
        DNode* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        
        DNode* temp = head;
        cout << "Doubly Linked List: NULL <-> ";
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    ~DoublyLinkedList() {
        DNode* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

class CircularLinkedList {
private:
    CNode* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int value) {
        CNode* newNode = new CNode(value);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        } else {
            CNode* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    int getSize() {
        if (head == nullptr) {
            return 0;
        }
        
        int count = 0;
        CNode* temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
        
        return count;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        
        CNode* temp = head;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)\n";
    }

    ~CircularLinkedList() {
        if (head == nullptr) return;
        
        CNode* current = head;
        CNode* nextNode;
        do {
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);
    }
};

int main() {
    DoublyLinkedList dlist;
    CircularLinkedList clist;
    
    cout << "Creating Doubly Linked List with values: 10, 20, 30, 40, 50\n";
    int dvalues[] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; i++) {
        dlist.insertAtEnd(dvalues[i]);
    }
    dlist.display();
    cout << "Size of Doubly Linked List: " << dlist.getSize() << endl;
    
    cout << "\n" << string(50, '-') << "\n" << endl;
    
    cout << "Creating Circular Linked List with values: 5, 15, 25, 35\n";
    int cvalues[] = {5, 15, 25, 35};
    for (int i = 0; i < 4; i++) {
        clist.insertAtEnd(cvalues[i]);
    }
    clist.display();
    cout << "Size of Circular Linked List: " << clist.getSize() << endl;
    
    return 0;
}