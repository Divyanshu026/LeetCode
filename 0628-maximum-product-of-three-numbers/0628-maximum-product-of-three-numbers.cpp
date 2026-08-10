class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        int n = nums.size();
        int a = nums[n-1]*nums[n-2]*nums[0];
        int b = nums[0]*nums[1]*nums[2];
        return a>b ? a : b;
    }
};