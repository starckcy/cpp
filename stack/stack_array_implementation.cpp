#include <iostream>
using namespace std;

#define MAX 100   // Maximum size of stack

class Stack {
    int arr[MAX];
    int top;

public:
    // Constructor
    Stack() {
        top = -1;
    }

    // 🔸 Push operation
    void push(int x) {
        if (top >= MAX - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    // 🔸 Pop operation
    void pop() {
        if (top < 0) {
            cout << "Stack Underflow\n";
            return;
        }
        top--;
    }

    // 🔸 Peek (top element)
    int peek() {
        if (top < 0) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    // 🔸 Check if empty
    bool isEmpty() {
        return (top < 0);
    }

    // 🔸 Display stack
    void display() {
        if (top < 0) {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
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

    return 0;
}