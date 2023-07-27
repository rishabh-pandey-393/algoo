class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n=tasks.size(),t=0;
        vector<int>ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>free,used;
        for(int i=0;i<servers.size();i++) free.push({servers[i],i});
        for(int i=0;i<n;i++){
            t=max(t,i);
            if(free.empty() && used.top().first>t) t=used.top().first;
            while(used.size() && used.top().first<=t){
                pair<int,int>p=used.top();
                used.pop();
                free.push({servers[p.second],p.second});
            }
            pair<int,int>p=free.top();
            free.pop();
            ans.push_back(p.second);
            used.push({t+tasks[i],p.second});
        }
        return ans;
    }
};