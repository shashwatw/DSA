//*https://www.geeksforgeeks.org/problems/make-binary-tree/1

/*
The structure of Link list Node is as follows
struct Node
{
    int data;
    struct node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
The structure of TreeNode is as follows
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};
*/

// Function to make binary tree from linked list.
void convert(Node *head, TreeNode *&root)
{
    // Your code here
    if (head == NULL)
        return;

    root = new TreeNode(head->data);
    head = head->next;

    queue<TreeNode *> q;
    q.push(root);

    while (head && q.size() != 0)
    {
        TreeNode *node{q.front()};
        q.pop();
        node->left = new TreeNode(head->data);
        q.push(node->left);

        if (head->next != NULL)
        {
            head = head->next;
            node->right = new TreeNode(head->data);
            q.push(node->right);
        }
        head = head->next;
    }
}