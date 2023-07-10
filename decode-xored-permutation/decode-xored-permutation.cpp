class Solution {
public:
    vector<int> decode(vector<int>& e) {
        int n=e.size(),xr=0;
        for(int i=1;i<=n+1;i++) xr^=i;
        for(int i=1;i<n;i+=2) xr^=e[i];
        vector<int>ans;
        ans.push_back(xr);
        for(int i=0;i<n;i++){
            xr^=e[i];
            ans.push_back(xr);
        }
        return ans;
    }
};