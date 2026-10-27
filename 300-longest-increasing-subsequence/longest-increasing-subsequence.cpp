class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int n=nums.size();
        int ans=0;
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;

        
    }
};