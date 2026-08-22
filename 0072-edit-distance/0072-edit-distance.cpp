class Solution {
public:
    int f(int i, int j, string s, string t, vector<vector<int>>& dp) {
        // base case
        if(j<0 && i<0) return 0;
        if(j<0) return 1 + i;
        if(i<0) return 1 + j;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j] = 0 + f(i-1,j-1,s,t,dp);
        else return dp[i][j] = 1 + min({
            f(i,j-1,s,t,dp), // insert
            f(i-1,j,s,t,dp), // del
            f(i-1,j-1,s,t,dp) // replace
        });
    }
    int minDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        // return f(n-1,m-1,s,t,dp);
        // vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        vector<int> dp(m+1,0);
        dp[0] = 0;
        // for(int i=1; i<n+1; i++) dp[i][0] = i;
        for(int j=1; j<m+1; j++) dp[j] = j;
        for(int i=1; i<n+1; i++) {
            vector<int> prev = dp;
            dp[0] = i;
            for(int j=1; j<m+1; j++) {
                if(s[i-1]==t[j-1]) dp[j] = 0 + prev[j-1];
                else dp[j] = 1 + min({
                    dp[j-1],
                    prev[j], 
                    prev[j-1]
                });
            }
        }
        return dp[m];

    }
};