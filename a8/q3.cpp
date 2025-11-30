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

class BSTOperations {
private:
    BSTNode* root;
    
    BSTNode* insertRecursive(BSTNode* node, int val) {
        if (node == nullptr) {
            return new BSTNode(val);
        }
        
        if (val < node->data) {
            node->left = insertRecursive(node->left, val);
        } else if (val > node->data) {
            node->right = insertRecursive(node->right, val);
        }
        
        return node;
    }
    
    BSTNode* deleteRecursive(BSTNode* node, int val) {
        if (node == nullptr) return node;
        
        if (val < node->data) {
            node->left = deleteRecursive(node->left, val);
        } else if (val > node->data) {
            node->right = deleteRecursive(node->right, val);
        } else {
            if (node->left == nullptr) {
                BSTNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                BSTNode* temp = node->left;
                delete node;
                return temp;
            }
            
            BSTNode* temp = findMinNode(node->right);
            node->data = temp->data;
            node->right = deleteRecursive(node->right, temp->data);
        }
        return node;
    }
    
    BSTNode* findMinNode(BSTNode* node) {
        while (node && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    
    int maxDepth(BSTNode* node) {
        if (node == nullptr) return 0;
        
        int leftDepth = maxDepth(node->left);
        int rightDepth = maxDepth(node->right);
        
        return max(leftDepth, rightDepth) + 1;
    }
    
    int minDepth(BSTNode* node) {
        if (node == nullptr) return 0;
        
        if (node->left == nullptr && node->right == nullptr) return 1;
        
        if (node->left == nullptr) {
            return minDepth(node->right) + 1;
        }
        
        if (node->right == nullptr) {
            return minDepth(node->left) + 1;
        }
        
        return min(minDepth(node->left), minDepth(node->right)) + 1;
    }
    
    void inOrder(BSTNode* node) {
        if (node == nullptr) return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
    
public:
    BSTOperations() {
        root = nullptr;
    }
    
    void insert(int val) {
        root = insertRecursive(root, val);
    }
    
    void deleteElement(int val) {
        root = deleteRecursive(root, val);
    }
    
    int getMaxDepth() {
        return maxDepth(root);
    }
    
    int getMinDepth() {
        return minDepth(root);
    }
    
    void display() {
        cout << "BST (In-order): ";
        inOrder(root);
        cout << endl;
    }
    
    void buildSampleBST() {
        insert(50);
        insert(30);
        insert(70);
        insert(20);
        insert(40);
        insert(60);
        insert(80);
        insert(10);
        insert(25);
    }
};

int main() {
    BSTOperations bst;
    bst.buildSampleBST();
    
    bst.display();
    cout << "Max Depth: " << bst.getMaxDepth() << endl;
    cout << "Min Depth: " << bst.getMinDepth() << endl;
    
    bst.deleteElement(20);
    cout << "After deleting 20: ";
    bst.display();
    
    bst.deleteElement(30);
    cout << "After deleting 30: ";
    bst.display();
    
    cout << "Max Depth after deletion: " << bst.getMaxDepth() << endl;
    cout << "Min Depth after deletion: " << bst.getMinDepth() << endl;
    
    return 0;
}