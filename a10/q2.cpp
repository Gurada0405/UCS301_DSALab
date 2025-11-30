#include <iostream>
using namespace std;

class HashSet {
private:
    static const int SIZE = 1000;
    int table[SIZE];
    
    int hash(int key) {
        return abs(key) % SIZE;
    }
    
public:
    HashSet() {
        for (int i = 0; i < SIZE; i++) {
            table[i] = -1;
        }
    }
    
    void insert(int key) {
        int index = hash(key);
        while (table[index] != -1) {
            if (table[index] == key) return;
            index = (index + 1) % SIZE;
        }
        table[index] = key;
    }
    
    bool contains(int key) {
        int index = hash(key);
        while (table[index] != -1) {
            if (table[index] == key) return true;
            index = (index + 1) % SIZE;
        }
        return false;
    }
};

void findCommonElements(int A[], int m, int B[], int n) {
    HashSet setA;
    
    for (int i = 0; i < m; i++) {
        setA.insert(A[i]);
    }
    
    cout << "Common elements: ";
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (setA.contains(B[i])) {
            if (found) cout << ", ";
            cout << B[i];
            found = true;
        }
    }
    if (!found) cout << "None";
    cout << endl;
}

int main() {
    int A[] = {1, 2, 3, 4};
    int B[] = {3, 4, 5, 6};
    int m = sizeof(A) / sizeof(A[0]);
    int n = sizeof(B) / sizeof(B[0]);
    
    cout << "A = [1, 2, 3, 4]" << endl;
    cout << "B = [3, 4, 5, 6]" << endl;
    findCommonElements(A, m, B, n);
    
    return 0;
}