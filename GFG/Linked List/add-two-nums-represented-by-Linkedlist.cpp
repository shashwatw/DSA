// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-linkedlists/problem/add-two-numbers-represented-by-linked-lists

//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Node *buildList(int size)
{
    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

// } Driver Code Ends
/* node for linked list:

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
    // Function to add two numbers represented by linked list.

    struct Node *revLL(struct Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        struct Node *curr = head;
        struct Node *prev = NULL;

        while (curr != NULL)
        {
            struct Node *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }

    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {
        struct Node *rev1 = revLL(first);
        struct Node *rev2 = revLL(second);

        struct Node *tempy1 = rev1;
        struct Node *tempy2 = rev2;
        struct Node *result = NULL;
        struct Node *current = NULL;
        int carry = 0;

        while (tempy1 != NULL || tempy2 != NULL)
        {
            int sum = (tempy1 ? tempy1->data : 0) + (tempy2 ? tempy2->data : 0) + carry;

            struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->data = sum % 10;
            newNode->next = NULL;

            carry = sum / 10;

            if (result == NULL)
            {
                result = newNode;
                current = result;
            }
            else
            {
                current->next = newNode;
                current = newNode;
            }

            if (tempy1)
                tempy1 = tempy1->next;
            if (tempy2)
                tempy2 = tempy2->next;
        }

        if (carry > 0)
        {
            struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->data = carry;
            newNode->next = NULL;
            current->next = newNode;
        }

        // Reverse the result to get the final answer
        result = revLL(result);

        return result;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;

        cin >> n;
        Node *first = buildList(n);

        cin >> m;
        Node *second = buildList(m);
        Solution ob;
        Node *res = ob.addTwoLists(first, second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends