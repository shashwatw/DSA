// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-linkedlists/problem/given-a-linked-list-reverse-alternate-nodes-and-append-at-the-end

//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
/* A linked list node */

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

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void insert()
{
    int n, value;
    cin >> n;
    struct Node *temp;
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        if (i == 0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}

// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element
  Node is defined as
  struct Node
  {
      int data;
      struct Node *next;

      Node(int x){
        data = x;
        next = NULL;
      }

   };

*/
class Solution
{
public:
    struct Node *reverseList(struct Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        Node *curr = head;
        Node *nextNode = NULL;
        Node *prev = NULL;

        while (curr != NULL)
        {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        head = prev;

        return head;
    }

    void rearrange(struct Node *head)
    {
        if (head == NULL || head->next == NULL || head->next->next == NULL)
        {
            return; // No need to rearrange if the list has 0 or 1 elements
        }

        Node *altHead = head;
        Node *alt = altHead;
        Node *alt2Head = head->next;
        Node *alt2 = alt2Head;
        Node *temp = head->next->next; // Start from the third node
        int flag = 1;

        while (temp != NULL)
        {
            if (flag % 2 == 1)
            {
                alt->next = temp;
                alt = alt->next;
            }
            else
            {
                alt2->next = temp;
                alt2 = alt2->next;
            }

            temp = temp->next;
            flag++;
        }

        alt2Head = reverseList(alt2Head);

        alt->next = alt2Head;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends