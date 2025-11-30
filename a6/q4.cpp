#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node* prev;
    
    Node(char value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtEnd(char value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    bool isPalindrome() {
        if (head == nullptr) {
            return true; 
        }
        
        Node* front = head;
        Node* back = tail;
        
        while (front != back && front->prev != back) {
            if (front->data != back->data) {
                return false;
            }
            front = front->next;
            back = back->prev;
        }
        return true;
    }

    bool isPalindromeUsingArray() {
        if (head == nullptr) {
            return true;
        }
        
        int size = 0;
        Node* temp = head;
        while (temp != nullptr) {
            size++;
            temp = temp->next;
        }
        
        char* arr = new char[size];
        temp = head;
        for (int i = 0; i < size; i++) {
            arr[i] = temp->data;
            temp = temp->next;
        }
        
        bool result = true;
        for (int i = 0; i < size / 2; i++) {
            if (arr[i] != arr[size - 1 - i]) {
                result = false;
                break;
            }
        }
        
        delete[] arr;
        return result;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        
        Node* temp = head;
        cout << "Doubly Linked List: NULL <-> ";
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    ~DoublyLinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    DoublyLinkedList list1, list2, list3;
    
    cout << "Test Case 1: Palindrome list\n";
    char palindrome[] = {'r', 'a', 'd', 'a', 'r'};
    for (int i = 0; i < 5; i++) {
        list1.insertAtEnd(palindrome[i]);
    }
    list1.display();
    cout << "Is palindrome (two-pointer method): " << (list1.isPalindrome() ? "Yes" : "No") << endl;
    cout << "Is palindrome (array method): " << (list1.isPalindromeUsingArray() ? "Yes" : "No") << endl;
    
    cout << "\n" << string(50, '-') << "\n" << endl;
    
    cout << "Test Case 2: Non-palindrome list\n";
    char nonPalindrome[] = {'h', 'e', 'l', 'l', 'o'};
    for (int i = 0; i < 5; i++) {
        list2.insertAtEnd(nonPalindrome[i]);
    }
    list2.display();
    cout << "Is palindrome (two-pointer method): " << (list2.isPalindrome() ? "Yes" : "No") << endl;
    cout << "Is palindrome (array method): " << (list2.isPalindromeUsingArray() ? "Yes" : "No") << endl;
    
    cout << "\n" << string(50, '-') << "\n" << endl;
    
    cout << "Test Case 3: Single character list\n";
    list3.insertAtEnd('a');
    list3.display();
    cout << "Is palindrome (two-pointer method): " << (list3.isPalindrome() ? "Yes" : "No") << endl;
    cout << "Is palindrome (array method): " << (list3.isPalindromeUsingArray() ? "Yes" : "No") << endl;
    
    return 0;
}