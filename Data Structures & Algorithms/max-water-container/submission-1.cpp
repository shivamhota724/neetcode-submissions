class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size()-1;
        int maxx = 0;
        while(l,r){
            int h = min(heights[l],heights[r]);
                int water = h*(r-l);
                    maxx = max(water,maxx);
                    if(heights[l]<heights[r])
                    l++;
                    else
                    r--;
        }
        return maxx;
    }
};
