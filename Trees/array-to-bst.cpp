//^ https://www.geeksforgeeks.org/problems/array-to-bst4443/1

/*
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val)
        : data(val)
        , left(nullptr)
        , right(nullptr) {}
};
*/

class Solution
{
private:
    Node *solve(int i, int j, vector<int> &nums)
    {
        if (i > j)
            return NULL;

        if (i == j)
            return new Node(nums[i]);

        int mid = i + (j - i) / 2;

        Node *newNode = new Node(nums[mid]);
        newNode->left = solve(i, mid - 1, nums);
        newNode->right = solve(mid + 1, j, nums);

        return newNode;
    }

public:
    Node *sortedArrayToBST(vector<int> &nums)
    {
        // Code here
        return solve(0, nums.size() - 1, nums);
    }
};