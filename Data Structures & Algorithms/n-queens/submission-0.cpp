class Solution {
public:
    vector<vector<string>> result;
    vector<string> board;
    bool isSafe(int n, int row, int col){
        for(int i=row-1;i>=0;i--){
            if(board[i][col] == 'Q') return false;
        }
        int i = row-1;
        int j = col+1;
        while(i >= 0 && j < n){
                if(board[i][j] == 'Q') return false;
                i--;
                j++;
            }
        i = row-1;
        j = col-1;
        while(i >= 0 && j >= 0){
                if(board[i][j] == 'Q') return false;
                i--;
                j--;
            }
        return true;
    }
    void check(int n, int row){
        if(row == n){
            result.push_back(board);
            return;
        }
         for(int col = 0;col<n;col++){
            if(isSafe(n, row, col)){
                board[row][col] = 'Q';
                check(n,row+1);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        board = vector<string>(n,string(n,'.'));
        check(n,0);
        return result;
    }
};
