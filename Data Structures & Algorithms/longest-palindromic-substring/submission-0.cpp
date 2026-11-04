class Solution {
public:
    int start = 0; 
    int maxlen = 0;
    void expand(string s, int l, int r){
          while(l >= 0 && r < s.size() && s[l] == s[r]){
            if(r - l + 1 > maxlen){
                start = l;
                maxlen = r - l + 1;
            }
            l--;
            r++;
        }
    }
    string longestPalindrome(string s) {
        for(int i = 0; i < s.size(); i++){
            int l = i;
            int r = i;
            expand(s,l,r);
            l = i;
            r = i + 1;
            expand(s,l,r);
        }
        return s.substr(start, maxlen);
    }
};