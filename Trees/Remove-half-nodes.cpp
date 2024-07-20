//^ https://www.geeksforgeeks.org/problems/remove-half-nodes/1

/*Complete the function below
Node is as follows:
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

// Return the root of the modified tree after removing all the half nodes.
class Solution
{
private:
    Node *postorder(Node *node)
    {
        if (node == NULL)
            return NULL;

        node->left = postorder(node->left);

        node->right = postorder(node->right);

        if (node->right != NULL && node->left == NULL)
        {
            Node *newNode = node->right;
            delete (node);
            return newNode;
        }

        if (node->right == NULL && node->left != NULL)
        {
            Node *newNode = node->left;
            delete (node);
            return newNode;
        }

        return node;
    }

public:
    Node *RemoveHalfNodes(Node *root)
    {
        // code here
        return postorder(root);
    }
};