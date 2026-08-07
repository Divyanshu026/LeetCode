class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n = a.size();
        stack<int> st;
        vector<int> res;
        for(int i=n-1; i>=0; i--) {
            if(a[i]<0) {
                st.push(a[i]);
                continue;
            }
            while(!st.empty() && st.top()<0 && abs(st.top())<a[i]) st.pop();
            if(st.empty() || st.top()>0 ) {
                st.push(a[i]);
                continue;
            }
            if(!st.empty() && st.top()<0 && abs(st.top())==a[i]) st.pop();
            
              
        }
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};