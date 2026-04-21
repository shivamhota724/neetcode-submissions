class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(n>m) return "";
        vector<int> freq(128,0); //because too many characters
        for(char c : t) freq[c]++;
        int count = n;
        int start = 0;
        int minL = INT_MAX;
        int l = 0; 
        int r = 0;
        while(r<m){
            if(freq[s[r]]>0) count--;
            freq[s[r]]--;
            r++;
            while(count == 0){
                if(r-l < minL){
                minL = (minL,r-l);
                start = l;
                }
                freq[s[l]]++;
                if(freq[s[l]]> 0) count++;
                l++;
            }
        }
        return (minL == INT_MAX)? "" : s.substr(start,minL) ;
    }
};
