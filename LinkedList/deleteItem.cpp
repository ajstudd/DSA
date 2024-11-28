#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

void addItem(Node *&head, int num)
{
    Node *newItem = new Node();
    newItem->data = num;
    newItem->next = nullptr;
    if (head == nullptr)
    {
        head = newItem;
        return;
    }

    else
    {
        Node *iterator = head;
        while (iterator->next != nullptr)
        {
            iterator = iterator->next;
        }
        iterator->next = newItem;
    }
}

void remove(Node *head, int target)
{
    Node *temp = head;
    if (head == nullptr)
    {
        return;
    }
    while (temp->next->data != target)
    {
        temp = temp->next;
    }
    temp->next = temp->next->next;
};

int main()
{
    // create an Node pointer which points to nullptr for now
    // visual head → nullptr
    Node *head = nullptr;
    // adding items one by one , ow we can loop if we want to.
    addItem(head, 5);
    addItem(head, 6);
    addItem(head, 7);
    addItem(head, 8);
    addItem(head, 9);
    Node *iterator = head;
    cout << "Data of the linked list after adding item: " << endl;
    while (iterator != nullptr)
    {
        cout << iterator->data << "->";
        iterator = iterator->next;
    }
    cout << "NULL" << endl;
    remove(head, 6);

    Node *newLooper = head;
    cout << "Data of the linked list after removing item: " << endl;
    while (newLooper != nullptr)
    {
        cout << newLooper->data << "->";
        newLooper = newLooper->next;
    }
    cout << "NULL";
    return 0;
}