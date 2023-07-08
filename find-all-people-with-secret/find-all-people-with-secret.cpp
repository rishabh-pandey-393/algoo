class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        int sz=meetings.size();
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<sz;i++){
            adj[meetings[i][0]].push_back({meetings[i][1],meetings[i][2]});
            adj[meetings[i][1]].push_back({meetings[i][0],meetings[i][2]});
        }
        vector<int>vis(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        vector<int>ans;
        pq.push({0,0});
        pq.push({0,firstPerson});
        while(!pq.empty()){
            auto tp=pq.top();
            pq.pop();
            int t=tp.first;
            int p=tp.second;
            vis[p]=1;
            for(auto node:adj[p]){
                if(node.second>=t && !vis[node.first]) pq.push({node.second,node.first});
            }
        }
        for(int i=0;i<n;i++) if(vis[i]==1) ans.push_back(i);
        return ans;
    }
};