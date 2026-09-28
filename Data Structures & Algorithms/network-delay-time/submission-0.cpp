class Solution {
public:
    void dfs(vector<vector<pair<int,int>>>& adj, vector<int>& dist, int u, int time){

        if(time >= dist[u]) return;
        dist[u] = time; 

        for(auto [v,t] : adj[u]){
            dfs(adj,dist,v,time+t);
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i = 0; i < times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int t = times[i][2];
            adj[u].push_back({v,t});
        }
        
        vector<int> dist(n + 1, INT_MAX);

        dfs(adj,dist,k,0);

        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
