class Solution {
public:
    int f(int i,vector<int>& dp) {
        if(i==0) return 1;
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i] = f(i-1,dp) + f(i-2,dp);
    }
    int climbStairs(int n) {
        // vector<int> dp(n+1,-1);
        // return f(n,dp);
        // tabulation
        vector<int> dp(n+1,0);
        dp[0] = 1;
        for(int i=1; i<=n; i++) {
            if(i==1) dp[i] = dp[0] + 0;
            else dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};