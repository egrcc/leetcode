class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return nums[0];
        int start = 0;
        int end = len - 1;
        int mid;

        while (nums[start] == nums[end] && start < end) {
            start++;
        }

        if (nums[start] <= nums[end]) return nums[start];    

        while (start != end - 1) {
            mid = (start + end) / 2;
            if (nums[mid] >= nums[start]) {
                start = mid; 
            } else {
                end = mid;
            }           
        }
        return nums[end];
    }
};