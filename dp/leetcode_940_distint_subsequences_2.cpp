class Solution {
public: 
    
    int distinctSubseqII(string s) {
        long long dp=1;
        int MOD=1e9+7;
        vector<int>last(26,0);
        for(char ch:s){
            long long old=dp;
            dp=(2*dp)%MOD;
            //it is permutation approach 
            dp=(dp-last[ch-'a'])%MOD;
            //removing the subsequence which are made by duplicate characters
            last[ch-'a']=old;
            //updating the last with , what was the count before adding the character
        }
        return (dp-1+MOD)%MOD;
        //removing the empty string   
    }
};