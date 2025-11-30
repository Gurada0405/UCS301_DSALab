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
    
    bool insert(int key) {
        int index = hash(key);
        while (table[index] != -1) {
            if (table[index] == key) {
                return false;
            }
            index = (index + 1) % SIZE;
        }
        table[index] = key;
        return true;
    }
    
    bool contains(int key) {
        int index = hash(key);
        while (table[index] != -1) {
            if (table[index] == key) {
                return true;
            }
            index = (index + 1) % SIZE;
        }
        return false;
    }
};

bool containsDuplicate(int nums[], int n) {
    HashSet seen;
    for (int i = 0; i < n; i++) {
        if (!seen.insert(nums[i])) {
            return true;
        }
    }
    return false;
}

int main() {
    int nums[] = {1, 2, 3, 1};
    int n = sizeof(nums) / sizeof(nums[0]);
    
    cout << "Input: [1, 2, 3, 1]" << endl;
    cout << "Output: " << (containsDuplicate(nums, n) ? "true" : "false") << endl;
    
    return 0;
}