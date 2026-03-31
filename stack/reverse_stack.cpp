#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s, temp1, temp2;

    // Original stack
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    // Step 1: Move from s → temp1
    while (!s.empty()) {
        temp1.push(s.top());
        s.pop();
    }

    // Step 2: Move from temp1 → temp2
    while (!temp1.empty()) {
        temp2.push(temp1.top());
        temp1.pop();
    }

    // Step 3: Move from temp2 → s (reversed stack)
    while (!temp2.empty()) {
        s.push(temp2.top());
        temp2.pop();
    }

    // Print reversed stack
    cout << "Reversed stack (top to bottom): ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}