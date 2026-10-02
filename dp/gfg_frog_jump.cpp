//   memoization

class Solution {
  public:
    int n;
    int fn(vector<int>& height,vector<int>& dp,int i){
        if(i<=0){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int oneStep=fn(height,dp,i-1)+abs(height[i-1]-height[i]);
        int twoStep=INT_MAX;
        if(i>=2){
            twoStep=fn(height,dp,i-2)+abs(height[i-2]-height[i]);
        }
        return dp[i]=min(oneStep,twoStep);
        
    }
    
    int minCost(vector<int>& height) {
        // Code here
         n=height.size();
        vector<int>dp(n,-1);
        return fn(height,dp,n-1);
        
    }
};

// tabulation
class Solution {
  public:
   
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        vector<int>dp(n,0);
        for(int i=1;i<n;i++){
            int fs=dp[i-1]+abs(height[i-1]-height[i]);
            int ss=INT_MAX;
            if(i>1){
                ss=dp[i-2]+abs(height[i-2]-height[i]);
            }
            dp[i]=min(fs,ss);
        }
        return dp[n-1];
        
    }
};

// space optimization
class Solution {
  public:
   
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        int prev1=0;
        int prev2=0; 
        
        for(int i=1;i<n;i++){
            int fs=prev1+abs(height[i-1]-height[i]);
            int ss=INT_MAX;
            if(i>1){
                ss=prev2+abs(height[i-2]-height[i]);
            }
            int curr=min(fs,ss);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
        
    }
};