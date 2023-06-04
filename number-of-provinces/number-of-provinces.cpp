class Solution {
public:
    int n,count=0;
    void dfs(vector<vector<int>>&adj,vector<int>&vis,int i){
        vis[i]=1;
        for(int j=0;j<adj[i].size();j++){
            if(!vis[adj[i][j]]) dfs(adj,vis,adj[i][j]);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n=isConnected.size();
        vector<int>vis(n);
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<isConnected[i].size();j++){
                if((i!=j) && (isConnected[i][j]==1)) adj[i].push_back(j);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i]) {
                dfs(adj,vis,i);
                count++;
            }
        }
        return count;
    }
};