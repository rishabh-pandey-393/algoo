class Solution {
public:
    int mx=0;
    int f(int i,vector<vector<int>>&adj,vector<int>&informTime){
        int lmax=0;
        for(auto it:adj[i]) {
            int l=informTime[it];
            l+=f(it,adj,informTime);
            lmax=max(l,lmax);
        }
        mx=max(mx,lmax);
        return lmax;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>>adj(n);
        int x;
        for(int i=0;i<n;i++) if(manager[i]!=-1) adj[manager[i]].push_back(i);
        f(headID,adj,informTime);
        return mx+informTime[headID];
    }
};