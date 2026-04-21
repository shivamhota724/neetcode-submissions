class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxx = 0;
        for(int i=0;i<heights.size();i++){
            for(int j=1;j<heights.size();j++){
                int h = min(heights[i],heights[j]);
                int water = h*(j-i);
                if(water > maxx){
                    maxx = water;
                }
            }
        }
        return maxx;
    }
};
