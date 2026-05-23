#include <iostream>
#include <climits>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* construct(int arr[], int n) {
    queue<Node*> q;
    Node* root = new Node(arr[0]);
    q.push(root);

    int i = 1, j = 2;
    while(q.size() > 0 && i < n) {
        Node* temp = q.front();
        q.pop();

        Node* l = NULL;
        Node* r = NULL;

        if(arr[i] != INT_MIN) l = new Node(arr[i]);
        else l = NULL;
        if(j < n && arr[j] != INT_MIN) r = new Node(arr[j]);
        else r = NULL;

        temp->left = l;
        temp->right = r;

        if(l) q.push(l);
        if(r) q.push(r);

        i += 2;
        j += 2;
    }

    return root;
}

void leftBoundary(Node* root) {
    if (root == NULL) return;
    if(root->left==NULL && root->right==NULL) return; // leaf node
    cout << root->val << " "; // work
    if(root->left) leftBoundary(root->left);
    else leftBoundary(root->right);  // root->left is NULL but root->right is not NULL
}

void leafNodes(Node* root) {
    if (root == NULL) return;
    if(root->left==NULL && root->right==NULL) {
        cout << root->val << " "; // work
        return;
    }
    leafNodes(root->left);
    leafNodes(root->right);
}

void rightBoundary(Node* root) {
    if (root == NULL) return;
    if(root->left==NULL && root->right==NULL) return; // leaf node
    if(root->right) rightBoundary(root->right);
    else rightBoundary(root->left);  // root->right is NULL but root->left is not NULL
    cout << root->val << " "; // work
}

int level(Node* root) {
    if (root == NULL) return 0; // height of an empty tree is 0
    return 1 + max(level(root->left), level(root->right));
}

void nthLevel(Node* root, int curr, int level) {
    if (root == NULL) return; // base case
    if (curr == level) {
        cout << root->val << " "; // work
        return;
    }
    nthLevel(root->left, curr+1, level); 
    nthLevel(root->right, curr+1, level);
}

void levelOrder(Node* root) {
    int n = level(root);
    for(int i=1; i<=n; i++) {
        nthLevel(root, 1, i);
        cout << endl;
    }
}

void boundaryTraversal(Node* root) {
    if (root == NULL) return;
    leftBoundary(root);
    leafNodes(root);
    rightBoundary(root->right); // the root node as it is already printed in left boundary
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, INT_MIN, 6, 7, INT_MIN, 8,INT_MIN, 9, 10, INT_MIN, 11, INT_MIN,12, INT_MIN, 13, INT_MIN, 14, 15, 16, INT_MIN, 17,INT_MIN, INT_MIN, 18, INT_MIN, 19, INT_MIN, INT_MIN, INT_MIN, 20, 21, 22, 23, INT_MIN, 24, 25, 26, 27, INT_MIN, INT_MIN, 28, INT_MIN, INT_MIN}; 
    int n = sizeof(arr)/sizeof(arr[0]);

    Node* root = construct(arr, n);
    // levelOrder(root);

    boundaryTraversal(root);
    return 0;
}