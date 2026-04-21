class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map < int, int > mp;
        for(int i = 0;i < nums.size(); i++){
            mp[nums[i]]++;
        }
        vector <int> v;
        for(int i =0;i<k;i++){
            int maxFreq = 0;
            int maxKey  = 0;
            for(auto &p : mp){
            if(p.second > maxFreq) {
                maxFreq = p.second;
                maxKey = p.first;
            }
        }
        v.push_back(maxKey);
            mp.erase(maxKey);
        }
        return v;
    }
};
