//* https://leetcode.com/problems/merge-nodes-in-between-zeros

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
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *res = new ListNode(-1);
        ListNode *temp = res;
        int sum = 0;

        ListNode *tempo = head->next;

        while (tempo != NULL)
        {
            if (tempo->val == 0)
            {
                ListNode *newNode = new ListNode(sum);
                temp->next = newNode;
                temp = temp->next;
                sum = 0;
            }
            else
            {
                sum += tempo->val;
            }
            tempo = tempo->next;
        }
        return res->next;
    }
};