class Solution {
public:
    void f(int &res, vector<int>& v) {
        int n = v.size();
        stack<int> st;
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
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> v(m,0);
        int res=-1;
        // for(int j=0; j<m; j++) v[j] = matrix[0][j]-'0';
        for(int i=0; i<n; i++) {

            for(int j=0; j<m; j++) {
                v[j] = matrix[i][j]-'0' == 1 ? v[j]+1 : 0 ;
            }
            f(res,v);
        }
        return res;
    }
};