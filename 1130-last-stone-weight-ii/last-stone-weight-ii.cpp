class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        int totalSum=0;
        for(int i=0;i<n;i++) totalSum+=stones[i];
        int target=totalSum;
        vector<vector<bool>>dp(n,vector<bool>(target+1,0));
        for(int i=0;i<n;i++) dp[i][0]=true;
        if(stones[0]<=target) dp[0][stones[0]]=true;
        for(int ind=1;ind<n;ind++){
            for(int k=1;k<=target;k++){
                bool notChoose=dp[ind-1][k];
                bool take=false;
                if(k>=stones[ind]) take=dp[ind-1][k-stones[ind]];
                dp[ind][k]=take || notChoose;
            }
        }
        int mini=INT_MAX;
        //the last row will give the answer if whether that target is possible at last index or not
        for(int s1=0;s1<=totalSum/2;s1++){
            if(dp[n-1][s1]==true){
                int s2=totalSum-s1;
                mini=min(mini,abs(s1-s2));
            }
        }
        return mini;
    }
};