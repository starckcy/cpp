#include <iostream>
#include <climits>
#include <queue>
using namespace std;

class Node {  // this is a tree node
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

void nthLevelrev(Node* root, int curr, int level) {
    if (root == NULL) return; // base case
    if (curr == level) {
        cout << root->val << " "; // work
        return;
    }
    nthLevelrev(root->right, curr+1, level); 
    nthLevelrev(root->left, curr+1, level);
}

void levelOrder(Node* root) {
    int n = level(root);
    for(int i=1; i<=n; i++) {
        nthLevel(root, 1, i);
        cout << endl;
    }
}

void levelOrderrev(Node* root) {
    int n = level(root);
    for(int i=1; i<=n; i++) {
        nthLevelrev(root, 1, i);
        cout << endl;
    }
}

// bfs
void levelorderqueue(Node* root){
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout << temp->val << " ";
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}

int main() {
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    
    levelOrder(a);
    cout << endl;
    levelOrderrev(a);
    cout << endl;
    levelorderqueue(a);
    cout << endl;
    return 0;
}