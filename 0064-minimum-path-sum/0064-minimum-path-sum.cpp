class Solution {
public:
    int f(int i,int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if(i==0 && j==0) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int left = j>0 ? grid[i][j] + f(i,j-1,grid,dp) : 1e9;
        int up = i>0 ? grid[i][j] + f(i-1,j,grid,dp) : 1e9;
        // int mod = 1e9+7;
        return dp[i][j] = min(left,up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return f(n-1,m-1,grid,dp);
        vector<vector<int>> dp(n,vector<int>(m,0));
        dp[0][0] = grid[0][0];
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i==0 && j==0) continue;
                int left = j>0 ? grid[i][j] + dp[i][j-1] : 1e9;
                int up = i>0 ? grid[i][j] + dp[i-1][j] : 1e9;
                dp[i][j] = min(left,up);
            }
        }
        return dp[n-1][m-1];

    }
};