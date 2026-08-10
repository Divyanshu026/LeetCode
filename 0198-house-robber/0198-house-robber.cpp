class Solution {
public:
    int f(int i, vector<int>& nums,vector<int>& dp) {
        if(i<0) return 0;
        if(i==0) return nums[0];
        if(dp[i]!=-1) return dp[i];
        int pick = nums[i] + f(i-2,nums,dp);
        int notpick = 0 + f(i-1,nums,dp);
        return dp[i] = max(pick,notpick);
    }
    int rob(vector<int>& nums) {
      int n = nums.size();
    //   vector<int> dp(n+1,-1);
    //   return f(n-1,nums,dp);
      vector<int> dp(n,0);
      dp[0] = nums[0];
      for(int i=1; i<n; i++) {
        int pick = i>1 ? nums[i] + dp[i-2] : nums[i];
        int notpick = 0 + dp[i-1];
        dp[i] = max(pick,notpick);
      }
      return dp[n-1];
    }
};