class Solution {
public:
    vector<string>ans;
    unordered_map<string, vector<string>>adj;
    void dfs(string s){
        while(!adj[s].empty()){
            string next = adj[s].back();
            adj[s].pop_back();
            dfs(next);
        }
        ans.push_back(s);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        for(auto& it : tickets){
            adj[it[0]].push_back(it[1]);
        }
        for(auto& it : adj){
            sort(it.second.rbegin(), it.second.rend());
        }
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
