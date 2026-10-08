class Solution {
public:
    int fn(int row,int col,vector<vector<int>>&dp,vector<vector<int>>&matrix){
        
        
        if(row==0){
            return matrix[row][col];
        }
        if(dp[row][col]!=INT_MAX) return dp[row][col];
        int left = INT_MAX;
        int middle = INT_MAX;
        int right = INT_MAX;
        if(col-1>=0) left=matrix[row][col]+fn(row-1,col-1,dp,matrix);
        
        middle=matrix[row][col]+fn(row-1,col,dp,matrix);
        if(col+1<matrix.size()) right=matrix[row][col]+fn(row-1,col+1,dp,matrix);
        return dp[row][col]=min({left,middle,right});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        int ans=INT_MAX;
        for(int i=0;i<m;i++){
            ans=min(ans,fn(n-1,i,dp,matrix));
        }
        return ans;
         

    }
};