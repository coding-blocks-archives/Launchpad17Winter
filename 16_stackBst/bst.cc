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

// Sorted Array To Balanced BST 
TreeNode* bstFromArr(int arr[], int be, int en){
    if (be > en){
        return NULL;
    }

    int mid = (be + en) / 2;
    TreeNode * root = new TreeNode(arr[mid]);
    root->left = bstFromArr(arr, be, mid - 1);
    root->right = bstFromArr(arr, mid + 1, en);
    return root;
}

// Flatten Binary Tree to Linked List
class Pair{
public:
    TreeNode* head, *tail;
    Pair(){
        head = NULL;
        tail = NULL;
    }
};

Pair treeToList(TreeNode* root){
    if (root == NULL){
        return Pair();
    }

    Pair left = treeToList(root->left);
    Pair right = treeToList(root->right);

    Pair ans;
    if (left.tail){
        ans.head = left.head;
        left.tail->right = root;
        root->left = left.tail;
    }
    else {
        ans.head = root;
    }

    if (right.head){
        right.head->left = root;
        ans.tail = right.tail;
        root->right = right.head;
    }
    else{
        ans.tail = root;
    }
    return ans;
}

void printLL(Pair p){
    TreeNode* cur = p.head;
    while(cur){
        cout << "(" << (cur->left ? cur->left->data : -1) << ")";
        cout << cur->data;
        cout << "(" << (cur->right ? cur->right->data : -1) << ")";
        cout << "--->";
        cur = cur->right;
    }
}


bool isBst(TreeNode* root, int minVal, int maxVal){
    if (root == NULL) return true;

    return (root->data >= minVal && root->data <= maxVal) &&
            isBst(root->left, minVal, root->data) &&
            isBst(root->right, root->data, maxVal);
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


int main(){
    TreeNode* root = createTree();
    printInOrder(root);


    // TreeNode* root = createTreeLevelWise();
    // printInOrder(root);
    // const int inf = 1e5;
    // bool ans = isBst(root, -inf, inf);
    // cout << ans;

    // int height[100];
    // int n; cin >> n;
    // for (int i = 0; i < n; ++i) {
    //     cin >> height[i];
    // }

    // TreeNode* ans = bstFromArr(height, 0, n - 1);
    // printLevelOrder(ans);    
    // printInOrder(ans);

    Pair ans = treeToList(root);
    printLL(ans);
}