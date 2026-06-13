class KthLargest {
public:
int l;
    priority_queue<int,vector<int>,greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        l = k;
        for(int &num : nums){
            pq.push(num);
            if(pq.size()>k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>l) pq.pop();
        return pq.top();
    }
};
