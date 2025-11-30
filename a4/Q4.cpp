#include <iostream>
using namespace std;

class Queue 
{
private:
    char *arr;
    int front, rear, capacity;

public:
    Queue(int size) 
    {
        capacity = size;
        arr = new char[capacity];
        front = rear = -1;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(char value) 
    {
        if ((rear + 1) % capacity == front) {
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

    char dequeue() 
    {
        if (isEmpty()) {
            return '\0';
        }
        char value = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        return value;
    }

    char peek() {
        if (isEmpty()) {
            return '\0';
        }
        return arr[front];
    }
};

void findFirstNonRepeating(const string &str) 
{
    int count[26] = {0};
    Queue q(26);
    
    cout << "Output: ";
    for (char ch : str) {
        count[ch - 'a']++;
        q.enqueue(ch);
        
        while (!q.isEmpty() && count[q.peek() - 'a'] > 1) {
            q.dequeue();
        }
        
        if (q.isEmpty()) {
            cout << "-1 ";
        } else {
            cout << q.peek() << " ";
        }
    }
    cout << endl;
}

int main() 
{

    string input;
    cout << "Enter a string (lowercase only): ";
    cin >> input;
    
    findFirstNonRepeating(input);
    
    return 0;
}