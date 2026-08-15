class Solution {
public:
    int f(int i, vector<int>& nums,vector<int>& dp) {
        //  base case
        int n = nums.size();
        if(i>=n) return 0;
        if(i==n-1) return nums[n-1];
        if(dp[i]!=-1) return dp[i];
        int pick1 = nums[i] + f(i+1,nums,dp);
        int pick2 = nums[i] + f(i+2,nums,dp);
        return dp[i] = min(pick1,pick2);
    }
    int minCostClimbingStairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n+1,0);
        vector<int> dp2(n+1,0);
        // return  min(f(0,cost,dp1),f(1,cost,dp2));
        dp1[n-1] = nums[n-1];
        dp2[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--) {
            int pick1 = nums[i] + dp1[i+1];
            int pick2 = nums[i] + dp1[i+2];
            dp1[i] = min(pick1,pick2);
        }
        for(int i=n-2; i>=1; i--) {
            int pick1 = nums[i] + dp2[i+1];
            int pick2 = nums[i] + dp2[i+2];
            dp2[i] = min(pick1,pick2);
        }
        return min(dp1[0],dp2[1]);
    }
};