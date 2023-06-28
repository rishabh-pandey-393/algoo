class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<double,double>>pq;
        vector<double>v(n,0);
        v[start]=1;
        pq.push({v[start],start});
        while(!pq.empty()){
            double node =pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                if(v[it.first]<v[node]*it.second){
                    v[it.first]=v[node]*it.second;
                    pq.push({v[it.first],it.first});
                }
            }
        }
        return v[end];
    }
};