class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            nums1.swap(nums2);
        int x = nums1.size(), y = nums2.size();
        int start = 0, end = x;
        
        while(start <= end)
        {
            int partX = (start + end) / 2, partY = ((x + y + 1) / 2) - partX;
            
            int maxLeftX = (partX == 0) ? INT_MIN : nums1[partX - 1];
            int minRightX = (partX == x) ? INT_MAX : nums1[partX];
            
            int maxLeftY = (partY == 0) ? INT_MIN : nums2[partY - 1];
            int minRightY = (partY == y) ? INT_MAX : nums2[partY];
            if(maxLeftX <= minRightY && maxLeftY <= minRightX)
            {
                if((x + y) % 2 == 0)
                {
                    return double((max(maxLeftX, maxLeftY) + min(minRightY, minRightX))) / 2;
                }else{
                    return double(max(maxLeftX, maxLeftY));
                }
            }else if(maxLeftX > minRightY){
                end = partX - 1;
            }else{
                start = partX + 1;
            }
        }
        return 0;
    }
};