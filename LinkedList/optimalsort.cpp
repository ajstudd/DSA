#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    // Direct Initialization Constructor
    // constructor to add data and null-pointer to a new node directly.
    // so that we can just point to it directly while adding new node to the list
    Node(int val) : data(val), next(nullptr) {}
};

// Utility function to add item at the end
void addItem(Node *&head, int num)
{
    Node *newItem = new Node(num);
    if (head == nullptr)
    {
        head = newItem;
        return;
    }
    Node *iterator = head;
    while (iterator->next != nullptr)
    {
        iterator = iterator->next;
    }
    iterator->next = newItem;
}

// Function to split the linked list into two halves
void splitList(Node *head, Node *&left, Node *&right)
{
    if (head == nullptr || head->next == nullptr)
    {
        left = head;
        right = nullptr;
        return;
    }

    // concept of slow and fast pointer
    // slow move one step, fast moves two steps at a time.
    // so fast is 2x speed.
    // when fast covers full list, slow is at the half of the list. (Logic my boy! and maths. )
    // slow is the  middle.
    // we can also detect cycle in a list by using slow and fast pointer
    Node *slow = head;
    Node *fast = head->next;

    // Move fast two nodes, and slow one node at a time
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Split the list into two halves
    left = head;
    right = slow->next;
    slow->next = nullptr;
}

// Function to merge two sorted lists
Node *mergeSortedLists(Node *left, Node *right)
{
    if (left == nullptr)
        return right;
    if (right == nullptr)
        return left;

    Node *result = nullptr;

    if (left->data <= right->data)
    {
        result = left;
        result->next = mergeSortedLists(left->next, right);
    }
    else
    {
        result = right;
        result->next = mergeSortedLists(left, right->next);
    }
    return result;
}

// Merge Sort function for linked list
void mergeSort(Node *&head)
{
    if (head == nullptr || head->next == nullptr)
        return;

    Node *left;
    Node *right;

    // Split the list into two halves
    splitList(head, left, right);

    // Sort each half
    mergeSort(left);
    mergeSort(right);

    // Merge the sorted halves
    head = mergeSortedLists(left, right);
}

// Utility function to print the linked list
void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Main function
int main()
{
    Node *head = nullptr;
    addItem(head, 5);
    addItem(head, 112);
    addItem(head, 2);
    addItem(head, 15);
    addItem(head, 9);

    cout << "Linked list before sorting:" << endl;
    printList(head);

    mergeSort(head);

    cout << "Linked list after sorting:" << endl;
    printList(head);

    return 0;
}
