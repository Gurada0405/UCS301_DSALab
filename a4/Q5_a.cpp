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

class StackTwoQueues 
{
private:
    Queue q1, q2;
    int capacity;

public:
    StackTwoQueues(int size) : q1(size), q2(size) {
        capacity = size;
    }

    void push(int value) {
        if (q1.getSize() == capacity) {
            cout << "Stack is full!\n";
            return;
        }
        q2.enqueue(value);
        
        while (!q1.isEmpty()) {
            q2.enqueue(q1.dequeue());
        }
        
        Queue temp = q1;
        q1 = q2;
        q2 = temp;
        
        cout << value << " pushed successfully.\n";
    }

    void pop() {
        if (q1.isEmpty()) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << q1.dequeue() << " popped successfully.\n";
    }

    void display() {
        if (q1.isEmpty()) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Stack elements: ";
        Queue temp(capacity);
        while (!q1.isEmpty()) {
            int val = q1.dequeue();
            cout << val << " ";
            temp.enqueue(val);
        }
        q1 = temp;
        cout << endl;
    }
};

int main() 
{
    int size, choice, value;
    cout << "Enter the size of stack: ";
    cin >> size;
    
    StackTwoQueues stack(size);
    
    do {
        cout << "\nStack using Two Queues Menu\n";
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