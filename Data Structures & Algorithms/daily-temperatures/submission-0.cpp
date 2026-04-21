class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(),0);
        stack<int> st;
        int n = temperatures.size();
        for(int i=n-1;i>=0;i--){

            while(!st.empty() && temperatures[st.top()] <= temperatures[i])
            st.pop();

            if(st.empty()) ans[i] = 0;

            else ans[i] = st.top() - i;

            st.push(i);
        }

        return ans;
    }
};
