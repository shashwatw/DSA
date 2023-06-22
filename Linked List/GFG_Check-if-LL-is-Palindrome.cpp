// First Approach -----> time - O(n) and space- O(n)
// https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

/*
#include <vector>
class Solution{
    private:
    bool checkPalin(vector<int> arr)
    {
        int n = arr.size();
        int s = 0;
        int e = n-1;

        while(s<=e)
        {
            if(arr[s] != arr[e])
            {
                return 0;
            }
            s++;
            e--;
        }
        return 1;
    }
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
       vector<int> arr;

       Node* temp = head;
       while(temp != NULL)
       {
           arr.push_back(temp->data);
           temp = temp->next;
       }
       return checkPalin(arr);
    }
};

*/

// 2nd Approach -----> time - O(n) and space- O(1)
// Linked list le middle element tk pohchke mid+1 se end tk revrse krdo list....ab compare 2 parts and if they are identical then is palindrome.

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
private:
    Node *getMid(Node *head)
    {
        Node *slow = head;
        Node *fast = head->next;

        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
    Node *reverse(Node *head)
    {

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

public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        if (head->next == NULL)
        {
            return true;
        }

        // step 1 -> find Middle
        Node *middle = getMid(head);
        // cout << "Middle " << middle->data << endl;

        // step2 -> reverse List after Middle
        Node *temp = middle->next;
        middle->next = reverse(temp);

        // step3 - Compare both halves
        Node *head1 = head;
        Node *head2 = middle->next;

        while (head2 != NULL)
        {
            if (head2->data != head1->data)
            {
                return 0;
            }
            head1 = head1->next;
            head2 = head2->next;
        }

        // step4 - repeat step 2
        temp = middle->next;
        middle->next = reverse(temp);

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