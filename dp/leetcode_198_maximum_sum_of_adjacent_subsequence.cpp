// house robber 1 
// maximum sum of adjacent subsequence
// recursion +memoization
class Solution {
public:
     int fn(int n,vector<int> &dp,vector<int> &arr){
        
        if(n<0) return 0;
        if(n==0) return arr[n];
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

// tabulation
class Solution {
public:
     
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int include=nums[i];
            if(i>1) include+=dp[i-2];
            int exclude=dp[i-1];
            dp[i]=max(include,exclude);
        }
        return dp[n-1];
        
    }
};

// space optimization
class Solution {
public:
     
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev2=0;
        int prev1=nums[0];
        int curr=0;
        for(int i=1;i<n;i++){
            int include=nums[i]+prev2;
            int exclude=0+prev1;
            curr=max(include,exclude);
            prev2=prev1;
            prev1=curr;
            
        }
        return prev1;
        
        
    }
};
