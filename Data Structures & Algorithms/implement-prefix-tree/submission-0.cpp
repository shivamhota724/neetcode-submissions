class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        for(int i = 0; i < 26; i++)
            children[i] = nullptr;

        isEnd = false;
    }
};

class PrefixTree {
public:
    TrieNode* root;

    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(char c : word){
           
            if(node->children[c - 'a'] == nullptr)
            node->children[c - 'a'] = new TrieNode();

            node = node->children[c - 'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(char c : word){
           
            if(node->children[c - 'a'] == nullptr)
            return false;

            node = node->children[c - 'a'];
        }
        return node->isEnd == true;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(char c : prefix){
           
            if(node->children[c - 'a'] == nullptr)
            return false;

            node = node->children[c - 'a'];
        }
        return true;
    }
};
