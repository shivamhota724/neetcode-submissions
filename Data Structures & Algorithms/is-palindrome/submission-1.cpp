class Solution {
public:
    bool isPalindrome(string s) {
        string t = "";
        string u = "";
        for(int i=0;i<s.size();i++){
            if(isalnum(s[i]))
                t.push_back(tolower(s[i]));
        }
        for(int i=s.size()-1;i>=0;i--){
            if(isalnum(s[i]))
                u.push_back(tolower(s[i]));
        }
        if(t==u)
            return true;
        return false;
    }
};
