/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    // Function to add a node at the end of the list
    void addAtLast(ListNode *&head, ListNode *item)
    {
        if (head == nullptr)
        {
            head = item; // Set the head if the list is initially empty
            return;
        }
        ListNode *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = item;
    }

    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *ptr1 = list1;
        ListNode *ptr2 = list2;
        ListNode *newList = nullptr;

        while (ptr1 != nullptr && ptr2 != nullptr)
        {
            if (ptr1->val < ptr2->val)
            {
                ListNode *newNode = new ListNode(ptr1->val);
                addAtLast(newList, newNode);
                ptr1 = ptr1->next;
            }
            else
            {
                ListNode *newNode = new ListNode(ptr2->val);
                addAtLast(newList, newNode);
                ptr2 = ptr2->next;
            }
        }

        // If any nodes remain in either list, append them
        while (ptr1 != nullptr)
        {
            ListNode *newNode = new ListNode(ptr1->val);
            addAtLast(newList, newNode);
            ptr1 = ptr1->next;
        }

        while (ptr2 != nullptr)
        {
            ListNode *newNode = new ListNode(ptr2->val);
            addAtLast(newList, newNode);
            ptr2 = ptr2->next;
        }

        return newList;
    }
};
