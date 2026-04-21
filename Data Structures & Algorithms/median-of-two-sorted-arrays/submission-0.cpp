class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()) return findMedianSortedArrays(nums2,nums1);

                int m = nums2.size(); int n = nums1.size();
                        int total = m + n; int half = (total+1) >> 1;
                                int l = 0; int r = n;

                                        while(l<=r){
                                                    int i = (l+r) >> 1;
                                                                int j = half - i;

                                                                            int right1 = (i == 0) ? INT_MIN : nums1[i-1];
                                                                                        int right2 = (j == 0) ? INT_MIN : nums2[j-1];
                                                                                                    int left1 = (i == n) ? INT_MAX : nums1[i];
                                                                                                                int left2 = (j == m) ? INT_MAX : nums2[j];

                                                                                                                            if(right1 > left2)
                                                                                                                                         r = i - 1;
                                                                                                                                                     else if(right2 > left1)
                                                                                                                                                                  l = i + 1;
                                                                                                                                                                              else{
                                                                                                                                                                                              if(total%2 == 1)
                                                                                                                                                                                                               return max(right1,right2);
                                                                                                                                                                                                                               else 
                                                                                                                                                                                                                                               return (max(right1,right2)+min(left1,left2))/2.0 ;
                                                                                                                                                                                                                                                           }
                                                                                                                                                                                                                                                                   }
      return 0.0;
    }
};
