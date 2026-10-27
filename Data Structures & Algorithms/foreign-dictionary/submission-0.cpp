class Solution {
public:
    string s;
    bool dfs(vector<vector<int>>& adj, int v, vector<int>& vis){
        if(vis[v] == 1) return false;
        if(vis[v] == 2) return true;

        vis[v] = 1;
        for(int u : adj[v]){
            if(!dfs(adj,u,vis))
            return false;
        }
        vis[v] = 2;
        s += char(v + 'a');
        return true;
    }
    string foreignDictionary(vector<string>& words) {

        vector<vector<int>>adj(26);
        vector<int>vis(26,0);
        vector<bool> present(26, false);

        for (string& word : words) {
            for (char c : word)
                present[c - 'a'] = true;
        }

        for(int i = 0; i < words.size() - 1; i++){
            string s1 = words[i];
            string s2 = words[i + 1];

            int l = min(s1.size(),s2.size());
            bool found = false;

            for(int j = 0; j < l; j++){
                if(s1[j] != s2[j]){
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    found = true;
                    break;    
                }
            }
            if (!found && s1.size() > s2.size())
            return "";
        }
        s = "";
        for (int i = 0; i < 26; i++) {
            if (present[i] && vis[i] == 0) {
                if (!dfs(adj, i, vis))
                    return "";
            }
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
