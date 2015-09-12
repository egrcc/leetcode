class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) return result;

        sort(nums.begin(), nums.end());
        vector<int>::iterator i;
        for (i = nums.begin(); i < nums.end() - 2; i++) {
            if (i > nums.begin() && *i == *(i-1)) continue;
            vector<int>::iterator j = i + 1;
            vector<int>::iterator k = nums.end() - 1;
            while (j < k) {
                if (*i + *j + *k == 0) {
                    result.push_back({*i, *j, *k});
                    j++;
                    k--;
                    while (*j == *(j - 1) && *k == *(k + 1) && j < k) {
                        j++;
                        k--;
                    }
                } else if (*i + *j + *k < 0) {
                    j++;
                    while (*j == *(j - 1) && j < k) j++;
                } else {
                    k--;
                    while (*k == *(k + 1) && j < k) k--;
                }
            }
        } 
        return result;      
    }
};