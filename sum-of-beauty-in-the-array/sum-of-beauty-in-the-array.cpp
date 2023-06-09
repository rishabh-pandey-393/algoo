class Solution {
public:
    int sumOfBeauties(vector<int>& A) {
        int n=A.size(),left=A[0],ans=0;
        vector<int>right(n,A[n-1]);
        for (int i=n-2;i>0;--i) right[i]=min(right[i+1],A[i]);
        for (int i=1;i<n-1;++i) {
            if(A[i]>left && A[i]<right[i+1]) ans+=2;
            else if(A[i]>A[i-1] && A[i]<A[i+1]) ans++;
            left=max(left, A[i]);
        }
        return ans;
    }
};