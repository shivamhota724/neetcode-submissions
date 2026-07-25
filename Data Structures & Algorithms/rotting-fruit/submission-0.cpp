class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int minutes = 0;
        int fresh = 0;
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1)
                fresh++;
                if(grid[i][j] == 2)
                q.push({i,j});
            }
        }
        if(fresh == 0) return 0;
        vector<pair<int,int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            int size = q.size();
           for(int i = 0; i < size; i++){ 
                auto [r,c] = q.front();
                q.pop();
                for(auto [dr,dc] : dir){
                    int a = r + dr;
                    int b = c + dc;
                    if(a < 0 || b < 0 || a >= m || b >= n)
                    continue;
                    if(grid[a][b] != 1)
                    continue;
                    grid[a][b] = 2;
                    q.push({a,b});
                    fresh--;
                }
            }
            if(!q.empty()) minutes++;
        }
        if(fresh == 0)return minutes;
        else return -1;
    }
};
