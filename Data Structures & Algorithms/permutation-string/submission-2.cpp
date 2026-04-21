class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l = 0;
        int r = l + s1.size() - 1;
        sort(s1.begin(),s1.end());
        while(r<s2.size()){
            string sub2 = s2.substr(l,r-l+1);
            sort(sub2.begin(),sub2.end());
            if(s1 == sub2) return true;
            else 
            l++;
            r++;
        }
        return false;
    }
};
