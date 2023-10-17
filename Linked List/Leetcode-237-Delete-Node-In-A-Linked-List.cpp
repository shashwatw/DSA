// https://leetcode.com/problems/delete-node-in-a-linked-list/description/

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        if (node == nullptr || node->next == nullptr)
        {
            return;
        }

        ListNode *nextNode = node->next;
        node->val = nextNode->val;
        node->next = nextNode->next;
        delete nextNode;
    }
};
