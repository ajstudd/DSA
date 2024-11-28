#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

// we are bringing a reference to the head (Node *&head) rather than the value of head (Node *head)
// because we want to modify the head in the later program
void addItem(Node *&head, int num)
{
    // creating a new node
    Node *newItem = new Node();
    // putting value and initialising pointer
    newItem->data = num;
    newItem->next = nullptr;

    // why iterate if it is the first element
    // just directly put the value
    // also this block is why we brought the reference to the head
    // so that we can directly set head to the new Item.
    if (head == nullptr)
    {
        head = newItem;
        return;
    }

    // iterate and set new item at last
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

    Node *iterator = head;
    cout << "Data of the linked list after adding item: " << endl;
    while (iterator != nullptr)
    {
        cout << iterator->data << "->";
        iterator = iterator->next;
    }
    cout << "NULL";
    return 0;
}