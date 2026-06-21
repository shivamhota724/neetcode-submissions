class Solution {
public:
    vector<vector<int>> result;
    void check(int i, int target, vector<int>& nums,vector<int>& temp){
        if(target == 0){
            result.push_back(temp);
            return;
        }
        if(target < 0) return;
        if(i >= nums.size()) return;

        temp.push_back(nums[i]);
        check(i,target-nums[i],nums,temp);
        temp.pop_back();
        check(i+1,target,nums,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>temp;
        check(0,target,nums,temp);
        return result;
    }
};
