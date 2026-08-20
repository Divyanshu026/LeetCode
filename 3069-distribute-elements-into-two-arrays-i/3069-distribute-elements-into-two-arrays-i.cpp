class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        stack<int> st1,st2;
        st1.push(nums[0]);
        st2.push(nums[1]);
        for(int i=2; i<nums.size(); i++) {
            if(st1.top()>st2.top()) st1.push(nums[i]);
            else st2.push(nums[i]);
        }
        vector<int> v(n,0);
        int i=n-1;
        while(!st1.empty() || !st2.empty()) {
            if(!st2.empty()) {
                v[i] = st2.top();
                st2.pop();
            } else {
                v[i] = st1.top();
                st1.pop();
            }
            i--;
            
        }
        return v;
    }
};