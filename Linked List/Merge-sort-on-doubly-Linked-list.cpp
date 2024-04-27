//^ https://www.geeksforgeeks.org/problems/merge-sort-on-doubly-linked-list/1

//* Here we do not want to modify the existing LL but we want to create a new

/* Structure of the node of the list is as
struct Node
{
    int data;
    struct Node *next, *prev;
    Node (int x){
        data = x;
        next = prev = NULL;
    }
};
*/

class Solution
{
    // Function to sort the given doubly linked list using Merge Sort.
public:
    struct Node *merge(struct Node *a, struct Node *b)
    {
        struct Node *dummy = new Node(-1);
        struct Node *ptr = dummy;

        while (a && b)
        {
            if (a->data <= b->data)
            {
                ptr->next = a;
                a->prev = ptr;
                a = a->next;
            }
            else
            {
                ptr->next = b;
                b->prev = ptr;
                b = b->next;
            }
            ptr = ptr->next;
        }

        while (a)
        {
            ptr->next = a;
            a->prev = ptr;
            a = a->next;
            ptr = ptr->next;
        }
        while (b)
        {
            ptr->next = b;
            b->prev = ptr;
            b = b->next;
            ptr = ptr->next;
        }

        struct Node *ans = dummy->next;
        ans->prev = NULL;
        return ans;
    }

    struct Node *sortDoubly(struct Node *head)
    {
        // Your code here

        //* the base case
        if (head == NULL || head->next == NULL)
            return head;

        //* Lets find the middle node
        struct Node *fast = head;
        struct Node *slow = head;
        struct Node *temp = NULL;

        //* To handle edge case we want first middle node  for the even length list so start fast from one step forward
        while (fast && fast->next)
        {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL;

        //* Slow is the middle node

        //* sort the both parts of the linked list
        struct Node *first = sortDoubly(head);
        struct Node *second = sortDoubly(slow);

        //* now merge and return both the sorted linked list
        return merge(first, second);
    }
};