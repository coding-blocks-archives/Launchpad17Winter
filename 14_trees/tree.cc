// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int d) {
        data  = d;
        left = NULL;
        right = NULL;
    }
};

TreeNode* createTree(){
    int x;
    cin >> x;
    if (x == -1){
        return NULL;
    }

    TreeNode* root = new TreeNode(x);
    cout << "Enter left child of " << x << " ";
    root->left = createTree();
    cout << "Enter right child of " << x << " ";
    root->right = createTree();
    return root;
}

void preOrderPrint(TreeNode* root){
    if (root == NULL){
        return;
    }

    cout << root->data << " ";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}


int main() {
    TreeNode* root = createTree();
    preOrderPrint(root);

}