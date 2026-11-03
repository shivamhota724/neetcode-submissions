class Solution {
public:
    vector<int> dp;
    int dfs(vector<int>& nums, int i){

        if(i >= nums.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int take2 = nums[i] + dfs(nums,i+2);
        int take3 = nums[i] + dfs(nums,i+3);

        return dp[i] = max(take2, take3);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        dp.assign(n+1, -1);

        return max(dfs(nums, 0), dfs(nums, 1));
    }
};
