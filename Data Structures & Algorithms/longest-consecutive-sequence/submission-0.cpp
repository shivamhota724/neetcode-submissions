class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        int cnt = 1;
        int prev = INT_MIN;
        int zero = 0;
        for(int x : st){
            if(x == prev+1){
                cnt++;
            }
            else cnt = 1;
            zero = max(zero,cnt);
             prev = x;
        }
        return zero;
    }
};
