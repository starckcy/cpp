#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = next = NULL;
    }
};

// Deque class
class Deque {
    Node* front;
    Node* rear;

public:
    Deque() {
        front = rear = NULL;
    }

    // Insert at front
    void pushFront(int x) {
        Node* temp = new Node(x);

        if (front == NULL) {
            front = rear = temp;
        } else {
            temp->next = front;
            front->prev = temp;
            front = temp;
        }

        cout << "Inserted at front: " << x << endl;
    }

    // Insert at rear
    void pushRear(int x) {
        Node* temp = new Node(x);

        if (rear == NULL) {
            front = rear = temp;
        } else {
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
        }

        cout << "Inserted at rear: " << x << endl;
    }

    // Delete from front
    void popFront() {
        if (front == NULL) {
            cout << "Deque Underflow\n";
            return;
        }

        Node* temp = front;
        cout << "Deleted from front: " << temp->data << endl;

        front = front->next;

        if (front == NULL)
            rear = NULL;
        else
            front->prev = NULL;

        delete temp;
    }

    // Delete from rear
    void popRear() {
        if (rear == NULL) {
            cout << "Deque Underflow\n";
            return;
        }

        Node* temp = rear;
        cout << "Deleted from rear: " << temp->data << endl;

        rear = rear->prev;

        if (rear == NULL)
            front = NULL;
        else
            rear->next = NULL;

        delete temp;
    }

    // Display
    void display() {
        if (front == NULL) {
            cout << "Deque is empty\n";
            return;
        }

        Node* temp = front;
        cout << "Deque elements: ";

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    Deque dq;
    int choice, value;

    while (true) {
        cout << "\n1.Push Front  2.Push Rear  3.Pop Front  4.Pop Rear  5.Display  6.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                dq.pushFront(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                dq.pushRear(value);
                break;

            case 3:
                dq.popFront();
                break;

            case 4:
                dq.popRear();
                break;

            case 5:
                dq.display();
                break;

            case 6:
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
}