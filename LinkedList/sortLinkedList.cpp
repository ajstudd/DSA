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

// INFO: MY Code with issues

// void sort(Node *head)
// {
//     Node *itr = head;
//     int temp;
//     Node *nextptr = head->next;
//     while (itr != nullptr)
//     {
//         while (nextptr != nullptr)
//         {
//             if (itr->data > nextptr->data)
//             {
//                 temp = itr->data;
//                 itr->data = nextptr->data;
//                 nextptr->data = temp;
//                 nextptr = nextptr->next;
//             }
//             else
//             {
//                 nextptr = nextptr->next;
//             }
//         }
//         itr = itr->next;
//         nextptr = itr->next;
//     }
// };

// INFO: GPT Code
void sort(Node *head)
{
    Node *itr = head;
    int temp;

    while (itr != nullptr)
    {
        // Reset nextptr for each new itr position
        Node *nextptr = itr->next;

        while (nextptr != nullptr)
        {
            if (itr->data > nextptr->data)
            {
                // Swap the data
                temp = itr->data;
                itr->data = nextptr->data;
                nextptr->data = temp;
            }
            nextptr = nextptr->next; // Move to the next node
        }
        itr = itr->next; // Move itr to the next node
    }
}

int main()
{
    // create an Node pointer which points to nullptr for now
    // visual head → nullptr
    Node *head = nullptr;
    // adding items one by one , ow we can loop if we want to.
    addItem(head, 5);
    addItem(head, 112);
    addItem(head, 2);
    addItem(head, 15);
    addItem(head, 9);
    Node *iterator = head;
    cout << "Data of the linked list after adding items: " << endl;
    while (iterator != nullptr)
    {
        cout << iterator->data << "->";
        iterator = iterator->next;
    }
    cout << "NULL" << endl;
    sort(head);

    Node *newLooper = head;
    cout << "Data of the linked list after sorting items: " << endl;
    while (newLooper != nullptr)
    {
        cout << newLooper->data << "->";
        newLooper = newLooper->next;
    }
    cout << "NULL";
    return 0;
}