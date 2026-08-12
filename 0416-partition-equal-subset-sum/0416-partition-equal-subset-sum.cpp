class Solution {
public:
    bool f(int i, int sum, vector<int>& nums, vector<vector<int>>& dp) {
        if(i==0) return sum==nums[i];
        if(sum==0) return true;
        if(sum<0) return false;
        if(dp[i][sum]!=-1) return dp[i][sum];
        bool pick  = f(i-1,sum-nums[i],nums,dp);
        bool notpick = f(i-1,sum,nums,dp);
        return dp[i][sum] = pick | notpick;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2) return false;
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return f(n-1,sum/2,nums,dp);

    }
};