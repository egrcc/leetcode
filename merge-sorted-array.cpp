class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int start = 0;
        bool find;
        int count = 0;
        for (int i = 0; i < n; i++) {
            find = false;
            for (int j = start; j < m + count; j++) {
                if (nums1[j] > nums2[i]) {
                    nums1.insert(nums1.begin() + j, nums2[i]);
                    start = j + 1;
                    count++;
                    find = true;
                    break;
                }
            }
            if (find == false) {
                nums1.insert(nums1.begin() + m + count, nums2.begin() + i, nums2.end());
                break;
            }
        }
        nums1.erase(nums1.begin() + m + n, nums1.end());

    }
};