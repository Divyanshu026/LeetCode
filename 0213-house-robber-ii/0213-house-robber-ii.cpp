class Solution {
public:
    int f(int i, vector<int>& v, vector<int>& dp) {
        if(i<0) return 0;
        if(i==0) return v[i];
        if(dp[i]!=-1) return dp[i];
        int pick = v[i] + f(i-2,v,dp);
        int notpick = 0 + f(i-1,v,dp);
        return dp[i] = max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> v1(n-1,0),v2(n-1,0);
        for(int i=0; i<n; i++) {
            if(i==0) {
                v1[i]=nums[i];
                continue;
            }
            if(i==n-1) {
                v2[i-1] = nums[i];
                continue;
            }
            v1[i] = nums[i];
            v2[i-1] = nums[i];
        }
        int m = v1.size();
        vector<int> dp1(m,-1),dp2(m,-1);
        return max(f(m-1,v1,dp1),f(m-1,v2,dp2));
    }
};