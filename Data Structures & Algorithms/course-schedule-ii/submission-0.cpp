class Solution {
public:
    vector<int> ans;
    bool dfs(vector<vector<int>>& adj, vector<int>& vis, int u){

        if(vis[u] == 1) return true;
        if(vis[u] == 0) return false;

        vis[u] = 0;

        for(int v : adj[u]){
            if(!dfs(adj,vis,v)) return false;
        }
        ans.push_back(u);
        vis[u] = 1;
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> vis(numCourses, -1);

        vector<vector<int>>adj(numCourses);
        for(auto& it : prerequisites){
            adj[it[0]].push_back(it[1]);
        }

        for(int i = 0; i < numCourses; i++){
                if(!dfs(adj,vis,i)) return {};
        }
        return ans;
    }
};
