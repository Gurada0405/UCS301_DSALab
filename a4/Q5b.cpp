#include <iostream>
using namespace std;

class Queue 
{
private:
    int *arr;
    int front, rear, capacity;

public:
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = rear = -1;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % capacity == front;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full!\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = value;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        int value = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        return value;
    }

    int getSize() {
        if (isEmpty()) return 0;
        if (rear >= front) return rear - front + 1;
        return capacity - front + rear + 1;
    }
};

class StackOneQueue 
{
private:
    Queue q;
    int capacity;

public:
    StackOneQueue(int size) : q(size) {
        capacity = size;
    }

    void push(int value) {
        if (q.getSize() == capacity) {
            cout << "Stack is full!\n";
            return;
        }
        
        int size = q.getSize();
        q.enqueue(value);
        
        for (int i = 0; i < size; i++) {
            q.enqueue(q.dequeue());
        }
        
        cout << value << " pushed successfully.\n";
    }

    void pop() {
        if (q.isEmpty()) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << q.dequeue() << " popped successfully.\n";
    }

    void display() {
        if (q.isEmpty()) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Stack elements: ";
        Queue temp(capacity);
        while (!q.isEmpty()) {
            int val = q.dequeue();
            cout << val << " ";
            temp.enqueue(val);
        }
        q = temp;
        cout << endl;
    }
};

int main() {
    int size, choice, value;
    cout << "Enter the size of stack: ";
    cin >> size;
    
    StackOneQueue stack(size);
    
    do {
        cout << "\n--- Stack using One Queue Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.display();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);
    
    return 0;
}