class Solution {
public:
    int f(int i, int j, string s, string t, vector<vector<int>>& dp) {
        // base case
        if(i<0 || j<0) return 0;
        // if(i==0) {
        //     if(s[0]==t[j]) return 1 + f(i-1,j-1,s,t,dp);
        //     else return 0 + f(i,j-1,s,t,dp);
        // }
        // if(j==0) {
        //     if(s[i]==t[0]) return 1 + f(i-1,j-1,s,t,dp);
        //     else return 0 + f(i-1,j,s,t,dp);
        // }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j] = 1 + f(i-1,j-1,s,t,dp);
        else return dp[i][j] =  0 + max(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp));
    }
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        int n = s.size();
        int m = t.size();
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return f(n-1,m-1,s,t,dp);
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(s[i-1]==t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] =  0 + max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};