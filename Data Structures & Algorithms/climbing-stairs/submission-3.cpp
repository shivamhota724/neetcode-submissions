class Solution {
public:
    vector<int> dp;
    int dfs(int n){
        if(n == 0 || n == 1) return 1;

        if(dp[n] != -1) return dp[n];

        return dp[n] = dfs(n-1) + dfs(n-2);
    }
    int climbStairs(int n) {
        dp.assign(n+1, -1);
        return dfs(n);
    }
};
