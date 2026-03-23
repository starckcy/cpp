#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int v) {
        val = v;
        next = NULL;
    }
};

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() {
        head = NULL;
    }

    // Insert at end
    void insertAtEnd(int val) {
        Node* temp = new Node(val);

        if(head == NULL) {
            head = temp;
            temp->next = head;
            return;
        }

        Node* t = head;
        while(t->next != head) {
            t = t->next;
        }

        t->next = temp;
        temp->next = head;
    }

    // Insert at beginning
    void insertAtBeginning(int val) {
        Node* temp = new Node(val);

        if(head == NULL) {
            head = temp;
            temp->next = head;
            return;
        }

        Node* t = head;
        while(t->next != head) {
            t = t->next;
        }

        temp->next = head;
        t->next = temp;
        head = temp;
    }

    // Insert at position
    void insertAtPosition(int pos, int val) {

    Node* temp = new Node(val);

    if(pos == 0) {
        insertAtBeginning(val);
        return;
    }

    Node* t = head;

    for(int i = 1; i < pos; i++) {
        t = t->next;

        if(t->next == head) {
            cout << "Position out of range\n";
            return;
        }
    }

    temp->next = t->next;
    t->next = temp;
}

    // Delete at beginning
    void deleteAtBeginning() {

        if(head == NULL) {
            cout << "List empty\n";
            return;
        }

        if(head->next == head) {
            delete head;
            head = NULL;
            return;
        }

        Node* t = head;

        while(t->next != head) {
            t = t->next;
        }

        Node* temp = head;
        head = head->next;
        t->next = head;

        delete temp;
    }

    // Delete at end
    void deleteAtEnd() {

        if(head == NULL) {
            cout << "List empty" << endl;
            return;
        }

        if(head->next == head) {
            delete head;
            head = NULL;
            return;
        }

        Node* t = head;

        while(t->next->next != head) {
            t = t->next;
        }

        delete t->next;
        t->next = head;
    }

    // Delete at position
    void deleteAtPosition(int pos) {

    if(head == NULL) {
        cout << "List empty" << endl;
        return;
    }

    if(pos == 0) {
        deleteAtBeginning();
        return;
    }

    Node* t = head;

    for(int i = 1; i < pos; i++) {
        t = t->next;

        if(t->next == head) {
            cout << "Position out of range" << endl;
            return;
        }
    }

    Node* temp = t->next;

    if(temp == head) {
        cout << "Position out of range" << endl;
        return;
    }

    t->next = temp->next;
    delete temp;
}

    // Display circular list
    void display() {

        if(head == NULL) {
            cout << "List empty\n";
            return;
        }

        Node* temp = head;

        do {
            cout << temp->val << " ";
            temp = temp->next;
        } while(temp != head);

        cout << endl;
    }
};

int main() {

    CircularLinkedList cl;

    cl.insertAtEnd(10);
    cl.insertAtEnd(20);
    cl.insertAtEnd(30);

    cl.insertAtBeginning(5);

    cl.display();

    cl.deleteAtBeginning();
    cl.display();

    cl.deleteAtEnd();
    cl.display();

    return 0;
}