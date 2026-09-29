// brute force solution
class Solution {
public:
    bool isValid(string &s) {
        int balance = 0;

        for (char c : s) {
            if (c == '(')
                balance++;
            else
                balance--;

            if (balance < 0)
                return false;
        }

        return balance == 0;
    }

    bool check(int i, int j, vector<vector<char>>& grid, string &temp) {
        int n = grid.size();
        int m = grid[0].size();

        if (i >= n || j >= m)
            return false;

        // Add current cell
        temp += grid[i][j];

        // Destination
        if (i == n - 1 && j == m - 1) {
            bool ans = isValid(temp);
            temp.pop_back();
            return ans;
        }

        // Try down
        if (check(i + 1, j, grid, temp)) {
            temp.pop_back();
            return true;
        }

        // Backtrack
        temp.pop_back();

        // Add current cell again before right path
        temp += grid[i][j];

        // Try right
        if (check(i, j + 1, grid, temp)) {
            temp.pop_back();
            return true;
        }

        // Backtrack
        temp.pop_back();

        return false;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        string temp = "";
        return check(0, 0, grid, temp);
    }
};

// optimal solution using dp
class Solution {
public:
    int n,m;
    vector<vector<vector<int>>> dp;

    bool check(int i,int j,vector<vector<char>>& grid,int balance){
        int n=grid.size();
        int m=grid[0].size();
        if (i >= n || j >= m)
            return false;
        if(grid[i][j]=='('){
            balance++;
        }
        else balance--;
        if(balance<0) return false;
        int remaining=(n-1-i)+(m-j-1);
        if(balance>remaining) return false;
        if(i==n-1 && j==m-1){
            return balance ==0;
        }
        if(dp[i][j][balance]!=-1) return dp[i][j][balance];
        return dp[i][j][balance]=check(i+1,j,grid,balance) || check(i,j+1,grid,balance);
        
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        //if string that can be generated is odd then it is not possible to get balance paranthesis
        if((n+m-1)%2!=0) return false;
        //staring and end shoud be '('  ')' respectively
        if(grid[0][0]==')' || grid[n-1][m-1]=='(') return false;
         dp.assign(n, vector<vector<int>>(
            m, vector<int>(n + m + 1, -1)
        ));


        
        return check(0,0,grid,0);

        
    }
};