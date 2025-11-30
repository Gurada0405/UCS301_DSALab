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

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << "->";
            }
            temp = temp->next;
        }
        cout << "->NULL" << endl;
    }

    void reverseIterative() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        
        while (current != nullptr) {
            next = current->next;  
            current->next = prev;  
            prev = current;        
            current = next;        
        }
        
        head = prev;  
    }

    void reverseRecursive() {
        head = reverseRecursiveUtil(head);
    }
    
    Node* reverseRecursiveUtil(Node* node) {
        if (node == nullptr || node->next == nullptr) {
            return node;
        }
        
        Node* rest = reverseRecursiveUtil(node->next);
        node->next->next = node;
        node->next = nullptr;
        
        return rest;
    }

    ~LinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;
    
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    for (int i = 0; i < n; i++) {
        list.insertAtEnd(arr[i]);
    }
    
    cout << "Original Linked List: ";
    list.display();
    
    list.reverseIterative();
    cout << "Reversed Linked List (Iterative): ";
    list.display();
    
    list.reverseRecursive();
    cout << "Reversed back (Recursive): ";
    list.display();
    
    return 0;
}