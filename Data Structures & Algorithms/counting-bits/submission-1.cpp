class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>output(n+1);
        for(int i=0;i<=n;i++){
            output[i] = output[i>>1]+(i & 1);
        }
        return output;
    }
};
