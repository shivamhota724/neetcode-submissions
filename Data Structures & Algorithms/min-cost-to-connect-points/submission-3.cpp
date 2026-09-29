class Solution {
public:
    int PrismAlgo(vector<vector<pair<int,int>>>adj, int n){
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,greater<pair<int,int>>> pq;

        pq.push({0,0});
        vector<bool>vis(n, false);
        int count = 0;
        int totalcost = 0;

        while(count < n){
            auto [cost, node] = pq.top();
            pq.pop();

            if(vis[node]) continue;
            vis[node] = true;
            count++;
            totalcost += cost;

            for(auto it : adj[node]){
                int neighbour = it.first;
                int cost = it.second;

                if(!vis[neighbour])
                pq.push({cost, neighbour});
            }
        }
        return totalcost;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int,int>>>adj(n);
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int x1 = points[i][0];
                int x2 = points[j][0];
                int y1 = points[i][1];
                int y2 = points[j][1];
                int d = abs(x1 - x2) + abs(y1 - y2);

                adj[i].push_back({j,d});
                adj[j].push_back({i,d});
            }
        }
        return PrismAlgo(adj,n);
    }
};
