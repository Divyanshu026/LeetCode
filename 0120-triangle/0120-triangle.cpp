class Solution {
public:
    int f(int i, int j, vector<vector<int>>& v, vector<vector<int>>& dp) {
        int n = v.size();
        int m = v[i].size();
        // base
        if(i==n-1 && j<m) return v[i][j];
        if(i>=n || j>=m) return 1e9;
        if(dp[i][j]!=1e9) return dp[i][j];
        int down = v[i][j] + f(i+1,j,v,dp);
        int diag = v[i][j] + f(i+1,j+1,v,dp);
        cout<<"down: "<<down<<" "<<"diag: "<<diag<<endl;
        return dp[i][j] = min(down , diag);
    }
    int minimumTotal(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[n-1].size();
        vector<vector<int>> dp(n,vector<int>(m,1e9));
        return f(0,0,v,dp);
    }
};