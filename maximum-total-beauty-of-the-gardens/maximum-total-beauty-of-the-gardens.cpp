class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        long long n=flowers.size();
        sort(flowers.begin(),flowers.end());
        vector<long long>pre(n,flowers[0]);
        for(int i=1;i<n;i++) pre[i]=pre[i-1]+flowers[i];
        long long ans=0;
        for(int i=n-1;i>=0;i--){
            long long lo=flowers[0],hi=target-1,f=(n-1-i)*full,h=0;
            while(lo<=hi){
                long long mid=lo+(hi-lo)/2;
                long long ind=lower_bound(flowers.begin(),flowers.end(),mid)-flowers.begin();
                long long x=0;
                if(ind>0) x=pre[ind-1];
                if(newFlowers>=(ind*mid)-x) {
                    lo=mid+1;
                    h=mid*partial;
                }
                else hi=mid-1;
            }
            ans=max(ans,h+f);
            if(newFlowers>=target-flowers[i]) newFlowers-=(max(0,target-flowers[i]));
            else return ans;
            flowers.pop_back();
        }
        if(newFlowers>=0) ans=max(ans,1ll*n*full);
        return ans;
    }
};