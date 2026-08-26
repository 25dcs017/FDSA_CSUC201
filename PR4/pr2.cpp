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
        if (position == 1)
        {
            insertFront(value);
            return;
        }

        Node *temp = head;

        for (int i = 1; i < position - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Invalid position!" << endl;
            return;
        }

        Node *newNode = new Node(value);

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete by value
    void deleteByValue(int value)
    {
        if (head == NULL)
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        // If first node contains the value
        if (head->data == value)
        {
            Node *temp = head;
            head = head->next;
            delete temp;

            cout << value << " deleted." << endl;
            return;
        }

        Node *temp = head;

        // Find node before the node to delete
        while (temp->next != NULL &&
               temp->next->data != value)
        {
            temp = temp->next;
        }

        // Value not found
        if (temp->next == NULL)
        {
            cout << value << " not found." << endl;
            return;
        }

        Node *deleteNode = temp->next;

        temp->next = deleteNode->next;

        delete deleteNode;

        cout << value << " deleted." << endl;
    }

    // Forward traversal
    void displayForward()
    {
        Node *temp = head;

        cout << "Front to Back: ";

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    // Reverse printing using recursion
    void displayReverse(Node *temp)
    {
        if (temp == NULL)
            return;

        displayReverse(temp->next);

        cout << temp->data << " ";
    }

    void reversePrint()
    {
        cout << "Back to Front: ";
        displayReverse(head);
        cout << endl;
    }
};

int main()
{
    List queue;

    // Creating queue
    queue.insertEnd(101);
    queue.insertEnd(102);
    queue.insertEnd(103);
    queue.insertEnd(104);
    queue.insertEnd(105);

    cout << "Original Queue:" << endl;
    queue.displayForward();

    // Delete patient
    queue.deleteByValue(103);

    cout << "\nAfter deletion:" << endl;
    queue.displayForward();

    // Reverse printing
    cout << "\nEnd-of-day audit:" << endl;
    queue.reversePrint();

    // Forward traversal again
    cout << "\nCurrent Queue:" << endl;
    queue.displayForward();

    return 0;
}