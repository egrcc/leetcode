class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int v = nums[0];
        vector<int>::iterator it;
        for (it = nums.begin(); it != nums.end(); it++) {
            if (it == nums.begin()) continue;
            if (*it == v) {
                nums.erase(it);
                it--;
            } else {
                v = *it;
            }
        }
        return nums.size();
        
    }
};