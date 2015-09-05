#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
// #include <string>
using namespace std;

int BiSearch(vector<int>& nums, int start, int end, int target) {
    int mid;
    while (start != end + 1) {
        mid = (start + end) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            start = mid + 1;
        } else if (nums[mid] > target) {
            end = mid - 1;
        }
    }
    return -1;
}

int findMin(vector<int>& nums) {
    int len = nums.size();
    if (nums[len - 1] > nums[0] || len == 1) return 0;

    int start = 0;
    int end = len - 1;
    int mid;

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

int search(vector<int>& nums, int target) {
    if (nums.size() == 0) return -1;
    int start = 0;
    int end = nums.size() - 1;
    if (target < nums[start] && target > nums[end]) return -1;
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

int main(int argc, char const *argv[])
{   
    vector<int> v;
    v.push_back(1);
    // v.push_back(3);
    
    cout << search(v, 0) << endl;
    return 0;
}