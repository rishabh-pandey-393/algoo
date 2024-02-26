class Solution {
public:
    int maxFrequencyScore(vector<int>& A, long long k) {
        sort(A.begin(), A.end());
        int n = A.size();
        vector<long long> pre(n + 1, 0);
        
        for(int i = 0; i < n; i++) pre[i + 1] = pre[i] + A[i];
        
        function<bool(int)> isPossible = [&](int mid) -> bool {
            for(int i = mid; i <= n; i++) {
                long long ind1 = ((i - 1) + (i - mid)) >> 1;
                long long ind2 = ((i - 1) + (i - mid) + 1) >> 1;

                long long diff1 = ((ind1 - (i - mid)) * A[ind1] - (pre[ind1] - pre[i - mid])) + ((pre[i] - pre[ind1]) - (i - ind1) * A[ind1]);
                long long diff2 = ((ind2 - (i - mid)) * A[ind2] - (pre[ind2] - pre[i - mid])) + ((pre[i] - pre[ind2]) - (i - ind2) * A[ind2]);
                
                if(diff1 <= k || diff2 <= k) return true;
            }
            
            return false;
        };
        // 1 2 4 6
        int lo = 1, hi = n;
        while(lo <= hi) {
            int mid = lo + hi >> 1;
            
            if(isPossible(mid)) lo = mid + 1;
            else hi = mid - 1;
        }
        
        return hi;
    }
};