#include <iostream>
#include <stack>
using namespace std;

// Function to insert element at bottom
void pushAtBottom(stack<int> &s, int x) {
    // Base case
    if (s.empty()) {
        s.push(x);
        return;
    }

    // Store top element
    int topElement = s.top();
    s.pop();

    // Recursive call
    pushAtBottom(s, x);

    // Put back the top element
    s.push(topElement);
}

// iterative approach
// void pushAtbottom(stack<int> &s, int x){
//     stack<int> temp;
//     while(s.size() > 0){
//         temp.push(s.top());
//         s.pop();
//     }
//     s.push(x);
//     while(temp.size() > 0){
//         s.push(temp.top());
//         temp.pop();
//     }
// }

void display(stack<int> s) {
    // Base case
    if (s.empty()) return;

    int x = s.top();
    s.pop();
    display(s);
    cout << x << " ";
    s.push(x);
}

void reverse(stack<int> &s) {
    // Base case
    if (s.empty()) return;

    int x = s.top();
    s.pop();
    reverse(s);
    pushAtBottom(s, x);
}

int main() {
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);

    // Push 0 at bottom
    pushAtBottom(s, 0);

    // Print stack (top to bottom)
    cout << "Stack after pushing at bottom: ";
    display(s);
    cout << endl;
    reverse(s); // To restore original order
    display(s); // To show original order

    return 0;
}