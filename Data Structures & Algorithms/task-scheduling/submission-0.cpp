class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(char c : tasks) mp[c]++;
        priority_queue<int> pq;
        for(auto &p : mp) pq.push(p.second);
        int ans = 0;
        while(!pq.empty()){
            int cnt = 0;
            vector<int> freq;
            for(int i = 0;i < (n+1) && !pq.empty();i++){
                int task = pq.top();
                pq.pop();
                cnt++;
                task--;
                if(task > 0) freq.push_back(task);
            }
            for(int f : freq) pq.push(f);
            if(!pq.empty()) ans += n+1;
            else ans += cnt++;
        }
        return ans;
    }
};
