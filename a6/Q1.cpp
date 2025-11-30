#include <iostream>
using namespace std;

class CNode {
public:
    int data;
    CNode* next;
    
    CNode(int value) {
        data = value;
        next = nullptr;
    }
};

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

class CircularLinkedList {
private:
    CNode* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    void insertAsFirst(int value) {
        CNode* newNode = new CNode(value);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        } else {
            CNode* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
        cout << value << " inserted as first node.\n";
    }

    void insertAsLast(int value) {
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
        cout << value << " inserted as last node.\n";
    }

    void insertAfter(int value, int target) {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        
        CNode* temp = head;
        do {
            if (temp->data == target) {
                CNode* newNode = new CNode(value);
                newNode->next = temp->next;
                temp->next = newNode;
                cout << value << " inserted after " << target << ".\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);
        
        cout << "Node with value " << target << " not found!\n";
    }

    void insertBefore(int value, int target) {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        
        if (head->data == target) {
            insertAsFirst(value);
            return;
        }
        
        CNode* temp = head;
        do {
            if (temp->next->data == target) {
                CNode* newNode = new CNode(value);
                newNode->next = temp->next;
                temp->next = newNode;
                cout << value << " inserted before " << target << ".\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);
        
        cout << "Node with value " << target << " not found!\n";
    }

    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        
        if (head->data == value) {
            if (head->next == head) { 
                cout << head->data << " deleted.\n";
                delete head;
                head = nullptr;
            } else {
                CNode* temp = head;
                while (temp->next != head) {
                    temp = temp->next;
                }
                temp->next = head->next;
                cout << head->data << " deleted.\n";
                delete head;
                head = temp->next;
            }
            return;
        }
        
        CNode* temp = head;
        do {
            if (temp->next->data == value) {
                CNode* nodeToDelete = temp->next;
                temp->next = temp->next->next;
                cout << nodeToDelete->data << " deleted.\n";
                delete nodeToDelete;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        
        cout << "Node with value " << value << " not found!\n";
    }

    void search(int value) {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        
        CNode* temp = head;
        int position = 1;
        do {
            if (temp->data == value) {
                cout << "Node with value " << value << " found at position " << position << ".\n";
                return;
            }
            temp = temp->next;
            position++;
        } while (temp != head);
        
        cout << "Node with value " << value << " not found!\n";
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

class DoublyLinkedList {
private:
    DNode* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void insertAsFirst(int value) {
        DNode* newNode = new DNode(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << value << " inserted as first node.\n";
    }

    void insertAsLast(int value) {
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
        cout << value << " inserted as last node.\n";
    }

    void insertAfter(int value, int target) {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        
        DNode* temp = head;
        while (temp != nullptr && temp->data != target) {
            temp = temp->next;
        }
        
        if (temp == nullptr) {
            cout << "Node with value " << target << " not found!\n";
        } else {
            DNode* newNode = new DNode(value);
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next != nullptr) {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
            cout << value << " inserted after " << target << ".\n";
        }
    }

    void insertBefore(int value, int target) {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        
        if (head->data == target) {
            insertAsFirst(value);
            return;
        }
        
        DNode* temp = head;
        while (temp != nullptr && temp->data != target) {
            temp = temp->next;
        }
        
        if (temp == nullptr) {
            cout << "Node with value " << target << " not found!\n";
        } else {
            DNode* newNode = new DNode(value);
            newNode->next = temp;
            newNode->prev = temp->prev;
            temp->prev->next = newNode;
            temp->prev = newNode;
            cout << value << " inserted before " << target << ".\n";
        }
    }

    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        
        DNode* temp = head;
        while (temp != nullptr && temp->data != value) {
            temp = temp->next;
        }
        
        if (temp == nullptr) {
            cout << "Node with value " << value << " not found!\n";
        } else {
            if (temp->prev != nullptr) {
                temp->prev->next = temp->next;
            } else {
                head = temp->next;
            }
            if (temp->next != nullptr) {
                temp->next->prev = temp->prev;
            }
            cout << temp->data << " deleted.\n";
            delete temp;
        }
    }

    void search(int value) {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        
        DNode* temp = head;
        int position = 1;
        while (temp != nullptr) {
            if (temp->data == value) {
                cout << "Node with value " << value << " found at position " << position << ".\n";
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

int main() {
    CircularLinkedList clist;
    DoublyLinkedList dlist;
    int choice, listType, value, target;
    
    do {
        cout << "\n--- Linked List Menu ---\n";
        cout << "1. Circular Linked List Operations\n";
        cout << "2. Doubly Linked List Operations\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        if (choice == 3) break;
        
        listType = choice;
        
        do {
            cout << "\n--- " << (listType == 1 ? "Circular" : "Doubly") << " Linked List Menu ---\n";
            cout << "1. Insert as first node\n";
            cout << "2. Insert as last node\n";
            cout << "3. Insert after a node\n";
            cout << "4. Insert before a node\n";
            cout << "5. Delete specific node\n";
            cout << "6. Search for a node\n";
            cout << "7. Display list\n";
            cout << "8. Back to main menu\n";
            cout << "Enter your choice: ";
            cin >> choice;
            
            switch(choice) {
                case 1:
                    cout << "Enter value to insert: ";
                    cin >> value;
                    if (listType == 1) clist.insertAsFirst(value);
                    else dlist.insertAsFirst(value);
                    break;
                case 2:
                    cout << "Enter value to insert: ";
                    cin >> value;
                    if (listType == 1) clist.insertAsLast(value);
                    else dlist.insertAsLast(value);
                    break;
                case 3:
                    cout << "Enter value to insert: ";
                    cin >> value;
                    cout << "Enter target value: ";
                    cin >> target;
                    if (listType == 1) clist.insertAfter(value, target);
                    else dlist.insertAfter(value, target);
                    break;
                case 4:
                    cout << "Enter value to insert: ";
                    cin >> value;
                    cout << "Enter target value: ";
                    cin >> target;
                    if (listType == 1) clist.insertBefore(value, target);
                    else dlist.insertBefore(value, target);
                    break;
                case 5:
                    cout << "Enter value to delete: ";
                    cin >> value;
                    if (listType == 1) clist.deleteNode(value);
                    else dlist.deleteNode(value);
                    break;
                case 6:
                    cout << "Enter value to search: ";
                    cin >> value;
                    if (listType == 1) clist.search(value);
                    else dlist.search(value);
                    break;
                case 7:
                    if (listType == 1) clist.display();
                    else dlist.display();
                    break;
                case 8:
                    break;
                default:
                    cout << "Invalid choice!\n";
            }
        } while (choice != 8);
        
    } while (true);
    
    cout << "Exiting...\n";
    return 0;
}