// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-linkedlists/problem/rearrange-a-linked-list

//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/* Link list Node */
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

// } Driver Code Ends
/* Node structure

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
//      oh  eh
//      ot  et
//      1   2   3   4   5   6   7   8   9   9
// index:1   2   3   4   5   6   7   8   9   10

class Solution
{
public:
    void rearrangeEvenOdd(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return;

        struct Node *oddHead = head;
        struct Node *evenHead = head->next;
        struct Node *oddTail = head;
        struct Node *evenTail = head->next;

        while (evenTail != NULL && evenTail->next != NULL)
        {
            oddTail->next = evenTail->next;
            oddTail = oddTail->next;

            evenTail->next = oddTail->next;
            evenTail = evenTail->next;
        }
        oddTail->next = evenHead;
    }
};

//{ Driver Code Starts.

/* Driver program to test above function*/
int main()
{
    int T, i, n, l;

    cin >> T;

    while (T--)
    {
        struct Node *head = NULL;
        struct Node *temp = head;
        cin >> n;
        for (i = 1; i <= n; i++)
        {
            cin >> l;

            if (head == NULL)
            {
                head = temp = new Node(l);
            }
            else
            {
                temp->next = new Node(l);
                temp = temp->next;
            }
        }
        Solution ob;
        ob.rearrangeEvenOdd(head);
        while (head != NULL)
        {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
    return 0;
}

// } Driver Code Ends