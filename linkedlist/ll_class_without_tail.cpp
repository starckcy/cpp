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

// LinkedList class (WITHOUT tail)
class LinkedList
{
public:
    Node *head;
    int size;

    LinkedList()
    {
        head = NULL;
        size = 0;
    } 

    // Insert at end (O(n))
    void insertAtEnd(int val)
    {
        Node *temp = new Node(val);

        if (size == 0)
        {
            head = temp;
        }
        else
        {
            Node *t = head;
            while (t->next != NULL)
            {
                t = t->next;
            }
            t->next = temp;
        }

        size++;
    }

    // Insert at beginning
    void insertAtBeginning(int val)
    {
        Node *temp = new Node(val);

        if (size == 0)
        {
            head = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }

        size++;
    }

    // Insert at position
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

    // Get element by index
    int getElementAtIndex(int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "Invalid index" << endl;
            return -1;
        }

        Node *temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }

        return temp->val;
    }

    // Delete at beginning
    void deleteAtBeginning()
    {
        if (size == 0)
        {
            cout << "List empty" << endl;
            return;
        }

        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    // Delete at end (O(n))
    void deleteAtEnd()
    {
        if (size == 0)
        {
            cout << "List empty" << endl;
            return;
        }

        if (size == 1)
        {
            delete head;
            head = NULL;
            size = 0;
            return;
        }

        Node *temp = head;
        while (temp->next->next != NULL) 
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
        size--;
    }

    // Delete at position
    void deleteAtPosition(int pos)
    {
        if (pos < 0 || pos >= size)
        {
            cout << "Invalid position" << endl;
            return;
        }

        if (pos == 0)
        {
            deleteAtBeginning();
            return;
        }

        Node *temp = head;
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }

        Node *toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
        size--;
    }

    // Reverse the linked list
    void reverse()
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *next = NULL;

        while (curr != NULL)
        {
            next = curr->next; // save next
            curr->next = prev; // reverse link
            prev = curr;       // move prev
            curr = next;       // move curr
        }

        head = prev;
    }

    // Concatenate two linked lists
    Node* concatenate(Node* head1, Node* head2) {
    if (head1 == NULL)
        return head2;

    Node* temp = head1;

    // go to last node of first list
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // link last node to head2
    temp->next = head2;

    return head1;
}

    // Display list
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

    ll.insertAtEnd(10);
    ll.insertAtEnd(20);
    ll.insertAtEnd(30);

    ll.insertAtBeginning(5);
    ll.insertAtBeginning(1);
    ll.display();

    ll.insertAtPosition(2, 30);
    ll.display();

    ll.insertAtPosition(0, 5);
    ll.insertAtPosition(5, 50);
    ll.display();

    cout << "Element at index 2: " << ll.getElementAtIndex(2) << endl;

    ll.deleteAtBeginning();
    ll.display();

    ll.deleteAtEnd();
    ll.display();

    ll.deleteAtPosition(2);
    ll.display();

    ll.reverse(); // {20 -> 50 -> 10 -> 5 -> 1 -> NULL}
    ll.display();

     LinkedList ll2;
    ll2.insertAtEnd(40);
    ll2.insertAtEnd(50);
    ll2.display();

    Node* concatenated = ll.concatenate(ll.head, ll2.head);
    LinkedList ll3;
    ll3.head = concatenated;
    ll3.size = ll.size + ll2.size;
    ll3.display();

    return 0;
}