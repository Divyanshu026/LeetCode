class Solution {
public:
    int f(int i, int val, vector<int>& nums) {
        // base case
        
        if(i==0) {
            if(val==0) return nums[0]==0 ? 2 : 1;
            else return val-nums[0]==0 ? 1 : 0;
        }
         
        int pick = f(i-1,val-nums[i],nums);
        int notpick = f(i-1,val,nums);
        return pick+notpick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = accumulate(nums.begin(),nums.end(),0);
        if((target+total)%2!=0) return 0;
        int x = (target + total)/2;
        // vector<vector<int>> dp(n,vector<int>(x+1,-1));
        return f(n-1,x,nums);
    }
};