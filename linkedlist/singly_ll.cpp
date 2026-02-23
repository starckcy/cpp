#include <iostream>
using namespace std;

// Define the structure of a Node
class Node {
public:
    int value;
    Node* next;
    Node(int value) : value(value), next(NULL) {}
};

// Function to display the linked list
void display(Node* head) {
    
    while (head != NULL) {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating nodes manually
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);

    // Linking nodes together
    a->next = b;  
    b->next = c; 
    c->next = d; 
    d->next = NULL;  

    // Display the linked list
    display(a);

    return 0;
}