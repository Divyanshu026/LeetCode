class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        int n = v.size();
        stack<pair<int,int>> st;
        int res=-1;
        for(int i=0; i<n; i++) {
            while(!st.empty() && st.top().first>=v[i]) {
                int val = st.top().first;
                st.pop();
                if(st.empty()) res = max(res,(i)*val);
                else res = max(res,(i-st.top().second-1)*val);
            }
            st.push({v[i],i});
        }
        while(!st.empty()) {
            int val = st.top().first;
            st.pop();
            if(st.empty()) res = max(res,(n)*val);
            else res = max(res,(n-st.top().second-1)*val);
        }
        return res;
    }
};