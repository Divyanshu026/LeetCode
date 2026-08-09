class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        int n = v.size();
        stack<int> st;
        int res=-1;
        for(int i=0; i<n; i++) {
            while(!st.empty() && v[st.top()]>=v[i]) {
                int val = v[st.top()];
                st.pop();
                if(st.empty()) res = max(res,(i)*val);
                else res = max(res,(i-st.top()-1)*val);
            }
            st.push(i);
        }
        while(!st.empty()) {
            int val = v[st.top()];
            st.pop();
            if(st.empty()) res = max(res,(n)*val);
            else res = max(res,(n-st.top()-1)*val);
        }
        return res;
    }
};