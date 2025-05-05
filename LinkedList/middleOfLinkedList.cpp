#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

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

int middleOfList(Node *&head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int main()
{
    Node *head = nullptr;
    addItem(head, 5);
    addItem(head, 7);
    addItem(head, 9);
    addItem(head, 11);
    addItem(head, 15);
    addItem(head, 17);
    addItem(head, 12);
    addItem(head, 199);
    cout << "Mid: " << middleOfList(head);
    return 0;
}
