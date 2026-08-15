class Solution {
public:
    int f(int i, int val, vector<int>& nums,vector<vector<int>>& dp) {
        // base case
        if(val<0) return 0;
        if(i==0) {
            if(val==0) return nums[0]==0 ? 2 : 1;
            else return val==nums[0];
        }
         
        if(dp[i][val]!=-1) return dp[i][val];
        int pick = f(i-1,val-nums[i],nums,dp);
        int notpick = f(i-1,val,nums,dp);
        return dp[i][val] =  pick+notpick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = accumulate(nums.begin(),nums.end(),0);
        if(abs(target) > total) return 0;
        if((target+total)%2!=0) return 0;
        int x = (target + total)/2;
        // vector<vector<int>> dp(n,vector<int>(x+1,-1));
        // return f(n-1,x,nums,dp);
        vector<vector<int>> dp(n,vector<int>(x+1,0));
        dp[0][0] = nums[0]==0 ? 2 : 1;
        for(int val=1; val<=x; val++) dp[0][val] = val==nums[0];

        for(int i=1; i<n; i++) {
            for(int val=0; val<=x; val++) {
                int pick = val-nums[i]>=0 ? dp[i-1][val-nums[i]] : 0;
                int notpick = dp[i-1][val];
                dp[i][val] =  pick + notpick;
            }
        }
        return dp[n-1][x];

    }
};