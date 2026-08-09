class Solution {
public:
    void NSE(vector<int>& v,vector<int>& nse) {
        int n = v.size();
        stack<pair<int,int>> st;
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && st.top().first>=v[i]) st.pop();
            nse[i] = st.empty() ? n : st.top().second;
            st.push({v[i],i});
        }
    }
    void PSE(vector<int>& v,vector<int>& pse) {
        int n = v.size();
        stack<pair<int,int>> st;
        for(int i=0; i<n; i++) {
            while(!st.empty() && st.top().first>=v[i]) st.pop();
            pse[i] = st.empty() ? -1 : st.top().second;
            st.push({v[i],i});
        }
    }
    int largestRectangleArea(vector<int>& v) {
        int n = v.size();
        vector<int> nse(n,0),pse(n,0);
        NSE(v,nse);
        PSE(v,pse);
        int res = -1;
        for(int i=0; i<n; i++) {
            int left = pse[i];
            int right = nse[i];
            res = max(res,(right-left-1)*v[i]);
        } 
        return res;
    }
};