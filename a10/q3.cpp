#include <iostream>
using namespace std;

struct KeyValue {
    int key;
    int value;
};

class HashMap {
private:
    static const int SIZE = 1000;
    KeyValue table[SIZE];
    
    int hash(int key) {
        return abs(key) % SIZE;
    }
    
public:
    HashMap() {
        for (int i = 0; i < SIZE; i++) {
            table[i].key = -1;
            table[i].value = 0;
        }
    }
    
    void put(int key) {
        int index = hash(key);
        while (table[index].key != -1 && table[index].key != key) {
            index = (index + 1) % SIZE;
        }
        table[index].key = key;
        table[index].value++;
    }
    
    void printFrequencies() {
        for (int i = 0; i < SIZE; i++) {
            if (table[i].key != -1) {
                cout << "• " << table[i].key << " → " << table[i].value << " times" << endl;
            }
        }
    }
};

void countFrequency(int nums[], int n) {
    HashMap freqMap;
    
    for (int i = 0; i < n; i++) {
        freqMap.put(nums[i]);
    }
    
    freqMap.printFrequencies();
}

int main() {
    int nums[] = {2, 3, 2, 4, 3, 2};
    int n = sizeof(nums) / sizeof(nums[0]);
    
    cout << "Input: [2, 3, 2, 4, 3, 2]" << endl;
    cout << "Output:" << endl;
    countFrequency(nums, n);
    
    return 0;
}