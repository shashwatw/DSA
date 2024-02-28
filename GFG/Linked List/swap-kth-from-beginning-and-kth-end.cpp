// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-linkedlists/problem/swap-kth-node-from-beginning-and-kth-node-from-end-in-a-singly-linked-list

//{ Driver Code Starts
#include <iostream>

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

Node *swapkthnode(Node *head, int num, int K);

void addressstore(Node **arr, Node *head)
{
    Node *temp = head;
    int i = 0;
    while (temp)
    {
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(Node **before, Node **after, int num, int K)
{
    if (K > num)
        return 1;

    bool f = true;

    for (int i = 0; i < num; i++)
    {
        if ((i == K - 1) || (i == num - K))
        {
            if (!((before[K - 1] == after[num - K]) && (before[num - K] == after[K - 1])))
                f = 0;
        }
        else
        {
            if (before[i] != after[i])
                f = 0;
        }
    }

    return f;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int num, K, firstdata;
        cin >> num >> K;
        int temp;
        cin >> firstdata;
        Node *head = new Node(firstdata);
        Node *tail = head;
        for (int i = 0; i < num - 1; i++)
        {
            cin >> temp;
            tail->next = new Node(temp);
            tail = tail->next;
        }

        Node *before[num];
        addressstore(before, head);

        head = swapkthnode(head, num, K);

        Node *after[num];
        addressstore(after, head);

        if (check(before, after, num, K))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
}

// } Driver Code Ends

// User function Template for C++

/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
     Node(int x) {
        data = x;
        next = NULL;
  }
  }
*/

// Function to swap Kth node from beginning and end in a linked list.
Node *swapkthnode(Node *head, int num, int K)
{
    if (head == NULL || head->next == NULL)
        return head;
    if (K > num)
        return head;
    if (K > num / 2)
        K = num % K + 1;

    int check = K;
    Node *temp1 = head, *temp2 = head;
    Node *prev2 = NULL, *prev1 = NULL;

    while (--K)
    {
        prev1 = temp1;
        temp1 = temp1->next;
    }

    K = num - check;

    while (K--)
    {
        prev2 = temp2;
        temp2 = temp2->next;
    }

    if (check == 1)
    {
        prev2->next = temp1;
        temp2->next = temp1->next;
        temp1->next = prev1;
        return temp2;
    }

    Node *nextt = temp1->next;
    prev1->next = temp2;
    prev2->next = temp1;
    temp1->next = temp2->next;

    if (temp2 == nextt)
    {
        temp2->next = temp1;
    }
    else
    {
        temp2->next = nextt;
    }

    return head;
}