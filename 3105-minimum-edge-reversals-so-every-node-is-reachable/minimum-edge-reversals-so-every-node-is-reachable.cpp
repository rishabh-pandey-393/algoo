class Solution {
public:
    int dfs(int s,int p,vector<vector<pair<int,int>>>&adj){
        int cnt=0;
        for(auto it:adj[s]){
            if(it.first==p) continue;
            if(it.second==1) cnt++;
            cnt+=dfs(it.first,s,adj);
        }
        return cnt;
    }
    void final(int s,int p,int flag,vector<vector<pair<int,int>>>&adj,vector<int>&ans){
        if(flag==0) ans[s]=ans[p]+1;
        else ans[s]=ans[p]-1;
        for(auto it:adj[s]) if(it.first!=p) final(it.first,s,it.second,adj,ans);
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],0});
            adj[edges[i][1]].push_back({edges[i][0],1});
        }
        vector<int>ans(n);
        ans[0]=dfs(0,-1,adj);
        for(auto it:adj[0]) final(it.first,0,it.second,adj,ans);
        return ans;
    }
};