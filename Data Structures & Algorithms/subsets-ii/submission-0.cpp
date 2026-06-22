class Solution {
public:
    vector<int>temp;
    vector<vector<int>>result;
    void check(int i, vector<int>&nums){
        result.push_back(temp);
        for(int j = i; j < nums.size(); j++){
            if(j > i && nums[j] == nums[j-1])
            continue;
            temp.push_back(nums[j]);
            check(j+1, nums);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        check(0, nums);
        return result;
    }
};
