class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        for(int i=0;i<n;i++){
            int h = heights[i];
            int right = i+1;
            while(right < n && heights[right] >= h)
            right++;

            int left = i-1;
            while(left >= 0 && heights[left] >= h)
            left--;

            maxArea = max(maxArea,(right-left-1)*h);
        }
        return maxArea;
    }
};
