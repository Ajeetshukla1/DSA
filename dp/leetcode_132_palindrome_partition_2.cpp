////                  By memoization  
///        tc-o(n^2)
  ///      sc-o(n)+o(n) auxilary stack space 

class Solution {
public:
    bool palindromeCheck(string &s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;

    }
    int fn(int i,string &s,vector<int>&dp){
        if(i==s.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int mini=INT_MAX;
        for(int j=i;j<s.size();j++){
            if(palindromeCheck(s,i,j)){
                int cost=1+fn(j+1,s,dp);
                mini=min(mini,cost);
            }
        }
        return dp[i]=mini;
    }
    int minCut(string s) {
        vector<int>dp(s.size(),-1);
        return fn(0,s,dp)-1; // because it do partition at the last also that's why we need to remove that partition eg)abc -> a|b|c| -> here partition is 3 because it also partitioned at last therefore we need to do -1;
    }
};


 ///////////////    using tabulation
  /// tc-> o(n^2)
  //// sc->o(n) 
 class Solution {
public:
    bool palindromeCheck(string &s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;

    }

    int minCut(string s) {
        

        int n=s.size();
        vector<int>dp(n+1,0);
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            int minCost=INT_MAX;
            for(int j=i;j<n;j++){
                if(palindromeCheck(s,i,j)){
                    int cost=1+dp[j+1];
                    minCost=min(cost,minCost);
                }
            }
            dp[i]=minCost;
        }
        return dp[0]-1;
    }
};
