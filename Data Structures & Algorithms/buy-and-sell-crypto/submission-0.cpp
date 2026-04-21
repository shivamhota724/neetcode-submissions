class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n = INT_MAX;     // min price
       int m = 0;           // max profit
       for(int i=0;i<prices.size();i++){
        n = min(n,prices[i]);
        m = max(m,prices[i]-n);
       }
       return m;
    }
};
