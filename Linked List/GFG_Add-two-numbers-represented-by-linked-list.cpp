//^ https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

/*  node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
public:
    Node *revLL(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        Node *curr = head;
        Node *prev = NULL;
        Node *next = NULL;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void insertAtTail(Node *&head, Node *&tail, int val)
    {
        Node *temp = new Node(val);

        if (head == NULL)
        {
            head = temp;
            tail = temp;
            return;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    // Function to add two numbers represented by linked list.
    struct Node *addTwoLists(struct Node *num1, struct Node *num2)
    {
        // code here

        // remove leading zeroes
        while (num1 != NULL && num1->data == 0)
        {
            num1 = num1->next;
        }

        while (num2 != NULL && num2->data == 0)
        {
            num2 = num2->next;
        }

        if (num1 == NULL && num2 == NULL)
        {
            return new Node(0);
        }

        Node *first = revLL(num1);
        Node *second = revLL(num2);

        int sum = 0;
        int carry = 0;
        int digit = 0;

        Node *ansHead = NULL;
        Node *ansTail = NULL;

        while (first != NULL || second != NULL || carry != 0)
        {
            int val1 = 0;
            if (first != NULL)
            {
                val1 = first->data;
            }

            int val2 = 0;
            if (second != NULL)
            {
                val2 = second->data;
            }

            sum = val1 + val2 + carry;

            digit = sum % 10;
            carry = sum / 10;

            insertAtTail(ansHead, ansTail, digit);

            if (first != NULL)
                first = first->next;

            if (second != NULL)
                second = second->next;
        }

        Node *ans = revLL(ansHead);

        return ans;
    }
};