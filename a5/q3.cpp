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

    int findMiddle() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return -1;
        }
        
        Node* slow = head;
        Node* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow->data;
    }

    int findMiddleByCounting() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return -1;
        }
        
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        
        temp = head;
        for (int i = 0; i < count / 2; i++) {
            temp = temp->next;
        }
        
        return temp->data;
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
    
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    for (int i = 0; i < n; i++) {
        list.insertAtEnd(arr[i]);
    }
    
    cout << "Original Linked List: ";
    list.display();
    
    int middle = list.findMiddle();
    cout << "Middle element (two-pointer method): " << middle << endl;
    
    int middle2 = list.findMiddleByCounting();
    cout << "Middle element (counting method): " << middle2 << endl;
    
    return 0;
}