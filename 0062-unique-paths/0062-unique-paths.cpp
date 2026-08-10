class Solution {
public:
    int f(int i, int j, vector<vector<int>>& dp) {
        if(i==0 && j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int left = i>0 ? f(i-1,j,dp) : 0;
        int up = j>0 ? f(i,j-1,dp) : 0;
        return dp[i][j] =  left + up;
    }
    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,dp);
    }
};