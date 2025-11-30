#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class CircularLinkedList 
{
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void displayWithHeadRepetition() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        
        cout << "Circular Linked List with head repetition: ";
        Node* temp = head;
        int headValue = head->data;
        
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        
        cout << headValue << endl;
    }

    void displayNormal() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        
        cout << "Normal display: ";
        Node* temp = head;
        do {
            cout << temp->data;
            if (temp->next != head) {
                cout << " → ";
            }
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    ~CircularLinkedList() {
        if (head == nullptr) return;
        
        Node* current = head;
        Node* nextNode;
        do {
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);
    }
};

int main() {
    CircularLinkedList list;
    
    int arr[] = {20, 100, 40, 80, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    for (int i = 0; i < n; i++) {
        list.insertAtEnd(arr[i]);
    }
    
    cout << "Input: 20 → 100 → 40 → 80 → 60 (circular)" << endl;
    list.displayNormal();
    list.displayWithHeadRepetition();
    
    return 0;
}