// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-bst/problem/find-the-closest-element-in-bst

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

// } Driver Code Ends
/*
Tree Node
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
    void floorK(Node *root, int K, int &less)
    {
        if (root == NULL)
            return;

        if (root->data > K)
        {
            less = root->data;
            floorK(root->left, K, less);
        }
        else if (root->data < K)
        {
            floorK(root->right, K, less);
        }
        else if (root->data == K)
        {
            less = K;
            return;
        }
    }

    void ceilK(Node *root, int K, int &large)
    {
        if (root == NULL)
            return;

        if (root->data > K)
        {
            ceilK(root->left, K, large);
        }
        else if (root->data < K)
        {
            large = root->data;
            ceilK(root->right, K, large);
        }
        else if (root->data == K)
        {
            large = K;
            return;
        }
    }

    int minDiff(Node *root, int K)
    {
        if (root == NULL)
            return K;

        int less = INT_MIN;  // Initialize less to minimum possible value
        int large = INT_MAX; // Initialize large to maximum possible value

        floorK(root, K, less);
        ceilK(root, K, large);

        int diff1 = abs(less - K);
        int diff2 = abs(large - K);

        return min(diff1, diff2); // Return the minimum of diff1 and diff2
    }
};

//{ Driver Code Starts.

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
        int k = stoi(s);
        // getline(cin, s);

        Solution ob;
        cout << ob.minDiff(root1, k);
        cout << endl;
        // cout<<"~"<<endl;
    }
    return 0;
}

// } Driver Code Ends