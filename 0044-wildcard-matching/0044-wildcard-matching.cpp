class Solution {
public:
    bool f(int i, int j, string s, string t, vector<vector<int>>& dp) {
        // base case
        if(i<0 && j<0) return true;
        if(j<0) return false;
        if(i<0) {
            return t[j]=='*' ? f(i,j-1,s,t,dp) : false;
        }
        if(dp[i][j]!=-1) return dp[i][j];

        if(t[j]==s[i]) return dp[i][j] = f(i-1,j-1,s,t,dp);
        else if(t[j]=='?') return dp[i][j] = f(i-1,j-1,s,t,dp);
        else if(t[j]=='*') return dp[i][j] =  f(i-1,j,s,t,dp) || f(i-1,j-1,s,t,dp) || f(i,j-1,s,t,dp);
        else return dp[i][j] = false;
        
    }
    bool isMatch(string s, string t) {
        int n = s.size();
        int m = t.size();
        // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        // return f(n-1,m-1,s,t,dp);
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        dp[0][0] = true;
        for(int i=1; i<n+1; i++) dp[i][0] = false;
        for(int j=1; j<m+1; j++) dp[0][j] = t[j-1]=='*' ?  dp[0][j-1] : false;
        for(int i=1; i<n+1; i++) {
            for(int j=1; j<m+1; j++) {
                if(t[j-1]==s[i-1]) dp[i][j] = dp[i-1][j-1];
                else if(t[j-1]=='?') dp[i][j] = dp[i-1][j-1];
                else if(t[j-1]=='*') dp[i][j] =  dp[i-1][j] || dp[i-1][j-1] || dp[i][j-1];
                else dp[i][j] = false;
            }
        }
        return dp[n][m];
    }
};