class Solution {
public:
    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& safe){
        int n = board.size();
        int m = board[0].size();

        if(i < 0 || i >= n || j < 0 || j >= m)
            return;

        if(board[i][j] == 'X' || safe[i][j])
            return;

        safe[i][j] = true;

        for(auto& [r,c] : dir){

            int _i = i + r;
            int _j = j + c;

            dfs(board, _i, _j, safe);
        }

    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> safe(n, vector<bool>(m, false));

        for(int i = 0; i < n; i++){
            dfs(board, i, 0, safe);
            dfs(board, i, m - 1, safe);
        }
        for(int j = 0; j < m; j++){
            dfs(board, 0, j, safe);
            dfs(board, n - 1, j, safe);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!safe[i][j] && board[i][j] != 'X'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
