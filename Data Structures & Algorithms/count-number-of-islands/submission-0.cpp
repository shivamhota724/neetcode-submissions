class Solution {
public:
    int count = 0;
    void IsLand(vector<vector<char>>& grid, int i, int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
        return;
        if(grid[i][j] == '0')
        return;
        grid[i][j] = '0';
        IsLand(grid,i+1,j);
        IsLand(grid,i-1,j);
        IsLand(grid,i,j+1);
        IsLand(grid,i,j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == '1'){
                    count++;
                    IsLand(grid,i,j);
                }
            }
        }
        return count;
    }
};
