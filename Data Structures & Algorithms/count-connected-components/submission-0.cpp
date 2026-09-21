class Solution {
public:
    int components = 0;
    void dfs(vector<vector<int>>& adj, vector<int>& vis, int u){
        if(vis[u]) return;

        vis[u] = 1;
        for(int v : adj[u]){
            dfs(adj,vis,v);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>>adj(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n,0);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(adj,vis,i);
                components++;
            }
        }
        return components;
    }
};
