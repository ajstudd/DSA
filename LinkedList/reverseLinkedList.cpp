#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
};

void addItem(Node *&head, int val)
{
    Node *temp = new Node();
    temp->val = val;
    temp->next = nullptr;

    if (head == nullptr)
    {
        head = temp; // If the list is empty, set the new node as head
        return;
    }

    Node *iterate = head;
    while (iterate->next != nullptr) // Traverse to the end of the list
    {
        iterate = iterate->next;
    }
    iterate->next = temp; // Attach the new node to the end of the list
}

// INFO: if you see linked list as NULL->1->2->3->4->5->NULL
//  we're doing NULL<-1<-2<-3<-4<-5<-NULL and our pointer will be at last at the end, then we will start from the end.
// We just reversed the arrows/pointers
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

void iterate(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *head = nullptr;
    addItem(head, 5);
    addItem(head, 6);
    addItem(head, 7);
    addItem(head, 8);
    addItem(head, 9);
    addItem(head, 10);
    addItem(head, 11);
    head = reverseIterative(head);
    iterate(head);
    return 0;
}