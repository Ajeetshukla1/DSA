class Solution {
public:
    int fn(int i,int target,vector<int>& nums,vector<vector<int>>&dp){
        if(i==0){
            if(target==0 && nums[0]==0) return 2;
            if(target==0 || nums[0]==target) return 1;
            return 0;
        }
        if(dp[i][target]!=-1) return dp[i][target];
        int notchoose=fn(i-1,target,nums,dp);
        int choose=0;
        if(nums[i]<=target) choose=fn(i-1,target-nums[i],nums,dp);
        return dp[i][target]=choose+notchoose;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int total=0;
        for(int i=0;i<n;i++){
            total+=nums[i];
        }
        //total should be greater than target and 
        if(total-target<0 || (total-target)%2!=0){
            return 0;
        }
        int s1=(total-target)/2;
        vector<vector<int>>dp(n,vector<int>(s1+1,-1));
        return fn(n-1,s1,nums,dp);
        
    }
};