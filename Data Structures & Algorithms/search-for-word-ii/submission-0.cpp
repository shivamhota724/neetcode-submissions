class TrieNode{
    public:
    TrieNode* children[26];
    bool IsEnd;
    string word;

    TrieNode(){
        for(int i=0;i<26;i++)
            children[i] = nullptr;

            IsEnd = false;
            word = "";
    }
};
class Solution {
public:
    vector<string> result;
    int row;
    int col;
    TrieNode* root = new TrieNode();
    void insert(string& word){
        TrieNode* node = root;
        for(char c : word){
            if(node->children[c - 'a'] == nullptr)
            node->children[c - 'a'] = new TrieNode();
            node = node->children[c - 'a'];
        }
        node->IsEnd = true;
        node->word = word;
    }
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node){
        if(i >= row || i < 0 || j >= col || j < 0) return;
        char c = board[i][j];
        if(c == '#') return;
        if(node->children[c - 'a'] == nullptr)return;
        node = node->children[c - 'a'];
        if(node->IsEnd){
            result.push_back(node->word);
            node->IsEnd = false;
        } 
        board[i][j] = '#';
        dfs(board,i+1,j,node);
        dfs(board,i-1,j,node);
        dfs(board,i,j+1,node);
        dfs(board,i,j-1,node);
        board[i][j] = c;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    row = board.size();
    col = board[0].size();
        for(string& word : words){
            insert(word);
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                dfs(board,i,j,root);
            }
        }
        return result;
    }
};
