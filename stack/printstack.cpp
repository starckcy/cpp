#include <iostream>
#include <stack>
using namespace std;

void printBottomToTop(stack<int> s) {
    // Base case
    if (s.empty()) return;

    int topElement = s.top();
    s.pop();

    // Recursive call
    printBottomToTop(s);

    // Print after recursion
    cout << topElement << " ";
}

// void printBottomToTop(stack<int> s) {
//     stack<int> temp;

    // Reverse stack into temp
    // while (!s.empty()) {
    //     temp.push(s.top());
    //     s.pop();
    // }

    // Print from temp
//     while (!temp.empty()) {
//         cout << temp.top() << " ";
//         temp.pop();
//     }
// }

void displayrev(stack<int> s) {
    // Base case
    if (s.empty()) return;

    int x = s.top();
    cout << x << " ";
    s.pop();
    displayrev(s);
    s.push(x);
}

void display(stack<int> s) {
    // Base case
    if (s.empty()) return;

    int x = s.top();
    s.pop();
    display(s);
    cout << x << " ";
    s.push(x);
}

int main() {
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << "Stack (bottom to top): ";
    display(s);

    return 0;
}