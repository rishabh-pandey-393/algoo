class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        long long ans=0,n=costs.size();
        map<int,int>mp;
        for(int i=0;i<n;i++) ans+=costs[i][0];
        vector<int>v;
        for(int i=0;i<n;i++) v.push_back(costs[i][1]-costs[i][0]);
        sort(v.begin(),v.end());
        for(int i=0;i<n/2;i++){
            ans+=v[i];
        }
        return ans;
    }
};