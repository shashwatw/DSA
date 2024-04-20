// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-linkedlists/problem/intersection-of-two-linked-list

//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node *inputList(int size)
{
    Node *head, *tail;
    int val;

    cin >> val;
    head = tail = new Node(val);

    while (--size)
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
}

// } Driver Code Ends
/* structure of list node:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution
{
public:
    Node *findIntersection(Node *head1, Node *head2)
    {
        Node *ans = new Node(-1);
        Node *temp = ans;
        unordered_set<int> s;

        while (head2 != NULL)
        {
            s.insert(head2->data);
            head2 = head2->next;
        }

        while (head1 != NULL)
        {
            if (s.find(head1->data) != s.end())
            {
                temp->next = new Node(head1->data);
                temp = temp->next;
            }
            head1 = head1->next;
        }
        return ans->next;
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
        Node *head1 = inputList(n);

        cin >> m;
        Node *head2 = inputList(m);
        Solution obj;
        Node *result = obj.findIntersection(head1, head2);

        printList(result);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends