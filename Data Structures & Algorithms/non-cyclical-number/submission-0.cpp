class Solution {
public:
    bool isHappy(int n) {
        if(n == 1) return true;
        
        vector<int> freq(244,0);
        
        while(true){
            int sum = 0;
            while(n){
                int i = n%10;
                n /= 10;
                sum += i*i;
            }
            if(sum == 1) return true;
            if(freq[sum] > 0) return false;
            freq[sum]++;
            n = sum;
        }
        return false;
    }
};
