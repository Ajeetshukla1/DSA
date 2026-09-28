class Solution {
public:
    vector<string> ans;

    void fn(string &num, long long target, int index,
            long long value, long long prev, string &temp) {

        // Entire string has been used
        if (index == num.size()) {
            if (value == target) {
                ans.push_back(temp);
            }
            return;
        }

        long long curr = 0;
        int n = num.size();

        for (int i = index; i < n; i++) {

            // Leading zero is not allowed
            // Example: 05 is invalid
            if (i > index && num[index] == '0')
                break;

            curr = curr * 10 + (num[i] - '0');

            string part = num.substr(index, i - index + 1);

            // First number
            if (index == 0) {
                temp += part;

                fn(num, target, i + 1,
                   curr, curr, temp);

                temp.erase(temp.size() - part.size());
            }
            else {

                // +
                temp += "+" + part;

                fn(num, target, i + 1,
                   value + curr, curr, temp);

                temp.erase(temp.size() - part.size() - 1);


                // -
                temp += "-" + part;

                fn(num, target, i + 1,
                   value - curr, -curr, temp);

                temp.erase(temp.size() - part.size() - 1);


                // *
                temp += "*" + part;

                fn(num, target, i + 1,
                   value - prev + prev * curr,
                   prev * curr,
                   temp);

                temp.erase(temp.size() - part.size() - 1);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        string temp = "";

        fn(num, target, 0, 0, 0, temp);

        return ans;
    }
};