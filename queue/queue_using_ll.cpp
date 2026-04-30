#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Queue class
class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = NULL;
    }

    // Enqueue operation
    void enqueue(int x) {
        Node* newNode = new Node(x);

        if (rear == NULL) {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    // Dequeue operation
    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow\n";
            return;
        }

        Node* temp = front;
        cout << "Removed: " << temp->data << endl;

        front = front->next;

        if (front == NULL) rear = NULL;
        
        delete temp;
    }

    // Peek front element
    int peek() {
        if (front == NULL) {
            cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }

    // Check if empty
    bool isEmpty() {
        return (front == NULL);
    }

    // Display queue
    void display() {
        if (front == NULL) {
            cout << "Queue is empty\n";
            return;
        }

        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();
    q.display();

    cout << "Front element: " << q.peek() << endl;

    return 0;
}