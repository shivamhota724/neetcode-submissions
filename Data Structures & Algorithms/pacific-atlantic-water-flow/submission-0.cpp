class Solution {
public:
    void dfs(vector<vector<int>>& heights, int i, int j,
             vector<vector<bool>>& vis) {

        int m = heights.size();
        int n = heights[0].size();

        vis[i][j] = true;

        vector<pair<int,int>> dir = {
            {1,0},{-1,0},{0,1},{0,-1}
        };

        for(auto [dr,dc] : dir){

            int nr = i + dr;
            int nc = j + dc;

            if(nr < 0 || nc < 0 || nr >= m || nc >= n)
                continue;

            if(vis[nr][nc])
                continue;

            // Reverse flow
            if(heights[nr][nc] < heights[i][j])
                continue;

            dfs(heights,nr,nc,vis);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n,false));
        vector<vector<bool>> atlantic(m, vector<bool>(n,false));

        // Pacific
        for(int i=0;i<m;i++)
            dfs(heights,i,0,pacific);

        for(int j=0;j<n;j++)
            dfs(heights,0,j,pacific);

        // Atlantic
        for(int i=0;i<m;i++)
            dfs(heights,i,n-1,atlantic);

        for(int j=0;j<n;j++)
            dfs(heights,m-1,j,atlantic);

        vector<vector<int>> ans;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i,j});
            }
        }

        return ans;
    }
};