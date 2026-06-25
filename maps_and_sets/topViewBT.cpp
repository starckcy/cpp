#include <iostream>
#include <climits>
#include <queue>
#include <unordered_map>
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

void topView(Node* root){
    unordered_map<int, int> m;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    m[0] = root->val;
    while(!q.empty()){
        Node* temp = q.front().first;
        int level = q.front().second;
        q.pop();
        if(m.find(level) == m.end()){
            m[level] = temp->val;
        }
        if(temp->left) q.push({temp->left, level-1});
        if(temp->right) q.push({temp->right, level+1});
    }
    int minLevel = INT_MAX, maxLevel = INT_MIN;
    for(auto it : m){
        minLevel = min(minLevel, it.first);
        maxLevel = max(maxLevel, it.first);
    }
    for(int i=minLevel; i<=maxLevel; i++){
        cout << m[i] << " ";
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, INT_MIN, 6, INT_MIN, INT_MIN, 7, 8};
    int n = sizeof(arr)/sizeof(arr[0]);

    Node* root = construct(arr, n);
    levelOrder(root);
    cout << endl;
    cout << "Top View: ";
    topView(root);
    return 0;
}