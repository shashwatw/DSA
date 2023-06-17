// Approach 1 Iterative Approach
class Solution
{
public:
    int getLength(ListNode *head)
    {
        int len = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            len++;
            temp = temp->next;
        }
        return len;
    }

    ListNode *middleNode(ListNode *head)
    {
        int len = getLength(head);
        int ans = len / 2;

        ListNode *temp1 = head;

        int cnt = 0;
        while (cnt < ans)
        {
            temp1 = temp1->next;
            cnt++;
        }
        return temp1;
    }
};