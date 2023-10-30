https : // leetcode.com/problems/swap-nodes-in-pairs/description/

        class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head; // No need to swap if the list is empty or has only one node.
        }

        ListNode *newHead = head->next; // New head after swapping.
        ListNode *prev = nullptr;
        ListNode *temps = head;
        ListNode *tempf = head->next;

        while (temps && tempf)
        {
            temps->next = tempf->next;
            tempf->next = temps;

            if (prev)
            {
                prev->next = tempf;
            }

            prev = temps;
            temps = temps->next;

            if (temps)
            {
                tempf = temps->next;
            }
        }

        return newHead;
    }
};
