// head --> [data | next] --> [data | next] --> [data | next] --> (head)
#include <iostream>
using namespace std;

// the logic is simple here, no matter how much the linked and connected each node are with other circularly,
// as long as we have the head intact we are good.

struct Node
{
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

void insertEnd(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        head = newNode;
        newNode->next = head; // Points to itself if only node.
        return;
    }
    Node *temp = head;
    while (temp->next != head)
    { // Traverse until the last node
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head; // Complete the circle.
}

void insertBegin(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        head = newNode;
        newNode->next = head; // Points to itself if only node.
        return;
    }
    Node *temp = head;
    while (temp->next != head)
    { // Traverse to last node
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    head = newNode;
}

void deleteBegin(Node *&head)
{
    if (!head)
        return; // Empty list check
    if (head->next == head)
    {
        delete head;
        head = nullptr;
        return;
    }
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = head->next;
    Node *toDelete = head;
    head = head->next;
    delete toDelete;
}

void deleteEnd(Node *&head)
{
    if (!head)
        return; // Empty list check
    if (head->next == head)
    {
        delete head;
        head = nullptr;
        return;
    }
    Node *temp = head;
    while (temp->next->next != head)
    {
        temp = temp->next;
    }
    Node *toDelete = temp->next;
    temp->next = head;
    delete toDelete;
}

void sortList(Node *head)
{
    if (!head)
        return;
    bool swapped;
    do
    {
        swapped = false;
        Node *temp = head;
        while (temp->next != head)
        {
            if (temp->data > temp->next->data)
            {
                swap(temp->data, temp->next->data);
                swapped = true;
            }
            temp = temp->next;
        }
    } while (swapped);
}

int main()
{
    Node *head = nullptr;
    insertBegin(head, 10);
    insertEnd(head, 15);
    insertBegin(head, 11);
    insertEnd(head, 16);

    Node *temp = head;
    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head); // Stop when we come back to the head

    cout << "(back to head)" << endl;
    return 0;
}