#define ll long long
class Solution {
public:
    int f(int i, int j, string s, string t,vector<vector<int>>& dp) {
        // base case
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int pick = s[i]==t[j] ? f(i-1,j-1,s,t,dp) : 0;
        int notpick = f(i-1,j,s,t,dp);
        return dp[i][j] =  pick+notpick;
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m = t.size();
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return f(n-1,m-1,s,t,dp);
        // vector<vector<ll>> dp(n+1,vector<ll>(m+1,0));
        vector<double> dp(m+1,0);
        // for(int i=0; i<n+1; i++) dp[i][0] = 1;
        dp[0]=1;
        for(int i=1; i<n+1; i++) {
            for(int j=m; j>=1; j--) {
                if(s[i-1]==t[j-1]) dp[j] = dp[j-1] + dp[j];
            }
        }
        return (int)dp[m];
    }
};