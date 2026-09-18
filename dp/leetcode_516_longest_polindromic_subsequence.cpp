class Solution {
public:
    int lcs(string &text1,string &text2,int ind1,int ind2,vector<vector<int>>&dp){
        if(ind1<0 || ind2<0) return 0; 
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(text1[ind1]==text2[ind2]) return 1+lcs(text1,text2,ind1-1,ind2-1,dp); 
        return dp[ind1][ind2]=max(lcs(text1,text2,ind1-1,ind2,dp),lcs(text1,text2,ind1,ind2-1,dp));
    
    }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        string r=s;
        reverse(s.begin(),s.end());
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return lcs(s,r,n-1,n-1,dp);
        
    }
};