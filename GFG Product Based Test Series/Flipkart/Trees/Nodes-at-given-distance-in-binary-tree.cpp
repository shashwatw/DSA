// https://www.geeksforgeeks.org/batch/test-series-bundle/track/FTS-tree/problem/nodes-at-given-distance-in-binary-tree

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:
public:
    void printKDistanceNode(Node *root, int k, vector<int> &res)
    {
        if (root == nullptr)
            return;

        if (k == 0)
        {
            res.push_back(root->data);
            return;
        }

        printKDistanceNode(root->left, k - 1, res);
        printKDistanceNode(root->right, k - 1, res);
    }

    int findTargetDistance(Node *root, int target, int k, vector<int> &res)
    {
        if (root == nullptr)
            return -1; // Target not found

        if (root->data == target)
        {
            printKDistanceNode(root, k, res);
            return 0; // Found target, so at distance 0
        }

        int leftDistance = findTargetDistance(root->left, target, k, res);

        if (leftDistance != -1)
        {
            if (leftDistance + 1 == k)
            {
                res.push_back(root->data);
            }
            else
            {
                printKDistanceNode(root->right, k - leftDistance - 2, res);
            }
            return leftDistance + 1;
        }

        int rightDistance = findTargetDistance(root->right, target, k, res);

        if (rightDistance != -1)
        {
            if (rightDistance + 1 == k)
            {
                res.push_back(root->data);
            }
            else
            {
                printKDistanceNode(root->left, k - rightDistance - 2, res);
            }
            return rightDistance + 1;
        }

        return -1; // Target not found in the current subtree
    }

    vector<int> KDistanceNodes(Node *root, int target, int k)
    {
        // return the sorted vector of all nodes at k dist
        vector<int> res;
        findTargetDistance(root, target, k, res);

        sort(res.begin(), res.end());
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    getchar();

    Solution x = Solution();

    while (t--)
    {
        string s;
        getline(cin, s);
        Node *head = buildTree(s);

        int target, k;
        cin >> target >> k;
        getchar();

        vector<int> res = x.KDistanceNodes(head, target, k);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends