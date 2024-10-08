//* https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/

class Solution {
public:
    int r , c ;
    int dx[4] = {-1,0,1,0} ;
    int dy[4] = {0,1,0,-1};
    void dfs(int i , int j , vector<vector<int>> &grid , vector<vector<int>> &visited ){
        visited[i][j] = 1;
        
        for(int itr = 0 ; itr < 4 ; ++itr ){
            int ii = i + dx[itr] , jj = j + dy[itr] ;
            if(ii >= 0 and jj >= 0 and ii < r and jj < c and grid[ii][jj] and !visited[ii][jj]) dfs(ii,jj,grid,visited);
        }
    }
    
    int find_islands(vector<vector<int>> &grid){
        vector<vector<int>> visited(r,vector<int>(c)) ;
        int ans = 0 ;
        for(int i = 0 ; i < r ; ++i ){
            for(int j = 0 ; j < c ; ++j ){
                if(!grid[i][j]) continue ;
                if(!visited[i][j]) ++ans , dfs(i,j,grid,visited);
            }
        }
        return ans ;
    }
    
    int minDays(vector<vector<int>>& grid) {
        r = grid.size() , c = grid[0].size() ;
        int islands = find_islands(grid) ;
        if(!islands || islands > 1) return 0 ; 
        
        for(int i = 0 ; i < r ; ++i ){
            for(int j = 0 ; j < c ; ++j ){
                if(!grid[i][j]) continue ;
                
                grid[i][j] = 0 ;
                int groups = find_islands(grid) ;
                if(groups > 1 || !groups) return 1 ;
                grid[i][j] = 1 ;
            }
        }
        
        return 2 ;
        
    }
};