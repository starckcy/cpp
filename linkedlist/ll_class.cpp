#include <iostream>
using namespace std;

// Node class
class Node
{
public:
    int val;
    Node *next;

    Node(int v)
    {
        val = v;
        next = NULL;
    }
};

// User defined data structure
class LinkedList
{
public:
    Node *head;
    Node *tail;
    int size;

    LinkedList()
    {
        head = tail = NULL;
        size = 0;
    }

    void insertAtEnd(int val)
    {
        Node *temp = new Node(val);

        if (size == 0)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }

        size++;
    }

    void insertAtBeginning(int val)
    {
        Node *temp = new Node(val);

        if (size == 0)
        {
            head = tail = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }

        size++;
    }

    void insertAtPosition(int pos, int val)
    {
        if (pos < 0 || pos > size)
        {
            cout << "Invalid position" << endl;
            return;
        }

        if (pos == 0)
        {
            insertAtBeginning(val);
            return;
        }

        if (pos == size)
        {
            insertAtEnd(val);
            return;
        }

        Node *temp = new Node(val);
        Node *t = head;

        for (int i = 1; i < pos; i++)
        {
            t = t->next;
        }

        temp->next = t->next;
        t->next = temp;

        size++;
    }

    int getElementAtIndex(int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "Invalid index" << endl;
            return -1;
        }

        else if (index == 0)
        {
            return head->val;
        }

        else if (index == size - 1)
        {
            return tail->val;
        }

        else
        {
            Node *temp = head;

            for (int i = 0; i < index; i++)
            {
                temp = temp->next;
            }

            return temp->val;
        }
    }

    void deleteAtBeginning() {
        if (size == 0) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;

        size--;

        if (size == 0) tail = NULL;
    }

    void deleteAtEnd() {
        if (size == 0) {
            cout << "List is empty" << endl;
            return;
        }

        if (size == 1) {
            delete head;
            head = tail = NULL;
            size = 0;
            return;
        }

        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }

        delete tail;
        tail = temp;
        tail->next = NULL;
        size--;
    }

    void deleteAtPosition(int pos) {
        if (pos < 0 || pos >= size) {
            cout << "Invalid position" << endl;
            return;
        }

        if (pos == 0) {
            deleteAtBeginning();
            return;
        }

        if (pos == size - 1) {
            deleteAtEnd();
            return;
        }

        Node* temp = head;

        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }

        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;

        size--;
    }

    void display()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main()
{
    LinkedList ll;

    ll.insertAtEnd(10); // {10 -> NULL}
    ll.insertAtEnd(20); // {10 -> 20 -> NULL}
    ll.insertAtEnd(30); // {10 -> 20 -> 30 -> NULL}

    ll.insertAtBeginning(5); // {5 -> 10 -> 20 -> 30 -> NULL}
    ll.insertAtBeginning(1); // {1 -> 5 -> 10 -> 20 -> 30 -> NULL}
    ll.display();

    ll.insertAtPosition(2, 30); // {1 -> 5 -> 30 -> 10 -> 20 -> 30 -> NULL}
    ll.display();
    ll.insertAtPosition(0, 5);  // {5 -> 1 -> 5 -> 30 -> 10 -> 20 -> 30 -> NULL}
    ll.insertAtPosition(5, 50); // {5 -> 1 -> 5 -> 30 -> 10 -> 50 -> 20 -> 30 -> NULL}

    ll.display();

    cout << "Element at index 2: " << ll.getElementAtIndex(2) << endl;

    ll.deleteAtBeginning();  // {1 -> 5 -> 30 -> 10 -> 50 -> 20 -> 30 -> NULL}
    ll.display();

    ll.deleteAtEnd();  // {1 -> 5 -> 30 -> 10 -> 50 -> 20 -> NULL}
    ll.display();

    ll.deleteAtPosition(2);  // {1 -> 5 -> 10 -> 50 -> 20 -> NULL}
    ll.display();

    return 0;
}