#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class HashSet {
private:
    static const int SIZE = 1000;
    ListNode* table[SIZE];
    
    int hash(uintptr_t key) {
        return key % SIZE;
    }
    
public:
    HashSet() {
        for (int i = 0; i < SIZE; i++) {
            table[i] = nullptr;
        }
    }
    
    bool insert(ListNode* node) {
        uintptr_t key = reinterpret_cast<uintptr_t>(node);
        int index = hash(key);
        
        ListNode* curr = table[index];
        while (curr != nullptr) {
            if (curr == node) return false;
            curr = curr->next;
        }
        
        ListNode* newNode = new ListNode(key);
        newNode->next = table[index];
        table[index] = newNode;
        return true;
    }
    
    bool contains(ListNode* node) {
        uintptr_t key = reinterpret_cast<uintptr_t>(node);
        int index = hash(key);
        
        ListNode* curr = table[index];
        while (curr != nullptr) {
            if (curr->val == key) return true;
            curr = curr->next;
        }
        return false;
    }
};

bool hasCycle(ListNode* head) {
    if (!head) return false;
    
    HashSet seen;
    ListNode* current = head;
    
    while (current != nullptr) {
        if (!seen.insert(current)) {
            return true;
        }
        current = current->next;
    }
    return false;
}

ListNode* createListWithCycle() {
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);
    
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second;
    
    return head;
}

int main() {
    ListNode* head = createListWithCycle();
    
    cout << "Input: 1 → 2 → 3 → 4 → 2 (back to node 2)" << endl;
    cout << "Output: " << (hasCycle(head) ? "true" : "false") << endl;
    
    return 0;
}