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

class SinglyLinkedList 
{
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << value << " inserted at beginning.\n";
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
        cout << value << " inserted at end.\n";
    }

    void insertBefore(int value, int target) {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        
        if (head->data == target) {
            insertAtBeginning(value);
            return;
        }
        
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != target) {
            temp = temp->next;
        }
        
        if (temp->next == nullptr) {
            cout << "Node with value " << target << " not found!\n";
        } else {
            Node* newNode = new Node(value);
            newNode->next = temp->next;
            temp->next = newNode;
            cout << value << " inserted before " << target << ".\n";
        }
    }

    void insertAfter(int value, int target) {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        
        Node* temp = head;
        while (temp != nullptr && temp->data != target) {
            temp = temp->next;
        }
        
        if (temp == nullptr) {
            cout << "Node with value " << target << " not found!\n";
        } else {
            Node* newNode = new Node(value);
            newNode->next = temp->next;
            temp->next = newNode;
            cout << value << " inserted after " << target << ".\n";
        }
    }

    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << temp->data << " deleted from beginning.\n";
        delete temp;
    }

    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        
        if (head->next == nullptr) {
            cout << head->data << " deleted from end.\n";
            delete head;
            head = nullptr;
            return;
        }
        
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        cout << temp->next->data << " deleted from end.\n";
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        
        if (head->data == value) {
            deleteFromBeginning();
            return;
        }
        
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }
        
        if (temp->next == nullptr) {
            cout << "Node with value " << value << " not found!\n";
        } else {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            cout << nodeToDelete->data << " deleted.\n";
            delete nodeToDelete;
        }
    }

    void search(int value) {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        
        Node* temp = head;
        int position = 1;
        while (temp != nullptr) {
            if (temp->data == value) {
                cout << "Node with value " << value << " found at position " << position << " from head.\n";
                return;
            }
            temp = temp->next;
            position++;
        }
        cout << "Node with value " << value << " not found!\n";
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << " -> NULL\n";
    }

    ~SinglyLinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    SinglyLinkedList list;
    int choice, value, target;
    
    do {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert before a node\n";
        cout << "4. Insert after a node\n";
        cout << "5. Delete from beginning\n";
        cout << "6. Delete from end\n";
        cout << "7. Delete specific node\n";
        cout << "8. Search for a node\n";
        cout << "9. Display list\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter target value: ";
                cin >> target;
                list.insertBefore(value, target);
                break;
            case 4:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter target value: ";
                cin >> target;
                list.insertAfter(value, target);
                break;
            case 5:
                list.deleteFromBeginning();
                break;
            case 6:
                list.deleteFromEnd();
                break;
            case 7:
                cout << "Enter value to delete: ";
                cin >> value;
                list.deleteNode(value);
                break;
            case 8:
                cout << "Enter value to search: ";
                cin >> value;
                list.search(value);
                break;
            case 9:
                list.display();
                break;
            case 10:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 10);
    
    return 0;
}