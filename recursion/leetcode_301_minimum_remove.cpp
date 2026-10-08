class Solution {
public:
set<string>ans;
int maxi=0;
    void fn(int ind,int balance,string &s,string &temp){
        if(ind==s.size()){
            
            if(balance==0){
               if (temp.size() > maxi) {
                    maxi = temp.size();
                    ans.clear();
                    ans.insert(temp);
                }
                else if (temp.size() == maxi) {
                    ans.insert(temp);
                }
            } 
            return;
        }
        if(balance<0) return;
       
        
        if (s[ind] != '(' && s[ind] != ')') {
            temp.push_back(s[ind]);

            fn(ind + 1, balance, s, temp);

            temp.pop_back();
            return;
        }
        temp.push_back(s[ind]);
        if(s[ind]=='('){
            fn(ind+1,balance+1,s,temp);
        }
        else{
            fn(ind+1,balance-1,s,temp);
        }
        
        temp.pop_back();
        fn(ind+1,balance,s,temp);
        
    }
    vector<string> removeInvalidParentheses(string s) {
        string temp="";

        fn(0,0,s,temp);
       
         return vector<string>(ans.begin(), ans.end());


        
        
    }
};