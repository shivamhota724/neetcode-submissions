class Solution {
public:
    vector<vector<int>>result;
    vector<int>temp;
    unordered_set<int>st;
    void check(vector<int>&nums){
        if(temp.size() == nums.size()){
            result.push_back(temp);
            return;
        }
        for(int i = 0;i < nums.size();i ++){
            if(st.find(nums[i]) == st.end()){
                temp.push_back(nums[i]);
                st.insert(nums[i]);
                check(nums);
                temp.pop_back();
                st.erase(nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        check(nums);
        return result;
    }
};
