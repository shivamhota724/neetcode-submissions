class Solution {
public:
    vector<vector<int>>result;
    void check(int i,int target,vector<int>&candidates,vector<int>&temp){
        if(target < 0) return;
        if(target == 0){
            result.push_back(temp);
            return;
        }
        for(int j = i; j < candidates.size(); j++){
            if(j > i && candidates[j] == candidates[j-1])
            continue;
        temp.push_back(candidates[j]);
        check(j+1,target-candidates[j],candidates,temp);
        temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        check(0,target,candidates,temp);
        return result;
    }
};
