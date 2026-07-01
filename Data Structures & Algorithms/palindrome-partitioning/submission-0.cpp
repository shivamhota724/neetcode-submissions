class Solution {
public:
    vector<vector<string>>result;
    vector<string> temp;
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size()-1;
        while(l<r){
            if(tolower(s[l]) != tolower(s[r]))
                return false;
            l++;
            r--;
        }
        return true;
    }
    void check(string s, int k){
        if(k == s.size()){
            result.push_back(temp);
            return;
        } 
        for(int i = k; i < s.size(); i++){
            string curr = s.substr(k, i - k + 1);
            if(isPalindrome(curr)) {
                temp.push_back(curr);
                check(s,i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        check(s,0);
        return result;
    }
};
