class Solution {
public:
    int fn(int m,int n,vector<vector<int>>&dp,vector<vector<int>>& grid){
        if(m<0 || n<0) return 0;
        if(grid[m][n]==1) return 0;
        if(m==0 && n==0) return 1;
        if(dp[m][n]!=-1) return dp[m][n];
        int up=fn(m-1,n,dp,grid);
        int down=fn(m,n-1,dp,grid);
        return dp[m][n]=up +down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));

        return fn(m-1,n-1,dp,obstacleGrid);
        
    }
};