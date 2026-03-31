#include <iostream>
#include <stack>
using namespace std;

// Insert at given index (0 = bottom)
void pushAtIndex(stack<int> &s, int x, int index) {
    // Base case
    if (index == 0) {
        s.push(x);
        return;
    }

    // If stack is empty before reaching index
    if (s.empty()) {
        cout << "Index out of range" << endl;
        return;
    }

    int topElement = s.top();
    s.pop();

    // Recursive call
    pushAtIndex(s, x, index - 1);

    // Restore element
    s.push(topElement);
}

// iterative approach
// void pushAtIndex(stack<int> &s, int x, int index) {
//     stack<int> temp;
//     int i = 0;
//     while (i < index && !s.empty()) {
//         temp.push(s.top());
//         s.pop();
//         i++;
//     }
//     if (i < index) {
//         cout << "Index out of range\n";
//         // Restore stack
//         while (!temp.empty()) {
//             s.push(temp.top());
//             temp.pop();
//         }
//         return;
//     }
//     s.push(x);
//     while (!temp.empty()) {
//         s.push(temp.top());
//         temp.pop();
//     }
// }

void printstack(stack<int> s) {
    // Base case
    if (s.empty()) return;

    int topElement = s.top();
    s.pop();

    // Recursive call
    printstack(s);

    // Print after recursion
    cout << topElement << " ";
}

int main() {
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    printstack(s);
    cout << endl;

    pushAtIndex(s, 99, 2);

    // Print stack
    printstack(s);

    return 0;
}