class Solution {
public:
    int search(vector<int>& A, int target) {
        int lo = 0, hi = A.size() - 1;

        while(lo <= hi) {
            int mid = lo + hi >> 1;

            if(A[mid] == target) return mid;

            if(A[mid] >= A[lo]) {
                if(target >= A[lo] && target <= A[mid]) hi = mid - 1;
                else lo = mid + 1;
            }
            else {
                if(target <= A[hi] && target >= A[mid]) lo = mid + 1;
                else hi = mid - 1;
            }
        }

        return -1;
    }
};