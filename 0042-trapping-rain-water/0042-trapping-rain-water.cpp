class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();
        int l=0,r=n-1;
        int lmax=0,rmax=0;
        int water = 0;
        while(l<r) {
            lmax = max(lmax,a[l]);
            rmax = max(rmax,a[r]);
            if(a[l]<=a[r]) {
                water+= min(lmax,rmax) - a[l];
                l++;
            }
            else {
                water+= min(lmax,rmax) - a[r];
                r--;
            }
        }
        return water;
    }
};