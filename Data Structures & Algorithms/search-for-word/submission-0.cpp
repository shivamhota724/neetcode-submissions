class Solution {
public:
    int m;
    int n;
    bool find(int i, int j, int k, vector<vector<char>>& board, string& word){
        m = board.size();
        n = board[0].size();
        if(k == word.size())
        return true;
        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[k])
        return false;
            char temp = board[i][j];
            board[i][j] = '@';
            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};
            for(int a = 0; a < 4; a++) {
                if(find(i + dr[a], j + dc[a],k + 1, board, word)){
                    board[i][j] = temp;
                    return true;
                }
            }
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                if(board[i][j] == word[0]){
                    if(find(i,j,0,board,word))
                    return true;
                }
            }
        }
        return false;
    }
};
