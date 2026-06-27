#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void display(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

void reorder(queue<int>& q){
    stack<int> st;
    // step 1: push first half elements into stack
    int n = q.size();
    for(int i = 0; i < n / 2; i++){
        st.push(q.front());
        q.pop();
    }

    // step 2: enqueue back the stack elements
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }

    // step 3: move the remaining elements to the back
    for(int i = 0; i < n / 2; i++){
        q.push(q.front());
        q.pop();
    }

    // step 4: push the first half elements into stack again
    for(int i = 0; i < n / 2; i++){
        st.push(q.front());
        q.pop();
    }

    // step 5: interleave the elements of stack and queue
    while(!st.empty()){
        q.push(st.top());
        st.pop();
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);

    cout << "Original queue: ";
    display(q);

    reorder(q);

    cout << "After reorder: ";
    display(q);

    return 0;
}