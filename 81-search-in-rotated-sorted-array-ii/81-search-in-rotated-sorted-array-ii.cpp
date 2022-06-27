class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        while(i <= j) {
            int mid = i + (j - i) / 2;
            
            if (nums[mid] == target) return true;
            else if (nums[i] == nums[j]) {
                i++;
            } else if (nums[mid] <= nums[j]) {
                if (target < nums[mid] || target > nums[j]) j = mid - 1;
                else i = mid + 1;
            } else if (nums[mid] > nums[j]) {
                if (target > nums[mid] || target < nums[i]) i = mid + 1;
                else j = mid - 1;
            }
        }
        return false;
    }
};