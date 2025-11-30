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

class BinaryTree {
private:
    TreeNode* root;
    
    void preOrderRecursive(TreeNode* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preOrderRecursive(node->left);
        preOrderRecursive(node->right);
    }
    
    void inOrderRecursive(TreeNode* node) {
        if (node == nullptr) return;
        inOrderRecursive(node->left);
        cout << node->data << " ";
        inOrderRecursive(node->right);
    }
    
    void postOrderRecursive(TreeNode* node) {
        if (node == nullptr) return;
        postOrderRecursive(node->left);
        postOrderRecursive(node->right);
        cout << node->data << " ";
    }
    
public:
    BinaryTree() {
        root = nullptr;
    }
    
    void buildSampleTree() {
        root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(5);
        root->right->left = new TreeNode(6);
        root->right->right = new TreeNode(7);
    }
    
    void preOrder() {
        cout << "Pre-order: ";
        preOrderRecursive(root);
        cout << endl;
    }
    
    void inOrder() {
        cout << "In-order: ";
        inOrderRecursive(root);
        cout << endl;
    }
    
    void postOrder() {
        cout << "Post-order: ";
        postOrderRecursive(root);
        cout << endl;
    }
};

int main() {
    BinaryTree tree;
    tree.buildSampleTree();
    
    tree.preOrder();
    tree.inOrder();
    tree.postOrder();
    
    return 0;
}