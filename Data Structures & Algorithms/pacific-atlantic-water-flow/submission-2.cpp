class Solution {
public:
    int n;
    int m;
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    void DFS(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& visited, int prev){
        if(i < 0 || j < 0 || i >= n || j >= m){
            return;
        }
        if(heights[i][j] < prev || visited[i][j]){
            return;
        }
        visited[i][j] = true;
        for(auto& it : dir){
            int i_ = i + it[0];
            int j_ = j + it[1];

            DFS(heights, i_, j_, visited, heights[i][j]);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();

        vector<vector<int>>result;

        vector<vector<bool>> Pacific(n, vector<bool>(m, false));
        vector<vector<bool>> Atlantic(n, vector<bool>(m, false));

        for(int j = 0; j < m; j++){
            DFS(heights, 0, j, Pacific, INT_MIN);
            DFS(heights, n - 1, j, Atlantic, INT_MIN);
        }
        for(int i = 0; i < n; i++){
            DFS(heights, i, 0, Pacific, INT_MIN);
            DFS(heights, i, m - 1, Atlantic, INT_MIN);
        }
        for(int j = 0; j < m; j++){
            for(int i = 0; i < n; i++){
                if(Pacific[i][j] && Atlantic[i][j])
                result.push_back({i,j});
            }
        }
        return result;
    }
};
