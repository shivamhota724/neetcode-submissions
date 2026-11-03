class Solution {
public:
    vector<int> dp;
    int dfs(vector<int>& cost, int i){
        int n = cost.size();

        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int take1 = cost[i] + dfs(cost,i+1);
        int take2 = cost[i] + dfs(cost,i+2);

        return dp[i] = min(take1,take2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp.assign(n+1,-1);
        return min(dfs(cost,0), dfs(cost, 1));
    }
};