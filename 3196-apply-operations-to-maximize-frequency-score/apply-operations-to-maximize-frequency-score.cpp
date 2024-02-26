class Solution {
public:
    int maxFrequencyScore(vector<int>& A, long long k) {
        sort(A.begin(), A.end());
        int n = A.size();
        vector<long long> pre(n + 1, 0);
        
        for(int i = 0; i < n; i++) pre[i + 1] = pre[i] + A[i];
        
        function<bool(int)> isPossible = [&](int mid) -> bool {
            for(int i = mid; i <= n; i++) {
                long long med1 = (i + (i - mid)) >> 1;
                long long med2 = ((i - 1) + (i - mid)) >> 1;
                long long diff = (pre[i] - pre[med1]) - (pre[med2 + 1] - pre[i - mid]);
                
                if(diff <= k) return true;
            }
            
            return false;
        };

        int lo = 1, hi = n;
        while(lo <= hi) {
            int mid = lo + hi >> 1;
            
            if(isPossible(mid)) lo = mid + 1;
            else hi = mid - 1;
        }
        
        return hi;
    }
};