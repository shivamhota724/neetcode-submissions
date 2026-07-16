class TrieNode{
    public:
    TrieNode* children[26];
    bool IsEnd;

    TrieNode(){
        for(int i=0;i<26;i++){
            children[i] = nullptr;
            IsEnd = false; 
        }
    }
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode(); 
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for(char c : word){
            if(node->children[c - 'a'] == nullptr)
            node->children[c - 'a'] = new TrieNode();
            node = node->children[c - 'a'];
        }
        node->IsEnd = true;
    }
    bool find(TrieNode* root, string& word, int index){
        if(index == word.length())
        return root->IsEnd;
        char c = word[index];
        if(c == '.'){
            for(int i = 0;i<26;i++){
                if(root->children[i] && find(root->children[i],word,index+1))
                return true;
            }
            return false;
        }
        if(root->children[c - 'a'] == nullptr)
        return false;
        return find(root->children[c - 'a'],word,index+1);
    }
    bool search(string word) {
        return find(root,word,0);
    }
};
