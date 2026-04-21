class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0;
        int r = m*n - 1;
        while(l<=r){
            int mid = (l+r)/2; // mid index in imaginary 1D array;
            int val = matrix[mid/n][mid%n]; // convert the index into matrix index to get value;
            if(val == target) return true;
            else if(val < target) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
};
