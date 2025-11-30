#include <iostream>
using namespace std;

class MaxHeap {
private:
    int* heap;
    int capacity;
    int size;
    
    void heapifyUp(int i) {
        while (i > 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
    
    void heapifyDown(int i) {
        int maxIndex = i;
        int left = leftChild(i);
        int right = rightChild(i);
        
        if (left < size && heap[left] > heap[maxIndex]) {
            maxIndex = left;
        }
        if (right < size && heap[right] > heap[maxIndex]) {
            maxIndex = right;
        }
        
        if (i != maxIndex) {
            swap(heap[i], heap[maxIndex]);
            heapifyDown(maxIndex);
        }
    }
    
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }
    
public:
    MaxHeap(int cap) {
        capacity = cap;
        size = 0;
        heap = new int[capacity];
    }
    
    ~MaxHeap() {
        delete[] heap;
    }
    
    void insert(int value) {
        if (size == capacity) {
            return;
        }
        
        heap[size] = value;
        heapifyUp(size);
        size++;
    }
    
    int extractMax() {
        if (size == 0) {
            return -1;
        }
        
        int maxVal = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
        return maxVal;
    }
    
    int getMax() {
        if (size == 0) {
            return -1;
        }
        return heap[0];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    int getSize() {
        return size;
    }
    
    void display() {
        cout << "Priority Queue: ";
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

class PriorityQueue {
private:
    MaxHeap heap;
    
public:
    PriorityQueue(int capacity) : heap(capacity) {}
    
    void enqueue(int value) {
        heap.insert(value);
    }
    
    int dequeue() {
        return heap.extractMax();
    }
    
    int peek() {
        return heap.getMax();
    }
    
    bool isEmpty() {
        return heap.isEmpty();
    }
    
    void display() {
        heap.display();
    }
};

int main() {
    PriorityQueue pq(10);
    
    pq.enqueue(10);
    pq.enqueue(30);
    pq.enqueue(20);
    pq.enqueue(40);
    pq.enqueue(5);
    
    cout << "Initial priority queue: ";
    pq.display();
    
    cout << "Peek: " << pq.peek() << endl;
    
    cout << "Dequeue: " << pq.dequeue() << endl;
    cout << "Dequeue: " << pq.dequeue() << endl;
    
    cout << "After dequeuing two elements: ";
    pq.display();
    
    cout << "Peek: " << pq.peek() << endl;
    
    return 0;
}