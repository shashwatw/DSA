// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-bst/problem/merge-two-bst-s

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution
{
public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.

    void merge(vector<int> t1, vector<int> t2, vector<int> &ans)
    {
        int i = 0;
        int j = 0;

        while (i < t1.size() && j < t2.size())
        {
            if (t1[i] < t2[j])
            {
                ans.push_back(t1[i++]);
            }
            else
            {
                ans.push_back(t2[j++]);
            }
        }

        while (i < t1.size())
        {
            ans.push_back(t1[i++]);
        }

        while (j < t2.size())
        {
            ans.push_back(t2[j++]);
        }
    }

    void inorder(Node *root, vector<int> &t)
    {
        if (root == NULL)
            return;

        inorder(root->left, t);

        t.push_back(root->data);

        inorder(root->right, t);
    }

    vector<int> merge(Node *root1, Node *root2)
    {
        // Your code here
        vector<int> t1;
        vector<int> t2;

        inorder(root1, t1);
        inorder(root2, t2);

        vector<int> ans;

        merge(t1, t2, ans);

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root1 = buildTree(s);

        getline(cin, s);
        Node *root2 = buildTree(s);

        // getline(cin, s);
        Solution obj;
        vector<int> vec = obj.merge(root1, root2);
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;
        /// cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends