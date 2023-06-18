https : // leetcode.com/problems/reverse-nodes-in-k-group/description/

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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *curr = head;
        int count = 0;

        if (head == NULL)
        {
            return NULL;
        }

        // Check if there are at least k nodes remaining
        while (curr != nullptr && count < k)
        {
            curr = curr->next;
            count++;
        }

        if (count == k)
        {
            // Reverse the first k nodes
            ListNode *next = nullptr;
            ListNode *prev = nullptr;
            curr = head;
            count = 0;
            while (curr != nullptr && count < k)
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                count++;
            }

            if (next != nullptr)
            {
                // Recurse for the remaining list
                head->next = reverseKGroup(next, k);
            }

            // Return the new head of the reversed group
            return prev;
        }
        else
        {
            // Group doesn't have size k, so return head as is
            return head;
        }
    }
};