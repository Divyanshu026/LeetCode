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
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp1(n+1,-1);
        vector<int> dp2(n+1,-1);
        return  min(f(0,cost,dp1),f(1,cost,dp2));
    }
};