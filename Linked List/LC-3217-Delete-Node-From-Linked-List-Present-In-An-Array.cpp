//* https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array

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
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        unordered_set<int> valueToDelete(nums.begin(), nums.end());

        while (head != NULL && valueToDelete.contains(head->val) > 0)
        {
            ListNode *temp = head;
            head = head->next;
            delete temp;
        }

        if (head == NULL)
        {
            return NULL;
        }

        ListNode *curr = head;
        while (curr->next != NULL)
        {
            if (valueToDelete.contains(curr->next->val) > 0)
            {
                ListNode *temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            }
            else
            {
                curr = curr->next;
            }
        }
        return head;
    }
};