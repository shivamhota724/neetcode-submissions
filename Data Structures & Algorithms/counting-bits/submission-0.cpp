class Solution {
public:
    vector<int> countBits(int n) {
         vector<int>output(n+1);
        for(int i=0;i<n+1;i++){
            int count = 0;
            int x = i;
            while(x){
            count += (x & 1);
            x >>= 1;
        }
        output[i] = count;
        }
        return output;
    }
};
