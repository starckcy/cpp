#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Stack {
    Node* top;

public:
    // Constructor
    Stack() {
        top = NULL;
    }

    // Push (insert at beginning)
    void push(int x) {
        Node* newNode = new Node(x);

        newNode->next = top;
        top = newNode;
    }

    // Pop (remove from beginning)
    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow\n";
            return;
        }

        Node* temp = top;
        top = top->next;
        delete temp;
    }

    // Peek (top element)
    int peek() {
        if (top == NULL) {
            cout << "Stack is empty\n";
            return -1;
        }
        return top->data;
    }

    // Check empty
    bool isEmpty() {
        return (top == NULL);
    }

    // Display (top to bottom)
    void display() {
        if (top == NULL) {
            cout << "Stack is empty\n";
            return;
        }

        Node* temp = top;
        cout << "Stack elements (top to bottom): ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
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