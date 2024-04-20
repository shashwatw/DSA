// https://www.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1
//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* Function to print nodes in a given linked list */
void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution
{
public:
    struct CompareNode
    {
        bool operator()(Node *a, Node *b)
        {
            return a->data > b->data;
        }
    };

    Node *mergeKLists(Node *arr[], int K)
    {
        // Priority queue to maintain the smallest element among the heads of all lists
        priority_queue<Node *, std::vector<Node *>, CompareNode> minHeap;

        // Push the first element from each list to the min-heap
        for (int i = 0; i < K; ++i)
        {
            if (arr[i] != nullptr)
            {
                minHeap.push(arr[i]);
            }
        }

        Node *dummy = new Node(0);
        Node *tail = dummy;

        while (!minHeap.empty())
        {
            // Pop the smallest element from the min-heap
            Node *curr = minHeap.top();
            minHeap.pop();

            // Add the popped element to the result list
            tail->next = curr;
            tail = tail->next;

            // Move to the next element in the list of the popped element
            if (curr->next != nullptr)
            {
                minHeap.push(curr->next);
            }
        }

        return dummy->next;
    }
};

//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        struct Node *arr[N];
        for (int j = 0; j < N; j++)
        {
            int n;
            cin >> n;

            int x;
            cin >> x;
            arr[j] = new Node(x);
            Node *curr = arr[j];
            n--;

            for (int i = 0; i < n; i++)
            {
                cin >> x;
                Node *temp = new Node(x);
                curr->next = temp;
                curr = temp;
            }
        }
        Solution obj;
        Node *res = obj.mergeKLists(arr, N);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends