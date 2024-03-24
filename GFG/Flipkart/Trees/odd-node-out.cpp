// https://www.geeksforgeeks.org/batch/test-series-bundle/track/FTS-tree/problem/odd-node-out

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

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
    Node *root = new Node(stoi(ip[0]));

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
            currNode->left = new Node(stoi(currVal));

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
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void preorder(Node *root, map<int, int> &mp)
    {
        if (root == nullptr)
            return;

        if (mp.find(root->data) != mp.end())
        {
            mp[root->data]++;
        }
        else
        {
            mp[root->data] = 1;
        }
        preorder(root->left, mp);
        preorder(root->right, mp);
    }

    void preHelper(Node *root, map<int, int> &mp)
    {
        if (root == NULL)
            return;

        if (mp.find(root->data) != mp.end())
        {
            mp[root->data]--;
        }
        else
        {
            mp[root->data] = -1;
        }

        preHelper(root->left, mp);
        preHelper(root->right, mp);
    }

    int oddNodeOut(Node *root1, Node *root2)
    {
        // Write your code here
        map<int, int> mp;

        preorder(root1, mp);

        preHelper(root2, mp);

        for (auto it : mp)
        {
            if (it.second == -1)
                return it.first;
        }

        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    getchar();
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root1 = buildTree(s);

        getline(cin, s);
        Node *root2 = buildTree(s);
        Solution ob;
        int res = ob.oddNodeOut(root1, root2);

        cout << res;
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends