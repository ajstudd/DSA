#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    // Direct constructor for doubly linked list node initialisation
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// +-------------------+     +-------------------+     +-------------------+     +-------------------+
// |       data        |<--->|       data        |<--->|       data        |<--->|       data        |
// |-------------------|     |-------------------|     |-------------------|     |-------------------|
// |     prev   <------|     |     prev   <------|     |     prev   <------|     |     prev   <------|
// |       next ------>|     |       next ------>|     |       next ------>|     |       next ------>|
// +-------------------+     +-------------------+     +-------------------+     +-------------------+
//     (head)                    (node1)                  (node2)                 (tail)

void addAtEnd(Node *&head, int data)
{
    Node *newNode = new Node(data);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteNode(Node *&head, int key)
{
    if (head == nullptr)
        return;

    Node *temp = head;
    while (temp != nullptr && temp->data != key)
    {
        temp = temp->next;
    }
    if (temp == nullptr)
        return; // Key not found

    if (temp == head)
    {
        head = temp->next;
        if (head != nullptr)
            head->prev = nullptr;
    }
    else
    {
        if (temp->next != nullptr)
            temp->next->prev = temp->prev;
        if (temp->prev != nullptr)
            temp->prev->next = temp->next;
    }

    delete temp;
}

void insertAtPosition(Node *&head, int data, int position)
{
    Node *newNode = new Node(data);
    if (position == 1)
    {
        newNode->next = head;
        if (head != nullptr)
            head->prev = newNode;
        head = newNode;
        return;
    }

    Node *temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; i++)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
        return; // Position is out of bounds

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != nullptr)
        temp->next->prev = newNode;
    temp->next = newNode;
}

void sortDoublyLinkedList(Node *&head)
{
    if (head == nullptr)
        return;

    Node *sorted = nullptr;
    Node *current = head;

    while (current != nullptr)
    {
        Node *next = current->next;
        current->prev = current->next = nullptr;

        if (sorted == nullptr || sorted->data >= current->data)
        {
            current->next = sorted;
            if (sorted != nullptr)
                sorted->prev = current;
            sorted = current;
        }
        else
        {
            Node *temp = sorted;
            while (temp->next != nullptr && temp->next->data < current->data)
            {
                temp = temp->next;
            }

            current->next = temp->next;
            if (temp->next != nullptr)
                temp->next->prev = current;
            temp->next = current;
            current->prev = temp;
        }
        current = next;
    }
    head = sorted;
}

int main()
{
    Node *head = nullptr;

    addAtEnd(head, 5);
    addAtEnd(head, 11);
    addAtEnd(head, 2);
    addAtEnd(head, 3);

    Node *looper = head;
    while (looper != nullptr)
    {
        cout << looper->data << "<--->";
        looper = looper->next;
    }
    cout << "END" << endl;

    deleteNode(head, 11);
    cout << "After deletion of number: " << endl;
    looper = head;
    while (looper != nullptr)
    {
        cout << looper->data << "<--->";
        looper = looper->next;
    }
    cout << "END" << endl;

    insertAtPosition(head, 69, 2);
    cout << "After addition of number: " << endl;
    looper = head;
    while (looper != nullptr)
    {
        cout << looper->data << "<--->";
        looper = looper->next;
    }
    cout << "END" << endl;

    sortDoublyLinkedList(head);
    cout << "After sorting of list: " << endl;
    looper = head;
    while (looper != nullptr)
    {
        cout << looper->data << "<--->";
        looper = looper->next;
    }
    cout << "END";

    return 0;
}