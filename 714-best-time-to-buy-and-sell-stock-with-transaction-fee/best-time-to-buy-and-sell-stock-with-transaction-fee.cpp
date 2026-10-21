class Solution {
public:
    int fn(int ind,int buy,int fee,vector<int>& prices,vector<vector<int>> &dp){
        if(ind==prices.size()) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit=INT_MIN;
        if(buy){
            profit=max(-prices[ind]+ fn(ind+1,0,fee,prices,dp),0+fn(ind+1,1,fee,prices,dp));
        }
        else{
            //fee will be detected once we sell as one transaction completes
            profit=max(+prices[ind]-fee+fn(ind+1,1,fee,prices,dp),0+fn(ind+1,0,fee,prices,dp));
        }
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {

        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return fn(0,1,fee,prices,dp);
        
    }
};