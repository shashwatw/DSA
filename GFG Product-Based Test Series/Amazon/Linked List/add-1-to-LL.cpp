// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-linkedlists/problem/add-1-to-a-number-represented-as-linked-list

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

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

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}

// } Driver Code Ends
// User function template for C++

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
    Node *reverse(struct Node *head)
    {
        if (head == NULL)
        {
            return head;
        }
        Node *curr = head;
        Node *prev = NULL;
        Node *next = NULL;

        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
    Node *addOne(Node *head)
    {
        if (head == NULL)
        {
            return head;
        }

        head = reverse(head);
        Node *temp = head;
        Node *prev = NULL;

        int carry = 1;

        while (temp && carry)
        {
            int a = temp->data + carry;
            carry = a / 10;
            int b = a % 10;
            temp->data = b;
            prev = temp;
            temp = temp->next;
        }

        if (carry)
        {
            Node *newnode = new Node(carry);
            prev->next = newnode;
        }

        return reverse(head);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Node *head = new Node(s[0] - '0');
        Node *tail = head;
        for (int i = 1; i < s.size(); i++)
        {
            tail->next = new Node(s[i] - '0');
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends