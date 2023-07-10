class Solution {
public:
    long long minimumRemoval(vector<int>& b) {
        int n=b.size();
        sort(b.begin(),b.end());
        long long t=accumulate(b.begin(),b.end(),0ll),ans=LONG_MAX;
        long long pre=0;
        for(int i=0;i<n;i++){
            t-=b[i];
            ans=min(ans,t-1ll*(n-i-1)*b[i]+pre);
            pre+=b[i];
        }
        return ans;
    }
};