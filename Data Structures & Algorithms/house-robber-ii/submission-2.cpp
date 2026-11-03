class Solution {
public:
    vector<int> dp;
    int dfs(vector<int>& nums, int i, int end){
        
        if(i > end) return 0;

        if(dp[i] != -1) return dp[i];

        int take = nums[i] + dfs(nums, i+2, end);
        int skip = dfs(nums, i+1, end);

        return dp[i] = max(take, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        dp.assign(n+1, -1);
        int case1 = dfs(nums, 0, n-2);
        dp.assign(n+1, -1);
        int case2 = dfs(nums, 1, n-1);


        return max(case1, case2); 
    }
};
