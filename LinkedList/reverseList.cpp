#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(NULL) {}
};

// Helper function to print the linked list
void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Iterative reversal
Node *reverseIterative(Node *head)
{
    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;

    while (current)
    {
        next = current->next; // Save next node
        current->next = prev; // Reverse pointer
        prev = current;       // Move prev forward
        current = next;       // Move current forward
    }
    return prev; // New head
}

// Recursive reversal
Node *reverseRecursive(Node *head)
{
    if (!head || !head->next)
        return head;

    Node *newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

int main()
{
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original List: ";
    printList(head);

    // Reverse Iteratively
    head = reverseIterative(head);
    cout << "Reversed Iteratively: ";
    printList(head);

    // Reverse Recursively
    head = reverseRecursive(head);
    cout << "Reversed Recursively: ";
    printList(head);

    return 0;
}
