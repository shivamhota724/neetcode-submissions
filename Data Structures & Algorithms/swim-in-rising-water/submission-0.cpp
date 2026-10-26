class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        pq.push({grid[0][0],0,0});

        vector<vector<bool>> vis(n,vector<bool>(n, false));
        vector<pair<int,int>>dir{{1,0},{-1,0},{0,1},{0,-1}};

        while(!pq.empty()){
            auto [cost, i, j] = pq.top();
            pq.pop();
            
            if(i == n-1 && j == n-1) return cost;

            if(vis[i][j]) continue;
            vis[i][j] = true;

            for(auto [r,c] : dir){
                int _i = i + r;
                int _j = j + c;

                if(_i < 0 || _i >= n || _j < 0 || _j >= n) continue;
                if(vis[_i][_j]) continue;

                int newcost = max(cost, grid[_i][_j]);

                pq.push({newcost, _i, _j});
            }
        }
        return -1;
    }
};
