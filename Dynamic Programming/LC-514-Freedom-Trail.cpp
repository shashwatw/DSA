//^ Recursive Approach

class Solution
{
public:
    int solve(string &ring, string &key, int ptr, int index)
    {
        int n = ring.size();
        int m = key.size();

        if (index >= m)
            return 0;

        int steps = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (ring[i] == key[index])
            {
                steps = min(steps,
                            min(abs(i - ptr), n - abs(i - ptr)) + 1 + solve(ring, key, i, index + 1));
            }
        }
        return steps;
    }

    int findRotateSteps(string ring, string key)
    {
        int ptr = 0;
        int index = 0;

        return solve(ring, key, ptr, index);
    }
};

//^ DP Approach (conversion of recursive to dp)

class Solution
{
public:
    // Recursive function to find the minimum steps to spell out the key string
    int solve(string &ring, string &key, int ptr, int index,
              vector<vector<int>> &dp)
    {
        int n = ring.size(); // Number of characters in the ring
        int m = key.size();  // Number of characters in the key

        // Base case: If all characters in the key are processed, return 0 (no
        // steps needed).
        if (index >= m)
            return 0;

        // If the current state is already calculated, return the stored value.
        if (dp[index][ptr] != -1)
            return dp[index][ptr];

        int steps = INT_MAX; // Initialize the minimum steps required

        // Iterate through the ring to find the character matching the current
        // key character.
        for (int i = 0; i < n; i++)
        {
            if (ring[i] == key[index])
            {
                // Calculate the remaining steps needed to rotate the ring
                // pointer to the matching character.
                int remSteps = min(abs(i - ptr), n - abs(i - ptr));

                // Calculate the total steps needed for this matching character.
                // Add 1 for selecting the current character and call
                // recursively for the remaining key characters.
                steps = min(steps,
                            remSteps + 1 + solve(ring, key, i, index + 1, dp));
            }
        }

        // Store the result in the dp table and return.
        return dp[index][ptr] = steps;
    }

    // Main function to find the minimum steps to spell out the key string
    int findRotateSteps(string ring, string key)
    {
        int ptr = 0;         // Pointer position in the ring
        int index = 0;       // Current index of the key string
        int n = ring.size(); // Number of characters in the ring
        int m = key.size();  // Number of characters in the key

        // Create a DP vector to store the intermediate results.
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        // Call the recursive function to find the minimum steps.
        return solve(ring, key, ptr, index, dp);
    }
};
