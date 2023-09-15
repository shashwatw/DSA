#include <iostream>
#include <string>
// https://leetcode.com/problems/zigzag-conversion/description/

#include <vector>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
        {
            return s; // No change needed for a single row.
        }

        vector<string> rows(min(numRows, int(s.size())));
        int currentRow = 0;
        bool goingDown = false;

        for (char c : s)
        {
            rows[currentRow] += c;
            if (currentRow == 0 || currentRow == numRows - 1)
            {
                goingDown = !goingDown; // Change direction when reaching the top or bottom row.
            }
            currentRow += goingDown ? 1 : -1;
        }

        string result;
        for (const string &row : rows)
        {
            result += row;
        }

        return result;
    }
};