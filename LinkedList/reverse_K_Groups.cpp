#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

Node *reverseKGroup(Node *head, int k)
{
    if (head == nullptr)
        return nullptr;

    Node *curr = head;
    Node *prev = nullptr;
    Node *next = nullptr;

    int count = 0;

    // First check if there are at least k nodes to reverse
    Node *check = head;
    for (int i = 0; i < k; i++)
    {
        if (!check)
            return head; // less than k nodes, return head as is
        check = check->next;
    }

    // Reverse first k nodes
    while (curr != nullptr && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // next is now pointing to (k+1)th node
    if (next != nullptr)
    {
        head->next = reverseKGroup(next, k);
    }

    // prev is the new head after reversing
    return prev;
}

// Helper functions
void addItem(Node *&head, int val)
{
    Node *newItem = new Node(val);
    if (!head)
    {
        head = newItem;
        return;
    }
    Node *itr = head;
    while (itr->next != nullptr)
    {
        itr = itr->next;
    }
    itr->next = newItem;
}

void printList(Node *head)
{
    Node *itr = head;
    while (itr != nullptr)
    {
        cout << itr->data << " -> ";
        itr = itr->next;
    }
    cout << "NULL\n";
}

int main()
{
    Node *head = nullptr;
    addItem(head, 1);
    addItem(head, 2);
    addItem(head, 3);
    addItem(head, 4);
    addItem(head, 5);
    addItem(head, 6);
    addItem(head, 7);

    int k = 3;
    cout << "Original List:\n";
    printList(head);

    head = reverseKGroup(head, k);

    cout << "\nReversed in groups of " << k << ":\n";
    printList(head);

    return 0;
}
