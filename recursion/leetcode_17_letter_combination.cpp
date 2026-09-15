class Solution {
public:
    
    vector<string> mp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void fn(int ind,string s,vector<string> &ans,string &temp){
        if(ind ==s.size()){
            ans.push_back(temp);
            return;
        }
        int digit = s[ind] - '0';
        for(int i=0;i<mp[digit].size();i++){
            temp+=mp[digit][i];
            fn(ind+1,s,ans,temp);
            temp.pop_back();
           

        }
        
    }
    vector<string> letterCombinations(string digits) {
    vector<string> ans;
     if (digits.empty())
            return ans;
    string temp="";
    fn(0,digits,ans,temp);
    return ans;
    }  
};
             ""
        /     |     \
       a      b      c
     / | \  / | \  / | \
    ad ae af bd be bf cd ce cf