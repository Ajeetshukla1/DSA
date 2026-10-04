class Solution {
public:
    bool checkValidString(string s) {

        stack<int> open;
        stack<int> star;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                open.push(i);
            }

            else if (s[i] == '*') {
                star.push(i);
            }

            else { // ')'

                // Prefer a real '('
                if (!open.empty()) {
                    open.pop();
                }

                // Otherwise use '*' as '('
                else if (!star.empty()) {
                    star.pop();
                }

                // Nothing available
                else {
                    return false;
                }
            }
        }

        // Match remaining '(' with '*' acting as ')'
        while (!open.empty() && !star.empty()) {

            // '*' must occur AFTER '('
            if (open.top() > star.top()) {
                return false;
            }

            open.pop();
            star.pop();
        }

        // If '(' remain, they cannot be matched
        return open.empty();
    }
};