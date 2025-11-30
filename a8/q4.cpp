#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BSTChecker {
private:
    bool isBSTUtil(TreeNode* node, int minVal, int maxVal) {
        if (node == nullptr) return true;
        
        if ((minVal != -1 && node->data <= minVal) || (maxVal != -1 && node->data >= maxVal)) {
            return false;
        }
        
        return isBSTUtil(node->left, minVal, node->data) && 
               isBSTUtil(node->right, node->data, maxVal);
    }
    
    bool inOrderCheck(TreeNode* node, int& prev) {
        if (node == nullptr) return true;
        
        if (!inOrderCheck(node->left, prev)) {
            return false;
        }
        
        if (node->data <= prev) {
            return false;
        }
        prev = node->data;
        
        return inOrderCheck(node->right, prev);
    }
    
public:
    bool isBSTMethod1(TreeNode* root) {
        return isBSTUtil(root, -1, -1);
    }
    
    bool isBSTMethod2(TreeNode* root) {
        int prev = -1;
        return inOrderCheck(root, prev);
    }
    
    TreeNode* createValidBST() {
        TreeNode* root = new TreeNode(50);
        root->left = new TreeNode(30);
        root->right = new TreeNode(70);
        root->left->left = new TreeNode(20);
        root->left->right = new TreeNode(40);
        root->right->left = new TreeNode(60);
        root->right->right = new TreeNode(80);
        return root;
    }
    
    TreeNode* createInvalidBST() {
        TreeNode* root = new TreeNode(50);
        root->left = new TreeNode(30);
        root->right = new TreeNode(70);
        root->left->left = new TreeNode(20);
        root->left->right = new TreeNode(60);
        root->right->left = new TreeNode(40);
        root->right->right = new TreeNode(80);
        return root;
    }
};

int main() {
    BSTChecker checker;
    
    TreeNode* validBST = checker.createValidBST();
    TreeNode* invalidBST = checker.createInvalidBST();
    
    cout << "Valid BST (Method 1): " << checker.isBSTMethod1(validBST) << endl;
    cout << "Valid BST (Method 2): " << checker.isBSTMethod2(validBST) << endl;
    
    cout << "Invalid BST (Method 1): " << checker.isBSTMethod1(invalidBST) << endl;
    cout << "Invalid BST (Method 2): " << checker.isBSTMethod2(invalidBST) << endl;
    
    return 0;
}