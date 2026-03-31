#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;

    // Push elements
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    // Display top element
    cout << "Top element: " << s.top() << endl;

    // Pop element
    s.pop();

    cout << "Top after pop: " << s.top() << endl;

    // Size of stack
    cout << "Size of stack: " << s.size() << endl;

    // Check if empty
    if (s.empty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }

    return 0;
}