#include <iostream>
using namespace std;

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
    
    BSTNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    BSTNode* root;
    
    BSTNode* searchRecursive(BSTNode* node, int key) {
        if (node == nullptr || node->data == key) {
            return node;
        }
        
        if (key < node->data) {
            return searchRecursive(node->left, key);
        }
        return searchRecursive(node->right, key);
    }
    
    BSTNode* findMinNode(BSTNode* node) {
        while (node && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    
    BSTNode* findMaxNode(BSTNode* node) {
        while (node && node->right != nullptr) {
            node = node->right;
        }
        return node;
    }
    
public:
    BST() {
        root = nullptr;
    }
    
    void insert(int val) {
        BSTNode* newNode = new BSTNode(val);
        if (root == nullptr) {
            root = newNode;
            return;
        }
        
        BSTNode* current = root;
        BSTNode* parent = nullptr;
        
        while (current != nullptr) {
            parent = current;
            if (val < current->data) {
                current = current->left;
            } else if (val > current->data) {
                current = current->right;
            } else {
                return;
            }
        }
        
        if (val < parent->data) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    }
    
    bool searchRecursive(int key) {
        return searchRecursive(root, key) != nullptr;
    }
    
    bool searchNonRecursive(int key) {
        BSTNode* current = root;
        while (current != nullptr) {
            if (key == current->data) {
                return true;
            } else if (key < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return false;
    }
    
    int findMax() {
        BSTNode* maxNode = findMaxNode(root);
        return maxNode ? maxNode->data : -1;
    }
    
    int findMin() {
        BSTNode* minNode = findMinNode(root);
        return minNode ? minNode->data : -1;
    }
    
    BSTNode* findNode(int key) {
        return searchRecursive(root, key);
    }
    
    int inOrderSuccessor(int key) {
        BSTNode* current = findNode(key);
        if (current == nullptr) return -1;
        
        if (current->right != nullptr) {
            BSTNode* temp = current->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }
            return temp->data;
        } else {
            BSTNode* successor = nullptr;
            BSTNode* ancestor = root;
            while (ancestor != current) {
                if (current->data < ancestor->data) {
                    successor = ancestor;
                    ancestor = ancestor->left;
                } else {
                    ancestor = ancestor->right;
                }
            }
            return successor ? successor->data : -1;
        }
    }
    
    int inOrderPredecessor(int key) {
        BSTNode* current = findNode(key);
        if (current == nullptr) return -1;
        
        if (current->left != nullptr) {
            BSTNode* temp = current->left;
            while (temp->right != nullptr) {
                temp = temp->right;
            }
            return temp->data;
        } else {
            BSTNode* predecessor = nullptr;
            BSTNode* ancestor = root;
            while (ancestor != current) {
                if (current->data > ancestor->data) {
                    predecessor = ancestor;
                    ancestor = ancestor->right;
                } else {
                    ancestor = ancestor->left;
                }
            }
            return predecessor ? predecessor->data : -1;
        }
    }
    
    void buildSampleBST() {
        insert(50);
        insert(30);
        insert(70);
        insert(20);
        insert(40);
        insert(60);
        insert(80);
    }
};

int main() {
    BST bst;
    bst.buildSampleBST();
    
    cout << "Search 40 (Recursive): " << bst.searchRecursive(40) << endl;
    cout << "Search 40 (Non-Recursive): " << bst.searchNonRecursive(40) << endl;
    cout << "Search 100 (Recursive): " << bst.searchRecursive(100) << endl;
    
    cout << "Max element: " << bst.findMax() << endl;
    cout << "Min element: " << bst.findMin() << endl;
    
    cout << "In-order successor of 40: " << bst.inOrderSuccessor(40) << endl;
    cout << "In-order predecessor of 40: " << bst.inOrderPredecessor(40) << endl;
    
    return 0;
}