// https://leetcode.com/problems/rotate-list/description/

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
    ListNode *rotateRight(ListNode *head, int k)
    {

        if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return head;

        int cnt = 1;
        ListNode *temp = head;
        while (temp->next != NULL)
        {
            cnt++;
            temp = temp->next;
        }

        temp->next = head;

        ListNode *newTail = head;
        for (int i = 0; i < cnt - k % cnt - 1; i++)
        {
            newTail = newTail->next;
        }

        ListNode *newHead = newTail->next;
        newTail->next = NULL;

        return newHead;
    }
};