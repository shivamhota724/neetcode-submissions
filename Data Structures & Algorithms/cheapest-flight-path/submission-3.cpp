class Solution {
public:
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>> adj(n);
        for(auto f : flights){
            adj[f[0]].push_back({f[1],f[2]});
        }
        queue<tuple<int,int,int>> q;
        q.push({src,0,0});

        vector<int>dist(n, INT_MAX);
        dist[src] = 0;

        while(!q.empty()){
            auto [city, cost, stop] = q.front();
            q.pop();

            if(stop == k + 1) continue;

            for(auto [next, price] : adj[city]){

                int newcost = cost + price;

                if(dist[next] > newcost){
                    dist[next] = newcost;
                    q.push({next, newcost, stop+1});
                }
                
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
