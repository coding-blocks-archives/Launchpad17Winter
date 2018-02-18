// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <queue>
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

TreeNode* createTree() {
    int x;
    cin >> x;
    if (x == -1) {
        return NULL;
    }

    TreeNode* root = new TreeNode(x);
    // cout << "Enter left child of " << x << " ";
    root->left = createTree();
    // cout << "Enter right child of " << x << " ";
    root->right = createTree();
    return root;
}

void preOrderPrint(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}

void printLevelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    int curLevel = 1;
    int nextLevel = 0;

    while (q.empty() == false) {
        TreeNode* cur = q.front();
        q.pop();

        if (curLevel == 0){
            cout << endl;
            curLevel = nextLevel;
            nextLevel = 0;
        }

        cout << cur->data << " ";
        --curLevel;

        if (cur->left) {
            q.push(cur->left);
            nextLevel++;
        }

        if (cur->right) {
            q.push(cur->right);
            nextLevel++;
        }
    }

}

void printLevelOrder2(TreeNode* root) {
    queue<TreeNode*> q;
    TreeNode* MARKER = NULL;

    q.push(root);
    q.push(MARKER);

    while (q.empty() == false) {
        TreeNode* cur = q.front();
        q.pop();

        if (cur == MARKER){
            cout << endl;
            if (q.empty() == false){
                q.push(MARKER);
            }
            continue;
        }

        cout << cur->data << " ";

        if (cur->left) {
            q.push(cur->left);
        }

        if (cur->right) {
            q.push(cur->right);
        }
    }

}

TreeNode* createTreeLevelWise(){
    int x;
    cin >> x;
    if (x == -1) return NULL;

    TreeNode* root = new TreeNode(x);
    queue<TreeNode*> q;
    q.push(root);

    while(q.empty() == false){
        TreeNode* cur = q.front();
        q.pop();

        cin >> x;
        if (x != -1) {
            cur->left = new TreeNode(x);
            q.push(cur->left);
        }

        cin >> x;
        if (x != -1) {
            cur->right = new TreeNode(x);
            q.push(cur->right);
        }
    }
    return root;
}


int height(TreeNode* root){
    if (root == NULL){
        return 0;
    }

    int lfHeight = height(root->left);
    int rgHeight = height(root->right);
    return max(lfHeight, rgHeight) + 1;

}

int sumTree(TreeNode* root){
    if (root == NULL){
        return 0;
    }

    return sumTree(root->left) + root->data + sumTree(root->right);
}

#include <cmath>
bool isBal(TreeNode* root){
    if (root == NULL){
        return true;
    }

    int lfHeight = height(root->left);
    int rtHeight = height(root->right);
    bool curBal = abs(lfHeight - rtHeight) <= 1;
    return curBal && isBal(root->left) && isBal(root->right);
}

struct Pair{
    int ht;
    bool isBal;
    Pair(int h, bool b){
        ht = h;
        isBal = b;
    }
    void print(){
        cout << "ht " << ht << " isBal " << isBal << endl;
    }
};

Pair isBal2(TreeNode* root){
    if (root == NULL){
        Pair p(0, true);
        return p;
    }

    Pair ans(0, false);
    Pair lAns = isBal2(root->left);
    if (lAns.isBal == false) return ans;

    Pair rAns = isBal2(root->right);
    if (rAns.isBal == false) return ans;

    ans.ht = max(lAns.ht, rAns.ht) + 1;
    ans.isBal = abs(lAns.ht - rAns.ht) <= 1 && lAns.isBal && rAns.isBal;
    return ans;
}


// zig zag
#include <stack>
void printZigZag(TreeNode* root){
    stack<TreeNode*> curLevel;
    stack<TreeNode*> nextLevel;

    curLevel.push(root);
    bool rToL = false;

    while(!curLevel.empty()){
        TreeNode* cur = curLevel.top();
        curLevel.pop();
        cout << cur->data << " ";

        if (rToL){
            if (cur->right) nextLevel.push(cur->right);
            if (cur->left) nextLevel.push(cur->left);
        }
        else {
            if (cur->left) nextLevel.push(cur->left);
            if (cur->right) nextLevel.push(cur->right);
        }

        if (curLevel.empty()){
            cout << endl;
            swap(curLevel, nextLevel);
            rToL = !rToL;
        }
    }
}

// identical trees?
bool isIdentical(TreeNode* a, TreeNode* b){
    if (a == NULL && b == NULL) return true;
    if (a == NULL || b == NULL) return false;

    return (a->data == b->data) 
        && isIdentical(a->left, b->left) 
        && isIdentical(a->right, b->right); 
}



// Inorder Traversal of Cartesian Tree
int maxElement(int arr[], int be, int en){
    int pos = be;
    while(be <= en){
        if (arr[pos] < arr[be]) pos = be;
        ++be;
    }
    return pos;
}

TreeNode* CartesianTree(int arr[], int be, int en){
    if (be > en){
        return NULL;
    }

    int pos = maxElement(arr, be, en);
    TreeNode* root = new TreeNode(arr[pos]);
    root->left = CartesianTree(arr, be, pos - 1);
    root->right = CartesianTree(arr, pos + 1, en);
    return root;
}


// sum root to leaf numbers
// populate next pointer

// Kth Smallest Element In Tree


int main() {
    // TreeNode* root = createTreeLevelWise();
    // preOrderPrint(root);
    // printLevelOrder2(root);

    // int ans = height(root);
    // cout << ans;

    // int ans = sumTree(root);
    // cout << ans;

    // bool ans = isBal(root);
    // cout << ans;

    // Pair ans = isBal2(root);
    // ans.print();

    // printZigZag(root);

    // 18-Feb-18
    // TreeNode* a = createTreeLevelWise();
    // TreeNode* b = createTreeLevelWise();
    // cout << isIdentical(a, b);

    int arr[] = {-2, -1, 0,  3, 1, 2};
    TreeNode* root = CartesianTree(arr, 0, 5);
    printLevelOrder2(root);

}