#include <iostream>
using namespace std;

// Node structure to represent a single element in the list
struct Node
{
    int data;   // Data part of the node
    Node *next; // Pointer to the next node

    // Constructor to create a new node with given data
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

// Singly Linked List class
class SinglyLinkedList
{
private:
    Node *head; // Pointer to the head (first node) of the list

public:
    // Constructor to initialize an empty linked list
    SinglyLinkedList()
    {
        head = nullptr;
    }

    // Function to insert a new node at the end of the list
    void insertEnd(int data)
    {
        Node *newNode = new Node(data); // Create a new node with the given data
        if (head == nullptr)
        {                   // If the list is empty
            head = newNode; // Make the new node the head
        }
        else
        {
            Node *temp = head;            // Temporary pointer to traverse the list
            while (temp->next != nullptr) // Traverse to the last node
                temp = temp->next;
            temp->next = newNode; // Link the last node to the new node
        }
    }

    // Function to insert a new node at the beginning of the list
    void insertBeginning(int data)
    {
        Node *newNode = new Node(data); // Create a new node
        newNode->next = head;           // Point the new node to the current head
        head = newNode;                 // Make the new node the head
    }

    // Function to delete the first node in the list
    void deleteBeginning()
    {
        if (head == nullptr)
        { // Check if the list is empty
            cout << "List is empty, cannot delete.\n";
            return;
        }
        Node *temp = head; // Temporary pointer to hold the head
        head = head->next; // Make the second node the new head
        delete temp;       // Free the old head node
    }

    // Function to delete the last node in the list
    void deleteEnd()
    {
        if (head == nullptr)
        { // Check if the list is empty
            cout << "List is empty, cannot delete.\n";
            return;
        }
        if (head->next == nullptr)
        { // If there is only one node in the list
            delete head;
            head = nullptr;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr && temp->next->next != nullptr)
        { // Traverse to the second last node
            temp = temp->next;
        }
        delete temp->next;    // Delete the last node
        temp->next = nullptr; // Make the second last node the last node
    }

    // Function to search for an element in the list
    bool search(int data)
    {
        Node *temp = head; // Temporary pointer to traverse the list
        while (temp != nullptr)
        { // Traverse until the end of the list
            if (temp->data == data)
            { // If the node contains the data
                return true;
            }
            temp = temp->next;
        }
        return false; // If the data was not found in the list
    }

    // Function to display the contents of the list
    void display()
    {
        if (head == nullptr)
        { // If the list is empty
            cout << "List is empty.\n";
            return;
        }
        Node *temp = head; // Temporary pointer to traverse the list
        while (temp != nullptr)
        {                                 // Traverse until the end of the list
            cout << temp->data << " -> "; // Display the data of the current node
            temp = temp->next;
        }
        cout << "nullptr\n"; // Indicate the end of the list
    }

    // Destructor to delete all nodes and free the memory
    ~SinglyLinkedList()
    {
        while (head != nullptr)
        { // Delete all nodes
            deleteBeginning();
        }
    }
};

int main()
{
    SinglyLinkedList list;

    // Inserting elements into the list
    list.insertEnd(10);      // Insert 10 at the end
    list.insertEnd(20);      // Insert 20 at the end
    list.insertBeginning(5); // Insert 5 at the beginning
    list.insertEnd(30);      // Insert 30 at the end

    // Display the list
    cout << "List after insertion: ";
    list.display();

    // Search for an element in the list
    int key = 20;
    if (list.search(key))
    {
        cout << key << " found in the list.\n";
    }
    else
    {
        cout << key << " not found in the list.\n";
    }

    // Delete elements from the list
    list.deleteBeginning(); // Delete the first element
    list.deleteEnd();       // Delete the last element

    // Display the list after deletion
    cout << "List after deletion: ";
    list.display();

    return 0;
}
