class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int m = 0;
        int i = 0;
        int j = 0;
        unordered_set<char> st;
        while(i<s.size()){

            if(st.find(s[i]) != st.end()){
                st.erase(s[j]);
                j++;
            }
            else{
                st.insert(s[i]);
                m = max(m,int(st.size()));
                i++;
            }
        }
        return m;
    }
};
