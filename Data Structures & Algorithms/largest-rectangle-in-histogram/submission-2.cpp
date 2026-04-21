class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();
        int left = -1;
        int right = n;
        for(int i=0;i<=n;i++){
            int curr = (i==n) ? 0 : heights[i];
           while(!st.empty() && heights[st.top()] >= curr){
            int h = heights[st.top()];
            st.pop();
            left = st.empty()? -1 : st.top();
            right = i;
            maxArea = max(maxArea,h*(right - left - 1));
           }
            st.push(i);
        }
        return maxArea ;
    }
};
