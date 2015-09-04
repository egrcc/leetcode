class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0; 
        int end = nums.size() - 1;
        while (start <= end) {
            int index = (start + end) / 2;
            if (nums[index] == target) {
                return index;
            } else if (nums[index] < target) {
                start = index + 1;
            } else {
                end = index - 1;
            }
        }
        return start;
    }
};