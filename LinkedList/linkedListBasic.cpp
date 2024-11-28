#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

int main()
{
    // Ye bann gya pointer , and we made a new node, so it points to the new node, 2 kaam ho gya. Ponter bhi bann gya and node bhi bann gya.

    Node *head = new Node();
    // data fill kar diya
    head->data = 5;
    // pointer initialise kar diya
    head->next = nullptr;

    // ab bana second pointer , normally program mei function ya iteration se ek hi pointer sara node create kar ke initialise kar deta'
    // but for understanding I am here making second pointer.
    Node *second = new Node();
    second->data = 6;
    second->next = nullptr;

    // connect kr diya first node ko second node se
    head->next = second;

    cout << "First node data is : " << head->data << endl;
    cout << "Second node data is : " << second->data << endl;
    cout << "Accessing data of second node while using pointer of first node : " << head->next->data << endl;

    // ab apne ko traverse krna hai
    // we will make a pointer to the first node,
    // because we don't want to loose the original pointer to the first node,
    // phir to starting kabhi khoj hi nahi payenge

    // we just made a pointer to the whole first node actually.
    // we can access the 'next' pointer and data of first node with this.
    Node *anotherPointer = head;
    cout << "Data of the linked list" << endl;
    // checking the end of the list
    // here I have written anotherPointer->next !=nullptr, instead if the anotherPointer itself is null pointer
    // because I want to use another pointer again to insert an element at the last.
    // otherwise I would have written anotherPointer !=nullptr.
    // as inside the loop I am setting         anotherPointer = anotherPointer->next;
    // at the end it would make the anotherPointer null as the last node's next points to nullptr.
    // but I have stopped it one step before.
    while (anotherPointer->next != nullptr)
    {
        // printing the data
        cout << anotherPointer->data << "->";
        // making the pointer to point to the linked lists next element so that we can access that element and display data
        anotherPointer = anotherPointer->next;
    }
    // this is to print the last node data as the loop was not paring the last item.
    cout << anotherPointer->data << " -> ";
    cout << "NULL" << endl;

    // ab humlog karenge new element add
    // uske liye last element takk jaake , uska pointer ko new node pe point krna hai.

    // bnate hai new node.
    Node *newItem = new Node();
    newItem->data = 115;
    newItem->next = nullptr;

    // normally to iterate krna parta last takk.
    // but apna 'anotherPointer' already last pe pahuncha hua hai.
    //  so we will use it.
    anotherPointer->next = newItem;
    // anotherPointer = newItem;

    // ab phir se karo iterate :
    Node *iterator = head;
    cout << "Data of the linked list after adding item: " << endl;
    // checking the end of the list
    while (iterator != nullptr)
    {
        // printing the data
        cout << iterator->data << "->";
        // making the pointer to point to the linked lists next element so that we can access that element and display data
        iterator = iterator->next;
    }
    cout << "NULL";

    return 0;
}