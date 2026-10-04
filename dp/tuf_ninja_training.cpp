//question is present of striver sheet tuf

//memoization approach
class Solution {
public:
    int fn(int ind,int prev,vector<vector<int>>& matrix , vector<vector<int>>& dp){
        if(ind<0) return 0;
        if(dp[ind][prev]!=-1) return dp[ind][prev]; 
        
        int maxi=INT_MIN;
    
        for(int activity=0;activity<3;activity++){
            if(prev==activity && ind!=matrix.size()-1) continue;
            int cost=fn(ind-1,activity,matrix,dp)+matrix[ind][activity];
            maxi=max(cost,maxi);
        }
        return dp[ind][prev]=maxi;

    }
    int ninjaTraining(vector<vector<int>>& matrix) {
      vector<vector<int>>dp(matrix.size(),vector<int>(3,-1));
      return fn(matrix.size()-1,0,matrix,dp);


    }
};
//tabulation approach
class Solution {
public:
    int ninjaTraining(vector<vector<int>>& matrix) {

        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(3, 0));

        // Day 0
        dp[0][0] = max(matrix[0][1], matrix[0][2]);
        dp[0][1] = max(matrix[0][0], matrix[0][2]);
        dp[0][2] = max(matrix[0][0], matrix[0][1]);

        // Day 1 to n-1
        for(int day = 1; day < n; day++) {

            for(int prev = 0; prev < 3; prev++) {

                for(int activity = 0; activity < 3; activity++) {

                    if(activity == prev)
                        continue;

                    dp[day][prev] = max(
                        dp[day][prev],
                        matrix[day][activity] +
                        dp[day - 1][activity]
                    );
                }
            }
        }

        return max({
            dp[n-1][0],
            dp[n-1][1],
            dp[n-1][2]
        });
    }
};
// space optimization approach
class Solution {
public:
    int ninjaTraining(vector<vector<int>>& matrix) {

        int n = matrix.size();

        vector<int> prev(3, 0);
        vector<int> curr(3, 0);

        // Day 0
        prev[0] = max(matrix[0][1], matrix[0][2]);
        prev[1] = max(matrix[0][0], matrix[0][2]);
        prev[2] = max(matrix[0][0], matrix[0][1]);

        // Day 1 -> n-1
        for(int day = 1; day < n; day++) {

            for(int previous = 0; previous < 3; previous++) {

                curr[previous] = 0;

                for(int activity = 0; activity < 3; activity++) {

                    if(activity == previous)
                        continue;

                    int points = matrix[day][activity]
                               + prev[activity];

                    curr[previous] = max(curr[previous], points);
                }
            }

            // Current day becomes previous day
            prev = curr;
        }

        return max({
            prev[0],
            prev[1],
            prev[2]
        });
    }
};