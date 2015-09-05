class Solution {
public:

    bool BiSearch(vector<int>& nums, int start, int end, int target) {
        int mid;
        while (start != end + 1) {
            mid = (start + end) / 2;
            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else if (nums[mid] > target) {
                end = mid - 1;
            }
        }
        return false;
    }

    int findMin(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return 0;
        int start = 0;
        int end = len - 1;
        int mid;

        while (nums[start] == nums[end] && start < end) {
            start++;
        }

        if (nums[start] <= nums[end]) return start;    

        while (start != end - 1) {
            mid = (start + end) / 2;
            if (nums[mid] >= nums[start]) {
                start = mid; 
            } else {
                end = mid;
            }           
        }
        return end;
    }

    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0) return false;
        int start = 0;
        int end = nums.size() - 1;
        if (target < nums[start] && target > nums[end]) return false;
        int min = findMin(nums);
        if (target >= nums[start]) {
            if (min == start) {
                return BiSearch(nums, start, end, target);
            } else {
                return BiSearch(nums, start, min - 1, target);
            } 
        }
        if (target <= nums[end]) {
            return BiSearch(nums, min, end, target);
        }         
    }
};