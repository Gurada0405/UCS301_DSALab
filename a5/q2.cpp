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
        cout << endl;
    }

    void countAndDelete(int key) {
        int count = 0;
        
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == key) {
                count++;
            }
            temp = temp->next;
        }
        
        cout << "Count: " << count << endl;
        
       
        while (head != nullptr && head->data == key) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
        }
        
        if (head != nullptr) {
            Node* current = head;
            while (current->next != nullptr) {
                if (current->next->data == key) {
                    Node* toDelete = current->next;
                    current->next = current->next->next;
                    delete toDelete;
                } else {
                    current = current->next;
                }
            }
        }
        
        cout << "Updated Linked List: ";
        display();
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
    
    int arr[] = {1, 2, 1, 2, 1, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    for (int i = 0; i < n; i++) {
        list.insertAtEnd(arr[i]);
    }
    
    cout << "Original Linked List: ";
    list.display();
    
    int key = 1;
    list.countAndDelete(key);
    
    return 0;
}