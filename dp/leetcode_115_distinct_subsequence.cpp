class Solution {
public:

    int fn(int i,int j,string &s,string &t,vector<vector<int>>&dp){

        // if t is formed
        if(j==t.size()) return 1;

        // s is exhauseted
        if(i==s.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        //when characters are equal
        if(s[i]==t[j]){
            // add both if we are taking s[i] or not 
            return dp[i][j]=fn(i+1,j+1,s,t,dp)+fn(i+1,j,s,t,dp);
        }
        // if characters are not equal
        else return dp[i][j]=fn(i+1,j,s,t,dp);
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));

        return fn(0,0,s,t,dp);
        
        

        
    }
};