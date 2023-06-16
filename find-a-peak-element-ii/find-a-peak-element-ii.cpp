class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size(),lo=0,hi=n-1;
        while(lo<=hi){
            int mid=(lo+hi)/2,ind,mx=INT_MIN;
            for(int i=0;i<m;i++){
                if(matrix[i][mid]>mx){
                    mx=matrix[i][mid];
                    ind=i;
                }
            }
            if((mid==0 or matrix[ind][mid-1]<matrix[ind][mid]) && (mid==n-1 or matrix[ind][mid+1]<matrix[ind][mid])) return {ind,mid};
            else if(mid==0 or matrix[ind][mid-1]<matrix[ind][mid]) lo=mid+1;
            else hi=mid-1;
        }
        return {-1,-1};
    }
};