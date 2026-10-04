class Solution {
public:
    int fn(vector<int>&heights,vector<int>&dp,int index,int k){
        if(index==0 ) return 0;
        if(dp[index]!=-1) return dp[index];
        int mini=INT_MAX;
        for(int i=1;i<=k;i++){
            if(index-i<0) break;
            int cost=fn(heights,dp,index-i,k)+abs(heights[index]-heights[index-i]);
            mini=min(mini,cost);
        }
        
        return dp[index]=mini;

    }
    int frogJump(vector<int>& heights, int k) {
        int n=heights.size();
        vector<int>dp(n,-1);
        return fn(heights,dp,n-1,k);



    }
};
