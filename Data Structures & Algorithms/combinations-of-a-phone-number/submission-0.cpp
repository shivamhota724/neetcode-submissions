class Solution {
public:
    vector<string> result;
    void check(string& digits, int k, vector<string>& mp, string& temp){
        if(k == digits.size()){
            result.push_back(temp);
            return;
        }
        int digit = digits[k] - '0';
        string letters = mp[digit];
        for(char c : letters){
            temp.push_back(c);
            check(digits, k+1, mp, temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> mp = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(digits.empty())
        return {};
        string temp;
        check(digits,0,mp,temp);
        return result;
    }
};
