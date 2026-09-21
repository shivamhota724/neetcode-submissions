class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<int>& vis, int u){

        if(vis[u] == 1) return true;
        if(vis[u] == 0) return false;

        vis[u] = 0;

        for(int v : adj[u]){
            if(!dfs(adj,vis,v)) return false;
        }

        vis[u] = 1;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> vis(numCourses, -1);

        vector<vector<int>>adj(numCourses);
        for(auto& it : prerequisites){
            adj[it[0]].push_back(it[1]);
        }

        for(int i = 0; i < numCourses; i++){
                if(!dfs(adj,vis,i)) return false;
        }
        return true;
    }
};
