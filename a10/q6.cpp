#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

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
            if (table[index] == key) return false;
            index = (index + 1) % SIZE;
        }
        table[index] = key;
        return true;
    }
};

bool checkDuplicates(TreeNode* root, HashSet& seen) {
    if (!root) return false;
    
    if (!seen.insert(root->val)) {
        return true;
    }
    
    return checkDuplicates(root->left, seen) || checkDuplicates(root->right, seen);
}

bool hasDuplicateValues(TreeNode* root) {
    HashSet seen;
    return checkDuplicates(root, seen);
}

TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(5);
    
    return root;
}

int main() {
    TreeNode* root = createSampleTree();
    
    cout << "Binary Tree with values: 1, 2, 3, 4, 2, 5" << endl;
    if (hasDuplicateValues(root)) {
        cout << "Duplicates Found" << endl;
    } else {
        cout << "No Duplicates" << endl;
    }
    
    return 0;
}