class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int l=0,r=0,cnt=0;
        int freq[256] = {0};
        int sindex = 0;
        int size = 1e9;
        for(char c:t) freq[c]++;
        while(r<n) {
            freq[s[r]]--;
            if(freq[s[r]]>=0) cnt++;
            while(l<=r && cnt==t.size()) {
                if(r-l+1<size) {
                    sindex = l;
                    size = r-l+1;
                }
                freq[s[l]]++;
                if(freq[s[l]]>0) cnt--;
                l++;
            }
            r++;
        }
        cout<<l<<" "<<size<<endl;
        return size==1e9 ? "" : s.substr(sindex,size);
    }
};