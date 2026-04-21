class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int lMax = 0;
        int rMax = 0;
        int water = 0;
        while(l<r){
            if(height[l] <= height[r]){
                 if(height[l]>lMax)
                    lMax = height[l];
                else
                water += lMax - height[l];

                l++;
            }
            if(height[l] > height[r]){
                if(height[r]>rMax)
                    rMax = height[r];
                else
                water += rMax - height[r];

                r--;
            }
        }
        return water;
    }
};
