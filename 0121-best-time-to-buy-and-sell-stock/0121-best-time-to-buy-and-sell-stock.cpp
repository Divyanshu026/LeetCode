class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> suffixmax(n+1,0);
        // suffixmax[n-1] = prices[n-1];
        for(int i=n-1; i>=0; i--) suffixmax[i] = max(suffixmax[i+1],prices[i]);
        int res = -1;
        for(int i=0; i<n; i++) {
            int profit = abs(suffixmax[i]-prices[i]);
            res = max(res,profit);
        }
        return res;
    }
};