class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==n) return *max_element(nums.begin(),nums.end());
        map<int,int> mpp;
        for(int i=0; i<n; i++) mpp[nums[i]]++;
        if(k==1) {      
            int res = -1;
            for(auto it:mpp) {
                if(it.second==1) {
                    res = max(res,it.first);
                }
            }
            return res;
        }
        if(mpp[nums[0]]==1) {
            if(mpp[nums[n-1]]==1) return max(nums[0],nums[n-1]);
            else return nums[0];
        } 
        else if(mpp[nums[n-1]]==1) {
            if(mpp[nums[0]]==1) return max(nums[0],nums[n-1]);
            else return nums[n-1];
        }
        else return -1;

    }
};