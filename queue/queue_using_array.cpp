#include <iostream>
using namespace std;

class Queue {
    int *arr;
    int front, rear, size;

public:
    Queue(int s) {
        size = s;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    // Enqueue (Insert)
    void enqueue(int x) {
        if (rear == size - 1) {
            cout << "Queue Overflow\n";
            return;
        }
        arr[rear++] = x;
    }

    // Dequeue (Remove)
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow\n";
            return;
        }
        cout << "Removed: " << arr[front++] << endl;
    }

    // Get front element
    int peek() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    // Check if empty
    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    // Size of the queue
    int getSize(){
        return rear - front;
    }

    // Display queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        for (int i = front; i < rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();
    q.display();

    cout << "Front element: " << q.peek() << endl;

    return 0;
}