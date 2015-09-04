class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int target_start = -1;
        int target_end = -1;
        while (start <= end) {
            int index = (start + end) / 2;
            if (nums[index] == target) {
                target_start = index;
                target_end = index;
                int i = index - 1, j = index + 1;
                while ((i >= 0) && (nums[i] == target)) {
                    target_start--;
                    i--;
                }
                while ((j <= nums.size() - 1) && (nums[j] == target)) {
                    target_end++;
                    j++;
                }
                break;
            } else if (nums[index] < target) {
                start = index + 1;
            } else {
                end = index - 1;
            }
        }
        vector<int> v;
        v.push_back(target_start);
        v.push_back(target_end);
        return v;
    }
};