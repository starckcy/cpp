#include <iostream>
#include <vector>
using namespace std;

class Stack {
    vector<int> v;

public:
    // 🔸 Push
    void push(int x) {
        v.push_back(x);
    }

    // 🔸 Pop
    void pop() {
        if (v.empty()) {
            cout << "Stack Underflow\n";
            return;
        }
        v.pop_back();
    }

    // 🔸 Peek (top element)
    int peek() {
        if (v.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return v.back();
    }

    // 🔸 Check empty
    bool isEmpty() {
        return v.empty();
    }

    // 🔸 Size
    int size() {
        return v.size();
    }

    // 🔸 Display (top to bottom)
    void display() {
        if (v.empty()) {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Stack elements (top to bottom): ";
        for (int i = v.size() - 1; i >= 0; i--) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    cout << "Top element: " << s.peek() << endl;

    s.pop();
    s.display();

    cout << "Size: " << s.size() << endl;

    return 0;
}