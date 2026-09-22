class Solution {
public:
     int fn(int n,vector<int> &dp,vector<int> &arr){
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int include=fn(n-2,dp,arr)+arr[n];
        int exclude=fn(n-1,dp,arr)+0;
        dp[n]=max(include,exclude);
        return dp[n];


    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return fn(n-1,dp,nums);
        
    }
};