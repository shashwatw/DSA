//^ https://www.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1

/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution
{
public:
    // Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root)
    {
        vector<int> res;
        queue<Node *> q;

        q.push(root);
        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();

            if (curr != nullptr)
            {

                res.push_back(curr->data);
                q.push(curr->left);
                q.push(curr->right);
            }
            else
            {
                res.push_back(-1);
            }
        }
        return res;
    }

    // Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &A)
    {
        // Your code here
        if (A.empty())
            return nullptr;

        int ind = 0;
        queue<Node *> q;

        Node *root = new Node(A[ind++]);
        q.push(root);

        while (!q.empty() && ind < A.size())
        {
            Node *curr = q.front();
            q.pop();

            if (A[ind] != -1)
            {
                curr->left = new Node(A[ind]);
                q.push(curr->left);
            }
            ind++;

            if (ind < A.size() && A[ind] != -1)
            {
                curr->right = new Node(A[ind]);
                q.push(curr->right);
            }
            ind++;
        }
        return root;
    }
};