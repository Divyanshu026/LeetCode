class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        priority_queue<int> greed;
        priority_queue<int> size;
        for(int x: g) greed.push(x);
        for(int x: s) size.push(x);
        int cnt=0;
        while(!size.empty() && !greed.empty()) {
            if(size.top()>= greed.top()) {
                cnt++;
                size.pop();
            }
            greed.pop();
        }
        return cnt;
    }
};