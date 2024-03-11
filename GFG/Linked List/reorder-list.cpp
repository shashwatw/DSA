// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-linkedlists/problem/reorder-list

//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
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

// } Driver Code Ends
/* Following is the Linked list node structure */

/*
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

class Solution
{
public:
    Node *reverse(Node *head)
    {
        Node *p = NULL, *q = NULL, *r = head;
        while (r != NULL)
        {
            p = q;
            q = r;
            r = r->next;

            q->next = p;
        }
        return q;
    }

    void reorderList(Node *head)
    {
        // Your code here
        if (head == NULL || head->next == NULL)
        {
            return;
        }

        Node *f = head->next, *s = head;
        while (f != NULL)
        {
            f = f->next;
            if (f != NULL)
            {
                f = f->next;
                s = s->next;
            }
        }

        Node *second = reverse(s->next);
        Node *first = head;
        s->next = NULL;

        // insert even node then odd node one by one
        Node *ansHead = new Node(-1);
        Node *ansTail = ansHead;

        while (first && second)
        {
            // first add even
            ansTail->next = first;
            ansTail = first;
            first = first->next;

            // add odd
            ansTail->next = second;
            ansTail = second;
            second = second->next;
        }

        // in odd case LL -> first has 1 node left
        if (first != NULL)
        {
            ansTail->next = first;
            ansTail = first;
        }

        head = ansHead->next;
    }
};

//{ Driver Code Starts.

/* Function to create a new Node with given data */
struct Node *newNode(int data)
{
    struct Node *new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node *head)
{
    struct Node *temp;
    while (head != NULL)
    {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void)
{
    int t, n, m, i, x;

    cin >> t;
    while (t--)
    {
        struct Node *temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++)
        {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }

        Solution ob;

        ob.reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}

// } Driver Code Ends