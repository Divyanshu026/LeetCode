class Solution {
public:
    void NSE(vector<int>& arr,vector<int>& nse) {
        stack<pair<int,int>> st;
        int n = arr.size();
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && st.top().first>=arr[i]) st.pop();
            nse[i] = st.empty() ? n : st.top().second;
            // if(i==it) return st.empty() ?  n : st.top().second;
            st.push({arr[i],i});
        }

    }
    void PSEE(vector<int>& arr, vector<int>& psee) {
        int n = arr.size();
        stack<pair<int,int>> st;
        for(int i=0; i<n; i++) {
            while(!st.empty() && st.top().first>arr[i]) st.pop();
            psee[i] =  st.empty() ? -1 : st.top().second;
            st.push({arr[i],i});
        }
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int sum = 0;
        int mod = (int)(1e9+7);
        vector<int>nse(n,0),psee(n,0);
        NSE(arr,nse);
        PSEE(arr,psee);
        for(int i=0; i<n; i++) {
            sum = (sum + ((nse[i]-i)*(i-psee[i])*1LL*arr[i])%mod)%mod;
        }
        return sum;
    }
};