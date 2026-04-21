class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map < int, int > mp;
        for(int i = 0;i < nums.size(); i++){
            mp[nums[i]]++;
        }
        vector <pair<int,int>> v;
            for(auto &p : mp){
                v.push_back({p.second,p.first});
        }
        sort(v.begin(), v.end(), greater<pair<int,int>>());
        vector<int> result;
        for(int i=0;i<k;i++){
            result.push_back(v[i].second);
        }
        return result;
    }
};
