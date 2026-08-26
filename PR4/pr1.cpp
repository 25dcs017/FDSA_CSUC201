#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class List
{
    Node *head;

public:
    List()
    {
        head = NULL;
    }

    // Insert at front
    void insertFront(int value)
    {
        Node *newNode = new Node(value);

        newNode->next = head;
        head = newNode;
    }

    // Insert at end
    void insertEnd(int value)
    {
        Node *newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // Insert at specific position
    void insertAtPosition(int value, int position)
    {
        // Position 1 means insert at front
        if (position == 1)
        {
            insertFront(value);
            return;
        }

        Node *temp = head;

        // Move to node before required position
        for (int i = 1; i < position - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        // Invalid position
        if (temp == NULL)
        {
            cout << "Invalid position!" << endl;
            return;
        }

        Node *newNode = new Node(value);

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Traversal
    void display()
    {
        Node *temp = head;

        if (head == NULL)
        {
            cout << "Queue is empty." << endl;
            return;
        }

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main()
{
    List queue;

    // Critical patient → front
    queue.insertFront(101);
    cout << "After inserting 101 at front: ";
    queue.display();

    // Routine patient → end
    queue.insertEnd(102);
    cout << "After inserting 102 at end: ";
    queue.display();

    // Routine patient → end
    queue.insertEnd(103);
    cout << "After inserting 103 at end: ";
    queue.display();

    // Priority patient → position 2
    queue.insertAtPosition(105, 2);
    cout << "After inserting 105 at position 2: ";
    queue.display();

    // Invalid position
    queue.insertAtPosition(110, 10);
    cout << "Final queue: ";
    queue.display();

    return 0;
}