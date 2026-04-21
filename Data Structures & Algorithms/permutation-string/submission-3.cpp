class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if(n>m) return false;
        vector<int> frq1(26,0);
        vector<int> frq2(26,0);
        for(char &ch : s1){
            frq1[ch - 'a']++;
        }
        int l = 0;
        int r = 0;
        while(r<m){
            frq2[s2[r] - 'a']++;
            if((r-l+1 )> n){
                frq2[s2[l] - 'a']--;
                l++;
            }
            if(frq1 == frq2) return true;
            r++;
        }
        return false;
    }
};
