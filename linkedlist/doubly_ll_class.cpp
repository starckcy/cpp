#include <iostream>
using namespace std;

// Node class
class Node
{
public:
    int val;
    Node *next;
    Node *prev;

    Node(int v)
    {
        val = v;
        next = NULL;
        prev = NULL;
    }
};

// User defined data structure
class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;
    int size;

    DoublyLinkedList()
    {
        head = tail = NULL;
        size = 0;
    }

    void insertAtEnd(int val)
    {
        Node *temp = new Node(val);

        if (size == 0)
            head = tail = temp;
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }

    void insertAtBeginning(int val)
    {
        Node *temp = new Node(val);

        if (size == 0)
            head = tail = temp;
        else
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        size++;
    }

    void insertAtPosition(int pos, int val)
    {
        if (pos < 0 || pos > size)
            cout << "Invalid position" << endl;

        else if (pos == 0)
            insertAtBeginning(val);

        else if (pos == size)
            insertAtEnd(val);

        else
        {
            Node *t = new Node(val);
            Node *temp = head;

            for (int i = 1; i < pos; i++)
            {
                t = t->next;
            }

            t->next = temp->next;
            temp->next = t;
            t->prev = temp;
            t->next->prev = t;

            size++;
        }
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
            if (index < size / 2)
            {
                Node *temp = head;
                for (int i = 0; i < index; i++)
                {
                    temp = temp->next;
                }
                return temp->val;
            }
            else
            {
                Node *temp = tail;
                for (int i = size - 1; i > index; i--)
                {
                    temp = temp->prev;
                }
                return temp->val;
            }
        }
    }

    void deleteAtBeginning()
    {
        if (size == 0)
        {
            cout << "List is empty" << endl;
            return;
        }

        if (size == 1)
        {
            delete head;
            head = tail = NULL;
            size = 0;
            return;
        }

        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;

        size--;
    }

    void deleteAtEnd()
    {
        if (size == 0)
        {
            cout << "List is empty" << endl;
            return;
        }

        if (size == 1)
        {
            delete head;
            head = tail = NULL;
            size = 0;
            return;
        }

        Node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;

        size--;
    }

    void deleteAtPosition(int pos)
    {
        if (pos < 0 || pos >= size)
        {
            cout << "Invalid position" << endl;
            return;
        }

        else if (pos == 0)
        {
            deleteAtBeginning();
            return;
        }

        else if (pos == size - 1)
        {
            deleteAtEnd();
            return;
        }

        else
        {
            Node *temp = head;

            for (int i = 1; i < pos; i++)
            {
                temp = temp->next;
            }

            Node *t = temp->next;
            temp->next = t->next;
            t->next->prev = temp;
            delete t;
            size--;
        }

    }

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

    Node *concatenate(Node *head1, Node *head2)
    {
        if (head1 == NULL)
            return head2;

        Node *temp = head1;

        // go to last node of first list
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        // link last node to head2
        temp->next = head2;

        return head1;
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
    DoublyLinkedList dll;

    dll.insertAtEnd(10); // {10 -> NULL}
    dll.insertAtEnd(20); // {10 -> 20 -> NULL}
    dll.insertAtEnd(30); // {10 -> 20 -> 30 -> NULL}

    dll.insertAtBeginning(5); // {5 -> 10 -> 20 -> 30 -> NULL}
    dll.insertAtBeginning(1); // {1 -> 5 -> 10 -> 20 -> 30 -> NULL}
    dll.display();

    dll.insertAtPosition(2, 30); // {1 -> 5 -> 30 -> 10 -> 20 -> 30 -> NULL}
    dll.display();
    dll.insertAtPosition(0, 5);  // {5 -> 1 -> 5 -> 30 -> 10 -> 20 -> 30 -> NULL}
    dll.insertAtPosition(5, 50); // {5 -> 1 -> 5 -> 30 -> 10 -> 50 -> 20 -> 30 -> NULL}

    dll.display();

    cout << "Element at index 2: " << dll.getElementAtIndex(2) << endl;

    dll.deleteAtBeginning(); // {1 -> 5 -> 30 -> 10 -> 50 -> 20 -> 30 -> NULL}
    dll.display();

    dll.deleteAtEnd(); // {1 -> 5 -> 30 -> 10 -> 50 -> 20 -> NULL}
    dll.display();

    dll.deleteAtPosition(2); // {1 -> 5 -> 10 -> 50 -> 20 -> NULL}
    dll.display();

    dll.reverse(); // {20 -> 50 -> 10 -> 5 -> 1 -> NULL}
    dll.display();

    DoublyLinkedList dll2;
    dll2.insertAtEnd(40);
    dll2.insertAtEnd(50);
    dll2.display();

    Node *concatenated = dll.concatenate(dll.head, dll2.head);
    DoublyLinkedList dll3;
    dll3.head = concatenated;
    dll3.size = dll.size + dll2.size;
    dll3.display();

    return 0;
}