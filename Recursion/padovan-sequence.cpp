//* https://www.geeksforgeeks.org/problems/padovan-sequence2855/1

//^ APPROACH 1 - RECURSION

class Solution
{
public:
    int padovanSequence(int n)
    {
        // Edge cases
        if (n == 0 || n == 1 || n == 2)
            return 1;

        vector<int> padovan(n + 1, 0);
        padovan[0] = padovan[1] = padovan[2] = 1;

        for (int i = 3; i <= n; i++)
        {
            padovan[i] = (padovan[i - 2] + padovan[i - 3]) % 1000000007;
        }

        return padovan[n] % 1000000007;
    }

    // 1 1 1 2 2 3 4 5 7 9
};

//^ OPTIMAL APPROACH (TC- O(N) & SC- O(1))

#define M 1000000007

class Solution
{
public:
    int padovanSequence(int n)
    {
        int pPrevPrev = 1, pPrev = 1, pCurr = 1, pNext = 1;
        for (int i = 3; i <= n; i++)
        {
            pNext = (pPrevPrev % M + pPrev % M) % M;
            pPrevPrev = pPrev % M;
            pPrev = pCurr % M;
            pCurr = pNext % M;
        }
        return pNext % M;
    }
};
