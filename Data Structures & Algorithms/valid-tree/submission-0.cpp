class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<bool>& vis, int u, int parent){
        if(vis[u]) return false;

        vis[u] = true;
        for(int v : adj[u]){
            if(v == parent) continue;
            if(!dfs(adj,vis,v,u)) return false;
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {

        if(edges.size() != n-1) return false;

        vector<bool> vis(n,false);
        vector<vector<int>> adj(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        if(!dfs(adj,vis,0,-1)) return false;
        for(int i = 0; i < n; i++){
            if(!vis[i]) return false;
        }
        return true;
    }
};
