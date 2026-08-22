class Solution {
public:
    bool checkDivisibility(int n) {
        int x = n;
        int sum = 0;
        int prod = 1;
        while(x!=0) {
            sum+=x%10;
            prod = prod*(x%10);
            x = x/10;
        }
        cout<<prod<<endl;
        return n%(sum+prod)==0;
    }
};