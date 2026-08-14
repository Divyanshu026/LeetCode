class Solution {
public:
    int f(int i, int j, vector<int>& nums) {
        // base case
        if(i==0) {
            int add = j-nums[0]==0 ? 1 : 0;
            int sub = j+nums[0]==0 ? 1 : 0;
            return add + sub;
        }
        int add = f(i-1,j-nums[i],nums);
        int sub = f(i-1,j+nums[i],nums);
        return add + sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return f(n-1,target,nums);
    }
};