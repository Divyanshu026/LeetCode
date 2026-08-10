class Solution {
public:
    int maxProduct(int n) {
        priority_queue<int> pq;
        while(n!=0) {
            int x  = n%10;
            pq.push(x);
            n = n/10;
        }
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        return first*second;
    }
};