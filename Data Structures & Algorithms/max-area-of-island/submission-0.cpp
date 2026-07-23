class Solution {
public:
    int count = 0;
    void IsLand(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
        return;
        if(grid[i][j] == 0)
        return;
        count++;
        grid[i][j] = 0;
        IsLand(grid,i+1,j);
        IsLand(grid,i-1,j);
        IsLand(grid,i,j+1);
        IsLand(grid,i,j-1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxcount = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    IsLand(grid,i,j);
                    maxcount = max(maxcount,count);
                    count = 0;
                }
            }
        }
        return maxcount;
    }
};
