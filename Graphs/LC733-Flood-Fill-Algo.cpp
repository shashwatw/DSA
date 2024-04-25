//^ https://leetcode.com/problems/flood-fill/

//& INTUITION
//* We need to store a ini color to check for cell's inicolor.
//* Now we made a copy of image for mutation
//* called DFS from starting cell that is ans[sr][sc]
//* Initally in DFS call we changed the colour of start cell
//* run a for loop which is a trick for checking all 4 directions
//* Now check some validities, and necessary condns such as if it's already coloured or it has same inicolor
//* if it satisfies all then call dfs for new nrow and ncol
//* Dfs traverses till each cell accepting all condn gets recoloured

//~ CODE (DFS)

class Solution
{
private:
    void dfs(int row, int col, vector<vector<int>> &image,
             vector<vector<int>> &ans, int delRow[], int delCol[], int iniColor,
             int newColor)
    {
        ans[row][col] = newColor;

        int n = image.size();
        int m = image[0].size();

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor)
            {
                dfs(nrow, ncol, image, ans, delRow, delCol, iniColor, newColor);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                  int color)
    {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        dfs(sr, sc, image, ans, delRow, delCol, iniColor, color);
        return ans;
    }
};