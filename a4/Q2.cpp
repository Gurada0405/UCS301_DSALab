#include <iostream>
using namespace std;

class CircularQueue 
{
    private:
    int *arr;
    int front, rear, capacity;
    
    public:
    CircularQueue(int size) 
    {
        capacity = size;
        arr = new int[capacity];
        front = rear = -1;
    }

    ~CircularQueue() 
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

    void enqueue(int value) 
    {
        if (isFull()) 
        {
            cout << "Queue is full!\n";
            return;
        }
        if (isEmpty()) 
        {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = value;
        cout << value << " enqueued successfully.\n";
    }

    void dequeue() 
    {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << arr[front] << " dequeued successfully.\n";
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
    }

    void display() 
    {
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

    void peek() 
    {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
        } else {
            cout << "Front element: " << arr[front] << endl;
        }
    }
};

int main() 
{
    int size, choice, value;
    cout << "Enter the size of circular queue: ";
    cin >> size;
    
    CircularQueue cq(size);
    
    do {
        cout << "\nCircular Queue Menu\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Check Empty\n";
        cout << "4. Check Full\n";
        cout << "5. Display\n";
        cout << "6. Peek\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) 
        {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                cq.enqueue(value);
                break;
            case 2:
                cq.dequeue();
                break;
            case 3:
                if (cq.isEmpty()) 
                    cout << "Queue is empty\n";
                else 
                    cout << "Queue is not empty\n";
                break;
            case 4:
                if (cq.isFull()) 
                    cout << "Queue is full\n";
                else 
                    cout << "Queue is not full\n";
                break;
            case 5:
                cq.display();
                break;
            case 6:
                cq.peek();
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 7);
    
    return 0;
}