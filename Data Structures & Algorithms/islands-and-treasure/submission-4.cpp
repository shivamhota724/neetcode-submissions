class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        for(int i = 0;i < m; i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0)
                q.push({i,j});
            }
        }
        vector<pair<int,int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            for(auto [dr, dc] : dir){
                int a = r + dr;
                int b = c + dc;

                if(a < 0 || b < 0 || a >= m || b >= n)
                continue;
                if(grid[a][b] != 2147483647)
                continue;
                grid[a][b] = grid[r][c] + 1;
                q.push({a,b});
            }
        }
    }
};
