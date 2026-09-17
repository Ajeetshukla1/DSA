//brute
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {

        int n = arr.size();

        vector<int> prefix(n, INT_MAX);
        vector<int> suffix(n, INT_MAX);

        // ---------- PREFIX ----------
        int i = 0;
        int sum = 0;
        int best = INT_MAX;

        for (int j = 0; j < n; j++) {

            sum += arr[j];

            while (sum > target && i <= j) {
                sum -= arr[i];
                i++;
            }

            if (sum == target) {
                best = min(best, j - i + 1);
            }

            prefix[j] = best;
        }

        // ---------- SUFFIX ----------
        i = n - 1;
        sum = 0;
        best = INT_MAX;

        for (int j = n - 1; j >= 0; j--) {

            sum += arr[j];

            while (sum > target && i >= j) {
                sum -= arr[i];
                i--;
            }

            if (sum == target) {
                best = min(best, i - j + 1);
            }

            suffix[j] = best;
        }

        // ---------- COMBINE ----------
        int ans = INT_MAX;

        for (int i = 0; i < n - 1; i++) {

            if (prefix[i] != INT_MAX &&
                suffix[i + 1] != INT_MAX) {

                ans = min(ans, prefix[i] + suffix[i + 1]);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

//optimal using dp with time and space complexity of o(n)
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {

        int n = arr.size();
        vector<int> dp(n, INT_MAX);

        int left = 0;
        int sum = 0;
        int ans = INT_MAX;
        int best = INT_MAX;

        for (int right = 0; right < n; right++) {

            sum += arr[right];

            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            // Found a subarray [left ... right]
            if (sum == target) {

                int len = right - left + 1;

                // Combine with previous non-overlapping subarray
                if (left > 0 && dp[left - 1] != INT_MAX) {
                    ans = min(ans, len + dp[left - 1]);
                }

                // This is the best single subarray so far
                best = min(best, len);
            }

            dp[right] = best;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};