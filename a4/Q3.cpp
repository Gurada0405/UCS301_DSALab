#include <iostream>
using namespace std;

class Queue {
private:
    int *arr;
    int front, rear, capacity;

public:
    Queue(int size) 
    {
        capacity = size;
        arr = new int[capacity];
        front = rear = -1;
    }

    ~Queue() 
    {
        delete[] arr;
    }

    bool isEmpty() 
    {
        return front == -1;
    }

    bool isFull() 
    {
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

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % capacity;
        }
        cout << endl;
    }

    int getSize() {
        if (isEmpty()) return 0;
        if (rear >= front) return rear - front + 1;
        return capacity - front + rear + 1;
    }
};

void interleaveQueue(Queue &q) {
    int n = q.getSize();
    if (n % 2 != 0) {
        cout << "Queue size must be even for interleaving!\n";
        return;
    }

    int half = n / 2;
    int *temp = new int[half];
    
   
    for (int i = 0; i < half; i++) {
        temp[i] = q.dequeue();
    }
    
  
    for (int i = 0; i < half; i++) {
        q.enqueue(temp[i]);
        q.enqueue(q.dequeue());
    }
    
    delete[] temp;
}

int main() 
{
    int n, value;
    cout << "Enter number of elements (even): ";
    cin >> n;
    
    if (n % 2 != 0) 
    {
        cout << "Number of elements must be even!\n";
        return 1;
    }
    
    Queue q(n);
    
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        q.enqueue(value);
    }
    
    cout << "Original queue: ";
    q.display();
    
    interleaveQueue(q);
    
    cout << "Interleaved queue: ";
    q.display();
    
    return 0;
}