class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int area = 0;
        stack<int> st;
        vector<int> left(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[i] <= heights[st.top()])
            st.pop();
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        vector<int> right(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[i] <= heights[st.top()])
            st.pop();
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        for(int i=0;i<n;i++){
            area = max(area,heights[i]*(right[i]-left[i]-1));
        }
        return area;
    }
};
