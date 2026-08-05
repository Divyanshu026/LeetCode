class Solution {
public:
    int f(vector<int>& s, int k) {
        if(k<0) return 0;
        unordered_map<int,int> mpp;
        int n = s.size();
        int l = 0,r=0;
        int cnt=0;
        while(r<n) {
            mpp[s[r]]++;
            while(l<=r && mpp.size()>k) {
                mpp[s[l]]--;
                if(mpp[s[l]]==0) mpp.erase(s[l]);
                l++;
            }
            cnt+=r-l+1;
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums,k) - f(nums,k-1);
    }
};