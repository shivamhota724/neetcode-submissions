class Solution {
public:
    vector<int> edge;
    bool dfs(vector<vector<int>>& adj, vector<int>& vis, int u, int target){
        if(u == target) return true;
        vis[u] = 1;
        for(int v : adj[u]){
            if(!vis[v] && dfs(adj,vis,v,target))
            return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        vector<vector<int>> adj(n);
        vector<int>vis(n,0);
        for(auto it : edges){
            int i = it[0];
            int j = it[1];

            fill(vis.begin(), vis.end(), 0);

            if(dfs(adj,vis,i,j)) return it;

            adj[i].push_back(j);
            adj[j].push_back(i);
        }
        return {};
    }
};
