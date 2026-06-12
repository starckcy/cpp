#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reversek(int k, queue<int>& q){
    if (k > q.size() || k <= 0) return;

    stack<int> st;

    // Step 1: Push first k elements into stack
    for(int i = 0; i < k; i++){
        st.push(q.front());
        q.pop();
    }

    // Step 2: Push back from stack (reversed)
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }

    // Step 3: Move remaining elements to back
    int n = q.size();
    for(int i = 0; i < n - k; i++){
        q.push(q.front());
        q.pop();
    }
}

void display(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    int k = 3;

    cout << "Original queue: ";
    display(q);

    reversek(k, q);

    cout << "After reversing first k elements: ";
    display(q);

    return 0;
}