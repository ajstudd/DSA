class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummyHead = new ListNode(0);
        ListNode *itr = dummyHead;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            itr->next = new ListNode(sum % 10);
            itr = itr->next;
            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }
        ListNode *resultHead = dummyHead->next;
        delete dummyHead;
        return resultHead;
    }
};