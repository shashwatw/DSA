//* https://www.geeksforgeeks.org/problems/duplicate-subtrees/1

class Solution
{
private:
    unordered_map<string, pair<Node *, int>> subtreeMap;
    vector<Node *> res;

    string preorder(Node *root)
    {
        if (!root)
            return "#";

        // Serialize the subtree
        string serial = to_string(root->data) + "," + preorder(root->left) + "," + preorder(root->right);

        // Count the frequency of the serialized subtree
        auto &entry = subtreeMap[serial];
        entry.first = root;
        entry.second++;

        // If this is the second time this subtree has been seen, add the root to the result
        if (entry.second == 2)
        {
            res.push_back(root);
        }

        return serial;
    }

public:
    vector<Node *> printAllDups(Node *root)
    {
        // Perform preorder traversal to populate the map and result
        preorder(root);

        return res;
    }
};