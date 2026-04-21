class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l = 0;
        int r = l + s1.size() - 1;
        multiset<char>st1(s1.begin(),s1.end());
        while(r<s2.size()){
            multiset<char>st2(s2.begin()+l,s2.begin()+r+1);
            if(st2 != st1){
            l++;
            r++;
            }
            else
            return true;
        }
        return false;
    }
};
