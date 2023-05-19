class Solution {
public:
    bool x=true;
    void f(vector<vector<int>>& graph,int i,vector<int>&vis){
        if(!x) return;
        if(vis[i]==-1) vis[i]=1;
        for(int j=0;j<graph[i].size();j++){
            if(vis[graph[i][j]]==-1) {
                vis[graph[i][j]]=1-vis[i];
                f(graph,graph[i][j],vis);
            }
            else if(vis[graph[i][j]]==vis[i]) x=false;
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n);
        for(int i=0;i<n;i++) vis[i]=-1;
        for(int i=0;i<n;i++) if(vis[i]==-1) f(graph,i,vis);
        return x;
    }
};