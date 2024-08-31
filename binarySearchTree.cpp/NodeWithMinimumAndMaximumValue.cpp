#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void maxAndmin(TreeNode* root) {
    if (!root) return; 

    int mn = root->val, mx = root->val;

    TreeNode* temp = root;
    while (temp->left) {
        temp = temp->left;
        mn = temp->val;
    }
    
   
    temp = root;
    while (temp->right) {
        temp = temp->right;
        mx = temp->val;
    }
    
    cout << "Minimum value: " << mn << "\n";
    cout << "Maximum value: " << mx << "\n";
}


TreeNode* insert(TreeNode* node, int key) {
    // If the tree is empty, return a new node
    if (node == NULL) return new TreeNode(key);
    

    if (key < node->val)
        node->left = insert(node->left, key);
    else if (key > node->val)
        node->right = insert(node->right, key);


    return node;
}

int main() {
    TreeNode* root = NULL;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 20);
    insert(root, 3);
    insert(root, 7);
    insert(root, 15);
    insert(root, 30);
    insert(root, 2);

    // Find and print the maximum and minimum values in the BST
    maxAndmin(root);

    return 0;
}
