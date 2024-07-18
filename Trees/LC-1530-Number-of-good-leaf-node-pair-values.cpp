//^ https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description/

class Solution
{
private:
    vector<int> helper(TreeNode *node, int maxDistance, int &countPairs)
    {
        if (node == nullptr)
            return {0}; // Base case: if the node is null, return a vector with one element 0

        if (node->left == nullptr && node->right == nullptr)
            return {1}; // If the node is a leaf, return a vector with one element 1

        vector<int> leftDistances = helper(node->left, maxDistance, countPairs);   // Recursively find distances for the left subtree
        vector<int> rightDistances = helper(node->right, maxDistance, countPairs); // Recursively find distances for the right subtree

        // Check all pairs of distances from left and right subtrees
        for (int &leftDistance : leftDistances)
        {
            for (int &rightDistance : rightDistances)
            {
                if (leftDistance > 0 && rightDistance > 0 && leftDistance + rightDistance <= maxDistance)
                {
                    countPairs++; // Increment countPairs if the sum of distances is within maxDistance
                }
            }
        }

        vector<int> updatedDistances; // Vector to store updated distances

        // Increment distances for the current node and filter them based on maxDistance
        for (int leftDistance : leftDistances)
        {
            if (leftDistance > 0 && leftDistance <= maxDistance)
            {
                updatedDistances.push_back(leftDistance + 1);
            }
        }

        for (int rightDistance : rightDistances)
        {
            if (rightDistance > 0 && rightDistance <= maxDistance)
            {
                updatedDistances.push_back(rightDistance + 1);
            }
        }

        return updatedDistances; // Return the updated distances
    }

public:
    int countPairs(TreeNode *root, int distance)
    {
        int countPairs = 0;
        helper(root, distance, countPairs); // Start the recursive process
        return countPairs;                  // Return the total count of valid pairs
    }
};
