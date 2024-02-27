// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-linkedlists/problem/polynomial-addition

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int coeff;
    int pow;
    struct Node *next;

    Node(int c, int p)
    {
        coeff = c;
        pow = p;
        next = NULL;
    }
};

void append(struct Node **head_ref, struct Node **tail_ref,
            int new_data, int new_data1)
{
    struct Node *new_node = new Node(new_data, new_data1);

    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

void printList(struct Node *head)
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d %d ", temp->coeff, temp->pow);
        temp = temp->next;
    }
}

Node *addPolynomial(Node *p1, Node *p2);

void create_node(int x, int y, struct Node **temp)
{
    struct Node *r, *z;
    z = *temp;
    if (z == NULL)
    {
        r = new Node(x, y);
        *temp = r;
        r->next = NULL;
    }
    else
    {
        r->next = new Node(x, y);
        r = r->next;
        r->next = NULL;
    }
}

/* Driver program to test above function*/

// } Driver Code Ends
/* Structure of Node used
struct Node
{
    int coeff;
    int pow;
    struct Node* next;

    Node(int c, int p){
        coeff = c;
        pow = p;
        next = NULL;
    }

};
*/

class Solution
{
public:
    /* The below method print the required sum of polynomial
    p1 and p2 as specified in output  */
    Node *addPolynomial(Node *p1, Node *p2)
    {
        Node *temp1 = p1; // Rename temp to temp1
        Node *temp2 = p2; // Rename temp to temp2

        Node *newNode = new Node(-1, -1);
        Node *ans = newNode; // Initialize ans with newNode

        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1->pow == temp2->pow)
            {
                int cf = temp1->coeff + temp2->coeff;
                int pw = temp1->pow;

                ans->next = new Node(-1, -1); // Create a new node for the next term
                ans = ans->next;              // Move ans to the next node

                ans->coeff = cf;
                ans->pow = pw;

                temp1 = temp1->next; // Move to the next term in p1
                temp2 = temp2->next; // Move to the next term in p2
            }
            else if (temp1->pow > temp2->pow)
            {
                ans->next = new Node(-1, -1);
                ans = ans->next;

                ans->coeff = temp1->coeff;
                ans->pow = temp1->pow;

                temp1 = temp1->next;
            }
            else
            {
                ans->next = new Node(-1, -1);
                ans = ans->next;

                ans->coeff = temp2->coeff;
                ans->pow = temp2->pow;

                temp2 = temp2->next;
            }
        }

        if (temp1 != NULL)
        {
            ans->next = temp1;
        }

        if (temp2 != NULL)
        {
            ans->next = temp2;
        }

        return newNode->next; // Return the next node, as the first node was a dummy node
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        struct Node *poly1 = NULL, *poly2 = NULL, *poly = NULL;
        struct Node *tail1 = NULL, *tail2 = NULL;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            append(&poly1, &tail1, x, y);
        }

        int m;
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            append(&poly2, &tail2, x, y);
        }
        Solution obj;
        Node *sum = obj.addPolynomial(poly1, poly2);
        for (Node *ptr = sum; ptr; ptr = ptr->next)
        {
            // printing polynomial
            cout << ptr->coeff << "x^" << ptr->pow;
            if (ptr->next)
                cout << " + ";
        }
        cout << endl;
    }
}

// } Driver Code Ends