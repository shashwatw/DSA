// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-linkedlists/problem/subtraction-in-linked-list

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node
{
public:
    int data;
    Node *next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList
{
public:
    Node *head;
    Node *tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val)
    {
        if (head == NULL)
        {
            head = new Node(val);
            tail = head;
        }
        else
        {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int length(Node *n)
    {
        int ret = 0;

        while (n)
        {
            ret++;
            n = n->next;
        }
        return ret;
    }

    Node *reverse(Node *head)
    {
        Node *prev = NULL;
        Node *current = head;
        Node *next;

        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }
    Node *subLinkedList(Node *head1, Node *head2)
    {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list

        while (head1 && head1->data == 0)
            head1 = head1->next;

        while (head2 && head2->data == 0)
            head2 = head2->next;

        if (!head1 && !head2)
        {
            Node *head = new Node(0);
            return head;
        }

        int n1 = length(head1);
        int n2 = length(head2);

        if (n2 > n1)
            swap(head1, head2);

        if (n1 == n2)
        {
            Node *t1 = head1, *t2 = head2;
            while (t1->data == t2->data)
            {
                t1 = t1->next;
                t2 = t2->next;

                if (!t1)
                    return new Node(0);
            }
            if (t2->data > t1->data)
                swap(head1, head2);
        }

        head1 = reverse(head1);
        head2 = reverse(head2);

        Node *res = NULL, *last = NULL;
        Node *t1 = head1, *t2 = head2;

        while (t1)
        {
            int small = 0;
            if (t2)
                small = t2->data;

            if (t1->data < small)
            {
                t1->next->data = t1->next->data - 1;
                t1->data = t1->data + 10;
            }

            Node *n = new Node(t1->data - small);
            if (res == NULL)
            {
                res = n;
                last = n;
            }
            else
            {
                last->next = n;
                last = last->next;
            }

            t1 = t1->next;
            if (t2)
                t2 = t2->next;
        }

        res = reverse(res);
        while (res && res->data == 0)
        {
            res = res->next;
        }

        return res;
    }
};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node *n)
{
    while (n)
    {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1, l2;
        cin >> l1;
        for (int j = 0; j < n; ++j)
        {
            int x = (l1[j] - '0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin >> l2;
        for (int j = 0; j < m; ++j)
        {
            int x = (l2[j] - '0');
            LL2.insert(x);
        }

        Solution ob;
        Node *res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends