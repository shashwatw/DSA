// https://www.geeksforgeeks.org/batch/test-series-bundle/track/FTS-tree/problem/postorder-traversal-iterative

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
// User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution
{
public:
    vector<int> postOrder(Node *root)
    {
        vector<int> res;
        stack<Node *> s;
        Node *curr = root;

        while (curr != NULL || !s.empty())
        {
            while (curr != NULL)
            {
                s.push(curr);
                res.push_back(curr->data);
                curr = curr->right;
            }

            if (!s.empty())
            {
                curr = s.top();
                s.pop();
                curr = curr->left;
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main()
{

    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s, ch;
        getline(cin, s);

        Node *root = buildTree(s);

        vector<int> ans;
        Solution ob;
        ans = ob.postOrder(root);

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

//****************************************************************************************************************
// M-2

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
// User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution
{
public:
    // s   1 2

    // res 4

    vector<int> postOrder(Node *root)
    {
        // code here
        vector<int> res;
        stack<Node *> s;
        Node *curr = root;

        while (curr != NULL || !s.empty())
        {
            while (curr != NULL)
            {
                s.push(curr);
                curr = curr->left;
                s.top()->left = NULL;
            }

            curr = s.top();
            if (curr->right != NULL)
            {
                s.push(curr->right);
                curr->right = NULL;
                curr = s.top();
                s.pop();
                continue;
            }

            res.push_back(curr->data);
            s.pop();
            curr = NULL;

            // res.push_back(curr->data);
            // s.pop();
            // if(curr->right != NULL) s.push(curr->right);
            // curr = s.top();

            // if(!s.empty())
            // {
            //     curr = s.top();
            //     curr = curr->right;
            //     res.push_back(curr->data);
            // }
        }
        return res;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main()
{

    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s, ch;
        getline(cin, s);

        Node *root = buildTree(s);

        vector<int> ans;
        Solution ob;
        ans = ob.postOrder(root);

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends