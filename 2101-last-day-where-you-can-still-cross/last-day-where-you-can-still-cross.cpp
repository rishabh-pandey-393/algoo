class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector M(row + 1, vector<int>(col + 1, 0));
        vector<int> dir = {1, 0, -1, 0, 1};
        
        function<bool(int , int)> dfs = [&](int i, int j) -> bool {
            if(i < 1 || i > row || j < 1 || j > col || M[i][j] == 1) return false;
            if(i == row) return true;
            
            M[i][j] = 1;
            
            for(int k = 0; k < 4; k++) {
                if(dfs(i + dir[k], j + dir[k + 1])) return true;
            }
            
            return false;
        };
        
        function<bool(int)> canCross = [&](int mid) -> bool {
            for(int i = 0; i < mid; i++) M[cells[i][0]][cells[i][1]] = 1;
            
            bool res = false;
            for(int j = 1; j <= col; j++) if(dfs(1, j)) {
                res = true;
                break;
            }
            
            for(int i = 1; i <= row; i++) {
                for(int j = 1; j <= col; j++) M[i][j] = 0;
            }
            
            return res;
        };
        
        int lo = 1, hi = row * col;
        while(lo <= hi) {
            int mid = lo + hi >> 1;
            
            if(canCross(mid)) lo = mid + 1;
            else hi = mid - 1;
        }
        
        return hi;
    }
};