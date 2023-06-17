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

// Approach 2 Using fast and slow pointers
class Solution
{
public:
    ListNode *getMiddle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        // 2 nodes
        if (head->next->next == NULL)
        {
            return head->next;
        }

        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                fast = fast->next;
            }
            slow = slow->next;
        }
        return slow;
    }

    ListNode *middleNode(ListNode *head)
    {
        return getMiddle(head);
    }
};