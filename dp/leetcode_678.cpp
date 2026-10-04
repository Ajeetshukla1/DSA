class Solution {
public:

    vector<vector<int>> dp;

    bool fn(string &s, int i, int open) {

        if (open < 0)
            return false;

        if (i == s.size())
            return open == 0;

        if (dp[i][open] != -1)
            return dp[i][open];

        bool ans = false;

        if (s[i] == '(') {
            ans = fn(s, i + 1, open + 1);
        }

        else if (s[i] == ')') {
            ans = fn(s, i + 1, open - 1);
        }

        else {

            // '*' -> '('
            ans = fn(s, i + 1, open + 1);

            // '*' -> ')'
            if (!ans)
                ans = fn(s, i + 1, open - 1);

            // '*' -> empty
            if (!ans)
                ans = fn(s, i + 1, open);
        }

        return dp[i][open] = ans;
    }

    bool checkValidString(string s) {

        int n = s.size();

        dp.assign(n, vector<int>(n + 1, -1));

        return fn(s, 0, 0);
    }
};