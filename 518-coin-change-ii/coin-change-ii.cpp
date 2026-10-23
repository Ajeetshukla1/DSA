class Solution {
public:
    int fn(int i,int target,vector<int>& coins,vector<vector<int>>&dp){
        if(target==0) return 1;
        if(i==0 && target==coins[0]) return 1;
        if(i<0) return 0;
        if(dp[i][target]!=-1) return dp[i][target];
        int notChoose=fn(i-1,target,coins,dp);
        int choose=0;
        if(target>=coins[i]) choose=fn(i,target-coins[i],coins,dp);
        return dp[i][target]=choose+notChoose;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return fn(n-1,amount,coins,dp);

    }
};