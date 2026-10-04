//brute force
class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        int maxi=INT_MIN;

        for(int i=0;i<n;i++){
            if(s[i]==')') continue;
            int balance=0;
            for(int j=i;j<n;j++){
                if(s[j]=='(') balance++;
                else balance--;
                if(balance<0) break;
                if(balance ==0) maxi=max(maxi,j-i+1);

            }
        }
        return max(maxi,0);
        
    }
};

// using stack
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int n = s.length();
        int maxi =0;
        st.push(-1);
        int i=0;
        while(i<n){
            if(s[i] == '('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }else{
                    maxi = max(maxi, i-st.top());
                }
            }
            i++;
        }
        return maxi;
    }
};
//using two loop optimxized space 
class Solution {
public:
    int longestValidParentheses(string s) {
        int open = 0, close = 0;
        int maxi = 0;

        for (char ch : s) {
            if (ch == '(')
                open++;
            else
                close++;

            if (open == close)
                maxi = max(maxi, 2 * close);

            if (close > open)
                open = close = 0;
        }

        // Right -> Left
        open = close = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '(')
                open++;
            else
                close++;

            if (open == close)
                maxi = max(maxi, 2 * open);

            if (open > close)
                open = close = 0;
        }

        return maxi;
    }
};