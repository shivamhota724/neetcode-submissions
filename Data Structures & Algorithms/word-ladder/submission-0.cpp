class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string>st(wordList.begin(), wordList.end());
        if(!st.count(endWord)) return 0;

        queue<string>q;
        q.push(beginWord);

        int steps = 1;

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                string word = q.front();
                q.pop();

                if(word == endWord) return steps;

                for(int i = 0; i < word.size(); i++){

                    char og = word[i];

                    for(char ch = 'a'; ch <= 'z'; ch++){
                        word[i] = ch;

                        if(st.count(word)){
                            q.push(word);
                            st.erase(word);
                        }
                    }
                    word[i] = og;
                }
            }
            steps++;
        }
        return 0;
    }
};
