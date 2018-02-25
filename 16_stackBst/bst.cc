// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode* next;
    TreeNode(int d) {
        data  = d;
        next = NULL;
        left = NULL;
        right = NULL;
    }
};

TreeNode* insertIntoBst(TreeNode* root, int x){
    if (root == NULL){
        return new TreeNode(x);
    }

    if (x < root->data){
        root->left = insertIntoBst(root->left, x);
    }
    else {
        root->right = insertIntoBst(root->right, x);
    }
    return root;
}

TreeNode* createTree(){
    int x;
    TreeNode* root = NULL;
    while(true){
        cin >> x;
        if (x == -1) break;
        root = insertIntoBst(root, x);
    }
    return root;
}

void printInOrder(TreeNode* root){
    if (root == NULL){
        return;
    }
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

int main(){
    TreeNode* root = createTree();
    printInOrder(root);
    
}