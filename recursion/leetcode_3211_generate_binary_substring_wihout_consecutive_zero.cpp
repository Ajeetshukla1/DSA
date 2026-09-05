class Solution {
public:
    vector<string>ans;
    void fn(string &s,int n){
        if(s.size()==n){
            ans.push_back(s);
            return;
        };
        // We can always add '1'
        s += '1';
        fn(s, n);
        s.pop_back();

        // We can add '0' only if:
        // string is empty OR previous character is '1'
        if (s.empty() || s.back() == '1') {
            s += '0';
            fn(s, n);
            s.pop_back();
        }
    }
    vector<string> validStrings(int n) {
        string s;
        fn(s,n);
        return ans;
        
    }
};