class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = INT_MAX;
        int result;
        sort(nums.begin(), nums.end());
        vector<int>::iterator i;
        for (i = nums.begin(); i < nums.end() - 2; i++) {
            if (i > nums.begin() && *i == *(i-1)) continue;
            vector<int>::iterator j = i + 1;
            vector<int>::iterator k = nums.end() - 1;
            while (j < k) {    
                if (abs(*i + *j + *k - target) < closest) {
                    result = *i + *j + *k;
                    closest = abs(*i + *j + *k - target);
                }

                if (*i + *j + *k < target) {
                    j++;
                } else {
                    k--;
                }
                
            }
        } 
        return result;   
    }
};