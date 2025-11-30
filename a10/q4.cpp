#include <iostream>
using namespace std;

struct Node {
    int value;
    int count;
    int firstIndex;
};

class HashMap {
private:
    static const int SIZE = 1000;
    Node table[SIZE];
    
    int hash(int key) {
        return abs(key) % SIZE;
    }
    
public:
    HashMap() {
        for (int i = 0; i < SIZE; i++) {
            table[i].value = -1;
            table[i].count = 0;
            table[i].firstIndex = -1;
        }
    }
    
    void put(int key, int index) {
        int h = hash(key);
        while (table[h].value != -1 && table[h].value != key) {
            h = (h + 1) % SIZE;
        }
        
        if (table[h].value == -1) {
            table[h].value = key;
            table[h].firstIndex = index;
        }
        table[h].count++;
    }
    
    int findFirstNonRepeating(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            int h = hash(arr[i]);
            while (table[h].value != -1 && table[h].value != arr[i]) {
                h = (h + 1) % SIZE;
            }
            if (table[h].count == 1) {
                return table[h].value;
            }
        }
        return -1;
    }
};

int firstNonRepeating(int arr[], int n) {
    HashMap map;
    
    for (int i = 0; i < n; i++) {
        map.put(arr[i], i);
    }
    
    return map.findFirstNonRepeating(arr, n);
}

int main() {
    int arr[] = {4, 5, 1, 2, 0, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Input: [4, 5, 1, 2, 0, 4]" << endl;
    int result = firstNonRepeating(arr, n);
    cout << "Output: " << (result != -1 ? to_string(result) : "No non-repeating element") << endl;
    
    return 0;
}