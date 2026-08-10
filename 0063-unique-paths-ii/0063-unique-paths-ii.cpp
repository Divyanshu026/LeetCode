class Solution {
public:
    int f(int i, int j, vector<vector<int>>& v, vector<vector<int>>& dp) {
        if(v[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int left = j>0 ? f(i,j-1,v,dp) : 0;
        int up = i>0 ? f(i-1,j,v,dp) : 0;
        return dp[i][j] =  left + up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return f(n-1,m-1,v,dp);
        vector<vector<int>> dp(n,vector<int>(m,0));
        dp[0][0] = v[0][0]==1 ? 0 : 1;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i==0 && j==0) continue;
                int left = j>0 ? dp[i][j-1] : 0;
                int up = i>0 ? dp[i-1][j] : 0;
                dp[i][j] =  v[i][j]==1 ? 0 : left + up;
            }
        }
        return dp[n-1][m-1];
    }
};