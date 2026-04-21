class Solution {
public:

    string encode(vector<string>& strs) {
        string result;
        for(string s : strs){
            result += to_string(s.size()) + '#' + s; 
        }
        return result;
    }

    vector<string> decode(string s) {
        int i = 0;
        vector<string> v;
        while(i<s.size()){
            int j = i;
            while(s[j] != '#')
            j++;

            int l = stoi(s.substr(i,j-i));
            string w = s.substr(j+1,l);
            v.push_back(w);
            i = j + 1 + l;
        }
        return v;
    }
};
