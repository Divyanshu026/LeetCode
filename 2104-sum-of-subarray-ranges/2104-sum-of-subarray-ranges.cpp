
class Solution {
public:
    void NGE(vector<int>& nums,vector<int>& nge) {
        int n = nums.size();
        stack<pair<int,int>> st;
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && st.top().first<=nums[i]) st.pop();
            nge[i] = st.empty() ? n : st.top().second;
            st.push({nums[i],i});
        }
    }
    void PGEE(vector<int>& nums,vector<int>& pgee) {
        int n = nums.size();
        stack<pair<int,int>> st;
        for(int i=0; i<n; i++) {
            while(!st.empty() && st.top().first<nums[i]) st.pop();
            pgee[i] = st.empty () ? -1 : st.top().second;
            st.push({nums[i],i});
        }
    }
    void NSE(vector<int>& nums,vector<int>& nse) {
        int n = nums.size();
        stack<pair<int,int>> st;
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && st.top().first>=nums[i]) st.pop();
            nse[i] = st.empty() ? n : st.top().second;
            st.push({nums[i],i});
        }
    }
    void PSEE(vector<int>& nums,vector<int>& psee) {
        int n = nums.size();
        stack<pair<int,int>> st;
        for(int i=0; i<n; i++) {
            while(!st.empty() && st.top().first>nums[i]) st.pop();
            psee[i]  = st.empty() ? -1 : st.top().second;
            st.push({nums[i],i});
        }
    }
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        vector<int> nge(n,0),nse(n,0),pgee(n,0),psee(n,0);
        NGE(nums,nge);
        PGEE(nums,pgee);
        NSE(nums,nse);
        PSEE(nums,psee);
        for(int i=n-1; i>=0; i--) {
            sum+= 1LL*(i-nge[i])*(pgee[i]-i)*nums[i] - 1LL*(i-nse[i])*(psee[i]-i)*nums[i];
        }
        return sum;
    }
};