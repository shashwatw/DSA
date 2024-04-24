//& https://www.geeksforgeeks.org/problems/paths-to-reach-origin3850/1

//^ Approach 1 -> Brute Approach - Recursive (TLE Here)
//* Here recursion will start from arr[x][y] which is bottom most and check for each uske upar and right... Only
//* only two directions mein ja skte h for origin i.e up and right
//* yaha arr[x][y] ke upar and right dono ki ways add krte krte jaenge....

//~ CODE

// User function Template for C++
class Solution
{
public:
    int ways(int x, int y)
    {
        // code here.
        if (x == 0 || y == 0)
            return 1;

        int res = 0;

        res += ways(x - 1, y);
        res += ways(x, y - 1);

        return res;
    }
};

//^ Approach 2 --> Memoization Approach....
//* yaha create a 2D vector of size [x+1][y+1] and initialise with -1;
//* then store krte rho 2D vector mein and calls krte rho recursive taaki jab -1 na ho col then
//* fetch krlo already prefilled values from the 2D array.

//~ CODE:
// User function Template for C++
// User function Template for C++
class Solution
{
public:
    int countUtil(int x, int y, vector<vector<long long>> &memo)
    {
        if (x == 0 || y == 0)
            return 1;

        if (memo[x][y] != -1)
            return memo[x][y];

        memo[x][y] = countUtil(x - 1, y, memo) + countUtil(x, y - 1, memo);
        memo[x][y] = memo[x][y] % 1000000007;

        return memo[x][y];
    }

    int ways(int x, int y)
    {
        // code here.
        vector<vector<long long>> memo(x + 1, vector<long long>(y + 1, -1));

        return countUtil(x, y, memo);
    }
};

//^ Approach 3 - Tabulation (Iterative way)
//* In this way humne ek 2d array banaaya and first row and first col ko 1 se initialise kiya
//* becoz 1 hi path hoga.
//* Simply start by arr[1][1] and go till arr[x][y] basically it is TOP DOWN Approach

//~CODE:
// User function Template for C++
class Solution
{
public:
    int countUtil(int x, int y, vector<vector<long long>> &memo)
    {
        if (x == 0 || y == 0)
            return 1;

        if (memo[x][y] != -1)
            return memo[x][y];

        memo[x][y] = countUtil(x - 1, y, memo) + countUtil(x, y - 1, memo);
        memo[x][y] = memo[x][y] % 1000000007;

        return memo[x][y];
    }

    int ways(int x, int y)
    {
        // code here.
        vector<vector<long long>> memo(x + 1, vector<long long>(y + 1, -1));

        return countUtil(x, y, memo);
    }
};