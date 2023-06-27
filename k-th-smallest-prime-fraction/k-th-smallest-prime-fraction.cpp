class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double,pair<int,int>>> pq;
        int n = arr.size();
        for(int i = 0 ; i < n ; i++){
            for(int j=n-1;j>=i+1;j--){
                
                if(pq.size() < k){
                    pq.push({(double)arr[i]/arr[j] , {arr[i],arr[j]}});
                }
                else if(pq.top().first > (double)arr[i]/arr[j]){
                    pq.pop();
                    pq.push({(double)arr[i]/arr[j],{arr[i],arr[j]}});
                }
                else break;
            }
        }
        return {pq.top().second.first,pq.top().second.second};
    }
};