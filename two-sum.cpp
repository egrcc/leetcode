class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (map.find(target - nums[i]) != map.end() && map[target - nums[i]] > i) {
                result.push_back(i + 1);
                result.push_back(map[target - nums[i]] + 1);
                break;
            }
        }
        return result;
    }
};