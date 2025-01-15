class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        // If list is empty or has only one node
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode *current = head;

        // Traverse the list
        while (current != nullptr && current->next != nullptr)
        {
            if (current->val == current->next->val)
            {
                // Skip the duplicate node
                ListNode *temp = current->next;
                current->next = current->next->next;
                delete temp; // Free the memory of duplicate node
            }
            else
            {
                // Move to next node only if no duplicate is found
                current = current->next;
            }
        }

        return head;
    }
};