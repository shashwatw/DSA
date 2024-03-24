// https://www.geeksforgeeks.org/batch/test-series-bundle/track/FTS-tree/problem/pruning-a-tree--170635

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// } Driver Code Ends
// User function Template for C++
/*struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
class Solution
{
public:
    struct Node *pruneUtil(struct Node *&root, int k, int &pathSum)
    {
        if (root == nullptr)
            return nullptr;

        int lsum = pathSum + (root->data);
        int rsum = lsum;

        root->left = pruneUtil(root->left, k, lsum);
        root->right = pruneUtil(root->right, k, rsum);

        pathSum = max(lsum, rsum);

        if (pathSum < k)
        {
            delete root;
            root = nullptr;
        }

        return root;
    }

    struct Node *prune(struct Node *root, int sum)
    {
        int pathSum = 0;
        return pruneUtil(root, sum, pathSum);
    }
};

//{ Driver Code Starts.

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

            // Create the left child for the current Node
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

string toString(Node *root)
{
    if (root == nullptr)
        return "N\n";

    string str;
    queue<Node *> qq;
    qq.push(root);

    while (!qq.empty())
    {
        Node *curr = qq.front();
        qq.pop();

        if (curr == nullptr)
        {
            str += "N ";
            continue;
        }
        str += (to_string(curr->data) + " ");
        qq.push(curr->left);
        qq.push(curr->right);
    }
    str += "\n";
    return str;
}

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);

        int k;
        cin >> k;

        Solution ob;

        root = ob.prune(root, k);
        string output = toString(root);
        cout << output;
        cin.ignore();
    }
    return 0;
}

// Position this line where user code will be pasted.

// } Driver Code Ends