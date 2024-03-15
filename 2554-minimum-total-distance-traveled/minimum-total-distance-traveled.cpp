class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size(), m = factory.size();
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        
        vector dp(n, vector<vector<long long>>(m, vector<long long>(n, -1)));
        
        function<long long(int, int, int)> f = [&](int i, int j, int fixed) -> long long {
            if(i == n) return 0;
            if(j == m) return 1e16;
            
            if(dp[i][j][fixed] != -1) return dp[i][j][fixed];
            
            long long notRepaired = f(i, j + 1, 0);
            long long repaired = 1e16;
            if(fixed < factory[j][1]) repaired = llabs(factory[j][0] - robot[i]) + f(i + 1, j, fixed + 1);
            
            return dp[i][j][fixed] = min(notRepaired, repaired);
        };
        
        return f(0, 0, 0);
    }
};