class Solution {
public:
    bool f(int i, int sum, vector<int>& nums, vector<vector<int>>& dp) {
        if(i==0) return sum==nums[0];
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
        // vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        // return f(n-1,sum/2,nums,dp);
        vector<vector<int>> dp(n,vector<int>(sum+1,0));
        dp[0][nums[0]] = 1;
        for(int i=0; i<n; i++) dp[i][0] = 1;

        for(int i=1; i<n; i++) {
            for(int j=0; j<=sum/2; j++) {
                bool pick  = j-nums[i]>=0 ? dp[i-1][j-nums[i]] : 0;
                bool notpick = dp[i-1][j];
                dp[i][j] = pick | notpick;
            }
        }
        return dp[n-1][sum/2];

    }
};