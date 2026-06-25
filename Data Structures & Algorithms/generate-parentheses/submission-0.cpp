class Solution {
public:
    vector<string> result;
    bool isvalid(string s){
        int balance = 0;
        for(char c : s){
            if(c == '(') balance++;
            else balance--;
            if(balance < 0) return false;
        }
        return balance == 0;
    }
    void rec(string s, int n){
        if(s.size() == 2*n){
            if(isvalid(s))
            result.push_back(s);
            return;
        }
        s.push_back('(');
        rec(s, n);
        s.pop_back();
        s.push_back(')');
        rec(s, n);
        s.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        rec("", n);
        return result;
    }
};
