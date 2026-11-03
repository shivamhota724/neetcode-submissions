class Solution {
public:
    vector<int> dp;
    void dfs(int n){
        if(n == 0 || n == 1){
            dp[n] = 1;
            return;
        } 

        if(dp[n] != -1) return;

        dfs(n-1);
        dfs(n-2);

        dp[n] = dp[n-1] + dp[n-2];
    }
    int climbStairs(int n) {
        
        dp.assign(n+1,-1);
        dfs(n);
        return dp[n];
    }
};