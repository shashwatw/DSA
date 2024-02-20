// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-linkedlists/problem/check-if-linked-list-is-pallindrome

//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
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
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution
{
public:
    // Function to check whether the list is palindrome.
    Node *getMiddle(Node *head)
    {
        Node *slow = head;
        Node *fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    Node *reverse(Node *head)
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *forward = NULL;
        while (curr != NULL)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    bool isPalindrome(Node *head)
    {
        if (head->next == NULL)
        {
            return true;
        }
        Node *middle = getMiddle(head);
        Node *temp = middle->next;
        middle->next = reverse(temp);
        temp = middle->next;
        while (temp != NULL)
        {
            if (head->data != temp->data)
            {
                return false;
            }
            head = head->next;
            temp = temp->next;
        }
        return true;
    }
};

//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
    int T, i, n, l, firstdata;
    cin >> T;
    while (T--)
    {

        struct Node *head = NULL, *tail = NULL;
        cin >> n;
        // taking first data of LL
        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for (i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        Solution obj;
        cout << obj.isPalindrome(head) << endl;
    }
    return 0;
}

// } Driver Code Ends